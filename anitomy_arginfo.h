#if PHP_MAJOR_VERSION >= 8
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_anitomy_parse, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 1, "null")
ZEND_END_ARG_INFO()
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_anitomy_parse, 0, 0, 2)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()
#endif


ZEND_FUNCTION(anitomy_parse);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(anitomy_parse, arginfo_anitomy_parse)
	ZEND_FE_END
};
