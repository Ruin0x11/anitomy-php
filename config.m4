PHP_ARG_ENABLE([anitomy],
  [whether to enable anitomy support],
  [AS_HELP_STRING([--enable-anitomy],
    [Enable anitomy support])],
  [no])

if test "$PHP_ANITOMY" != "no"; then
  PHP_REQUIRE_CXX()
  PHP_CXX_COMPILE_STDCXX(11, mandatory, PHP_INTL_STDCXX)

  CXXFLAGS="-g3 -O2 -Wall -Wno-write-strings -fno-strict-aliasing"
  PHP_SUBST(CXXFLAGS)

  PHP_ADD_LIBRARY(stdc++, 1, ANITOMY_SHARED_LIBADD)

  ANITOMY_SOURCES="anitomy.cpp anitomy/anitomy/anitomy.cpp anitomy/anitomy/element.cpp anitomy/anitomy/keyword.cpp anitomy/anitomy/parser.cpp anitomy/anitomy/parser_helper.cpp anitomy/anitomy/parser_number.cpp anitomy/anitomy/string.cpp anitomy/anitomy/token.cpp anitomy/anitomy/tokenizer.cpp"
  PHP_NEW_EXTENSION(anitomy, $ANITOMY_SOURCES, $ext_shared)
  PHP_SUBST(ANITOMY_SHARED_LIBADD)
fi
