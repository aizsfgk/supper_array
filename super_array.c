/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_super_array.h"
#include <stdio.h>



/* If you declare any globals in php_super_array.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(super_array)
*/

/* True global resources - no need for thread safety here */
static int le_super_array;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("super_array.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_super_array_globals, super_array_globals)
    STD_PHP_INI_ENTRY("super_array.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_super_array_globals, super_array_globals)
PHP_INI_END()
*/
/* }}} */


/* {{{ proto array array_unique_recursive(array )
   $arr, int $recur_num) */
PHP_FUNCTION(array_unique_recursive)
{
	int argc = ZEND_NUM_ARGS();
	zval *arr;
	Bucket *p, *tmp;
	

	long recur_num = 1;

	if (zend_parse_parameters(argc TSRMLS_CC, "a|l", &arr, &recur_num) == FAILURE) {
		return;
	}

	/*
	   打印函数
	 */
	php_printf("The one param array is porter : %ld\n", (long) Z_ARRVAL_P(arr));

	
	p = Z_ARRVAL_P(arr)->pListHead;
	while (p != NULL) {
		if (p) {
			php_printf("p : %ld \n", (long) p->pData);
		}
		tmp = p;
		while (tmp->pNext) {
			php_printf("tmp->pNext : %ld\n", (long) tmp->pNext->pData);
			tmp = tmp->pNext;
		}
		p = p->pListNext;
	}
	
	php_printf("The two param recur_num is : %ld\n", recur_num);

}
/* }}} */


/* {{{ php_super_array_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_super_array_init_globals(zend_super_array_globals *super_array_globals)
{
	super_array_globals->global_value = 0;
	super_array_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(super_array)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(super_array)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(super_array)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(super_array)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(super_array)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "super_array support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ super_array_functions[]
 *
 * Every user visible function must have an entry in super_array_functions[].
 */
const zend_function_entry super_array_functions[] = {
	PHP_FE(array_unique_recursive,	NULL)
	PHP_FE_END	/* Must be the last line in super_array_functions[] */
};
/* }}} */

/* {{{ super_array_module_entry
 */
zend_module_entry super_array_module_entry = {
	STANDARD_MODULE_HEADER,
	SUPER_ARRAY_NAME,            // 扩展名称
	super_array_functions,       // 扩展的注册函数
	PHP_MINIT(super_array),      
	PHP_MSHUTDOWN(super_array),
	PHP_RINIT(super_array),		 /* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(super_array),	 /* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(super_array),
	SUPER_ARRAY_VERSION,         // 模块版本
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SUPER_ARRAY
ZEND_GET_MODULE(super_array)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
