/*
   +----------------------------------------------------------------------+
   | Copyright (c) The PHP Group                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | https://www.php.net/license/3_01.txt                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Ruin0x11                                                     |
   +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "php.h"
#include "ext/standard/info.h"
#include "php_anitomy.h"
#include "anitomy_arginfo.h"

#include "anitomy/anitomy/anitomy.h"
#include "anitomy/anitomy/element.h"
#include "anitomy/anitomy/options.h"
#include "anitomy/anitomy/string.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif
#ifndef RETURN_THROWS
#define RETURN_THROWS() do { ZEND_ASSERT(EG(exception)); (void) return_value; return; } while (0)
#endif

const char* categoryToString(anitomy::ElementCategory category)
{
  switch (category) {
  case anitomy::kElementAnimeSeason:
    return "anime_season";
  case anitomy::kElementAnimeSeasonPrefix:
    return "anime_season_prefix";
  case anitomy::kElementAnimeTitle:
    return "anime_title";
  case anitomy::kElementAnimeType:
    return "anime_type";
  case anitomy::kElementAnimeYear:
    return "anime_year";
  case anitomy::kElementAudioTerm:
    return "audio_term";
  case anitomy::kElementDeviceCompatibility:
    return "device_compatibility";
  case anitomy::kElementEpisodeNumber:
    return "episode_number";
  case anitomy::kElementEpisodeNumberAlt:
    return "episode_number_alt";
  case anitomy::kElementEpisodePrefix:
    return "episode_prefix";
  case anitomy::kElementEpisodeTitle:
    return "episode_title";
  case anitomy::kElementFileChecksum:
    return "file_checksum";
  case anitomy::kElementFileExtension:
    return "file_extension";
  case anitomy::kElementFileName:
    return "file_name";
  case anitomy::kElementLanguage:
    return "language";
  case anitomy::kElementOther:
    return "other";
  case anitomy::kElementReleaseGroup:
    return "release_group";
  case anitomy::kElementReleaseInformation:
    return "release_information";
  case anitomy::kElementReleaseVersion:
    return "release_version";
  case anitomy::kElementSource:
    return "source";
  case anitomy::kElementSubtitles:
    return "subtitles";
  case anitomy::kElementVideoResolution:
    return "video_resolution";
  case anitomy::kElementVideoTerm:
    return "video_term";
  case anitomy::kElementVolumeNumber:
    return "volume_number";
  case anitomy::kElementVolumePrefix:
    return "volume_prefix";
  case anitomy::kElementUnknown:
  default:
    return "unknown";
  }
}

wchar_t* mb2wstr(const char* inval) {
    size_t size = std::strlen(inval);
    #define OUTSZ (size+1)*sizeof(wchar_t)
    auto buf = (wchar_t*)std::malloc(OUTSZ);
    std::memset(buf, 0, OUTSZ);
    std::setlocale(LC_CTYPE,"");
    size = std::mbstowcs(buf, inval, size);
    if ( size == (size_t)(-1) ) {
        std::free(buf);
        buf = nullptr;
    } else {
        buf = (wchar_t*)std::realloc(buf,OUTSZ);
    }
    return buf;
    #undef OUTSZ
}

char* wstr2mb(const wchar_t* inval) {
    size_t size = std::wcslen(inval);
    #define OUTSZ (size+1)*MB_CUR_MAX
    auto buf = (char*)std::malloc(OUTSZ);
    std::memset(buf, 0, OUTSZ);
    std::setlocale(LC_CTYPE,"");
    size = std::wcstombs(buf, inval, size*sizeof(wchar_t));
    if ( size == (size_t)(-1) ) {
        std::free(buf);
        buf = nullptr;
    } else {
        buf = (char*)std::realloc(buf,size+1);
    }
    return buf;
    #undef OUTSZ
}

const anitomy::string_t pchar2wstring(const char* inval) {
    wchar_t* tmp = mb2wstr(inval);
    anitomy::string_t out{tmp};
    std::free(tmp);
    return out;
}

void parse_options(HashTable* options, anitomy::Options& o) {
    zval *e;

    if ((e = zend_hash_str_find(options, "allowed_delimiters", sizeof("allowed_delimiters")-1)) != NULL
            && (Z_TYPE_P(e) == IS_STRING)) {
        o.allowed_delimiters = pchar2wstring(Z_STRVAL_P(e));
    }
    if ((e = zend_hash_str_find(options, "ignored_strings", sizeof("ignored_strings")-1)) != NULL) {
        if (Z_TYPE_P(e) == IS_ARRAY) {
            zval *data;
            ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(e), data) {
                if(Z_TYPE_P(data) == IS_STRING) {
                    o.ignored_strings.push_back(pchar2wstring(Z_STRVAL_P(data)));
                }
            } ZEND_HASH_FOREACH_END();
        }
    }
    if ((e = zend_hash_str_find(options, "parse_episode_number", sizeof("parse_episode_number")-1)) != NULL) {
        o.parse_episode_number = Z_TYPE_P(e) == IS_TRUE;
    }
    if ((e = zend_hash_str_find(options, "parse_episode_title", sizeof("parse_episode_title")-1)) != NULL) {
        o.parse_episode_title = Z_TYPE_P(e) == IS_TRUE;
    }
    if ((e = zend_hash_str_find(options, "parse_file_extension", sizeof("parse_file_extension")-1)) != NULL) {
        o.parse_file_extension = Z_TYPE_P(e) == IS_TRUE;
    }
    if ((e = zend_hash_str_find(options, "parse_release_group", sizeof("parse_release_group")-1)) != NULL) {
        o.parse_release_group = Z_TYPE_P(e) == IS_TRUE;
    }
}

/* {{{ array anitomy_parse( [ string $var ] ) */
PHP_FUNCTION(anitomy_parse)
{
    char *filename = "";
    size_t filename_len = 0;
    HashTable *options = NULL;
    HashTable *result = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s|h", &filename, &filename_len, &options) == FAILURE) {
        RETURN_THROWS();
    }

    anitomy::string_t wide = pchar2wstring(filename);

    anitomy::Anitomy anitomy;
    anitomy::Options& o = anitomy.options();

    if (options != NULL) {
        parse_options(options, o);
    }

    if (!anitomy.Parse(wide)) {
        zend_throw_error(NULL, "Failed to parse filename");
        RETURN_THROWS();
    }

    ALLOC_HASHTABLE(result);
    zend_hash_init(result, 0, NULL, ZVAL_PTR_DTOR, 0);

    for (const auto& element : anitomy.elements()) {
      const char* key = categoryToString(element.first);
      zend_string *keystr = zend_string_init(key, strlen(key), 0);

      char* mb = wstr2mb(element.second.c_str());
      zval zv;
      ZVAL_STRING(&zv, mb);
      std::free(mb);

      zend_hash_update(result, keystr, &zv);
    }

    RETURN_ARR(result);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(anitomy)
{
#if defined(ZTS) && defined(COMPILE_DL_ANITOMY)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(anitomy)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "anitomy support", "enabled");
    php_info_print_table_end();
}
/* }}} */

/* {{{ anitomy_module_entry */
zend_module_entry anitomy_module_entry = {
    STANDARD_MODULE_HEADER,
    "anitomy",                  /* Extension name */
    ext_functions,                  /* zend_function_entry */
    NULL,                           /* PHP_MINIT - Module initialization */
    NULL,                           /* PHP_MSHUTDOWN - Module shutdown */
    PHP_RINIT(anitomy),             /* PHP_RINIT - Request initialization */
    NULL,                           /* PHP_RSHUTDOWN - Request shutdown */
    PHP_MINFO(anitomy),             /* PHP_MINFO - Module info */
    PHP_ANITOMY_VERSION,        /* Version */
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ANITOMY
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(anitomy)
#endif
