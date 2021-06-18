ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_anitomy_parse, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, class, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, array, IS_ARRAY, 1, "null")
ZEND_END_ARG_INFO()


ZEND_FUNCTION(anitomy_parse);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(anitomy_parse, arginfo_anitomy_parse)
	ZEND_FE_END
};
