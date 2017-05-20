dnl
dnl $Id$
dnl

PHP_ARG_ENABLE(five, whether to enable five support,
[  --enable-five           Enable five support])

if test "$PHP_FIVE" != "no"; then
  PHP_NEW_EXTENSION(five, five.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
