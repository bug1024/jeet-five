/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: bug1024.com@gmail.com                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_five.h"
#include "../../Zend/zend_types.h"

/* If you declare any globals in php_five.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(five)
*/

/* True global resources - no need for thread safety here */
static int le_five;

PHP_FUNCTION(confirm_five_compiled)
{
    char *arg = NULL;
    size_t arg_len, len;
    zend_string *strg;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
        return;
    }

    strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "five", arg);

    RETURN_STR(strg);
}


// five function end

PHP_FUNCTION(five)
{
    zend_long five;
    five = 5;
    RETURN_LONG(five);
}

PHP_FUNCTION(five_english)
{
    zend_string *str;
    str = strpprintf(0, "five");
    RETURN_STR(str);
}

PHP_FUNCTION(five_chinese)
{
    zend_string *str;
    str = strpprintf(0, "五");
    RETURN_STR(str);
}

PHP_FUNCTION(five_chinese_pinyin)
{
    zend_string *str;
    str = strpprintf(0, "wǔ");
    RETURN_STR(str);
}

PHP_FUNCTION(five_chinese_financial)
{
    zend_string *str;
    str = strpprintf(0, "伍");
    RETURN_STR(str);
}

PHP_FUNCTION(five_japanese)
{
    zend_string *str;
    str = strpprintf(0, "五");
    RETURN_STR(str);
}

PHP_FUNCTION(five_korean)
{
    zend_string *str;
    str = strpprintf(0, "오");
    RETURN_STR(str);
}

PHP_FUNCTION(five_binary)
{
    zend_long five;
    five = 101;
    RETURN_LONG(five);
}

PHP_FUNCTION(is_five)
{
    long number;

    /* accepting arguments */
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &number) != SUCCESS) {
        return;
    }
    zend_bool is_five;
    is_five = number == 5;
    RETURN_BOOL(is_five);
}

// five function end


PHP_MINIT_FUNCTION(five)
{
    zend_class_entry temp_php_five;
    INIT_CLASS_ENTRY(temp_php_five, "Five", five_methods);

    php_five = zend_register_internal_class(&temp_ce TSRMLS_CC);
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(five)
{
    return SUCCESS;
}

PHP_RINIT_FUNCTION(five)
{
#if defined(COMPILE_DL_FIVE) && defined(ZTS)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(five)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(five)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "five support", "enabled");
    php_info_print_table_end();
}

const zend_function_entry five_functions[] = {
    PHP_FE(five, NULL)
    PHP_FE(five_english, NULL)
    PHP_FE(five_chinese, NULL)
    PHP_FE(five_chinese_pinyin, NULL)
    PHP_FE(five_chinese_financial, NULL)
    PHP_FE(five_japanese, NULL)
    PHP_FE(five_korean, NULL)
    PHP_FE(five_binary, NULL)
    PHP_FE(is_five, NULL)
    PHP_FE(confirm_five_compiled, NULL)

    PHP_FE_END
};

const zend_function_entry five_methods[] = {
    PHP_ME(Five, english, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Five, chinese, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Five, chinese_pinyin, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Five, chinese_financial, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Five, chinese_japanese, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Five, chinese_korean, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Five, binary, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Five, is_five, NULL, ZEND_ACC_PUBLIC)

    PHP_FE_END
};

zend_module_entry five_module_entry = {
    STANDARD_MODULE_HEADER,
    "five",
    five_functions,
    PHP_MINIT(five),
    PHP_MSHUTDOWN(five),
    PHP_RINIT(five),        /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(five),    /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(five),
    PHP_FIVE_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_FIVE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(five)
#endif

