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
  | Author: bug1024.com@gmail.com                                        |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_FIVE_H
#define PHP_FIVE_H

extern zend_module_entry five_module_entry;
#define phpext_five_ptr &five_module_entry

#define PHP_FIVE_VERSION "0.1.0"

#ifdef PHP_WIN32
#   define PHP_FIVE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_FIVE_API __attribute__ ((visibility("default")))
#else
#   define PHP_FIVE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

zend_class_entry *php_five;

// code
PHP_METHOD(Five, english);
PHP_METHOD(Five, chinese);
PHP_METHOD(Five, chinese_pinyin);
PHP_METHOD(Five, chinese_financial);
PHP_METHOD(Five, chinese_japanese);
PHP_METHOD(Five, chinese_korean);
PHP_METHOD(Five, binary);
PHP_METHOD(Five, is_five);

#define FIVE_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(five, v)

#if defined(ZTS) && defined(COMPILE_DL_FIVE)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif  /* PHP_FIVE_H */

