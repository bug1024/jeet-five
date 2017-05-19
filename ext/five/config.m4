dnl $Id$
dnl config.m4 for extension five

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(five, for five support,
dnl Make sure that the comment is aligned:
dnl [  --with-five             Include five support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(five, whether to enable five support,
dnl Make sure that the comment is aligned:
[  --enable-five           Enable five support])

if test "$PHP_FIVE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-five -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/five.h"  # you most likely want to change this
  dnl if test -r $PHP_FIVE/$SEARCH_FOR; then # path given as parameter
  dnl   FIVE_DIR=$PHP_FIVE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for five files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       FIVE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$FIVE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the five distribution])
  dnl fi

  dnl # --with-five -> add include path
  dnl PHP_ADD_INCLUDE($FIVE_DIR/include)

  dnl # --with-five -> check for lib and symbol presence
  dnl LIBNAME=five # you may want to change this
  dnl LIBSYMBOL=five # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $FIVE_DIR/$PHP_LIBDIR, FIVE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_FIVELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong five lib version or lib not found])
  dnl ],[
  dnl   -L$FIVE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(FIVE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(five, five.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
