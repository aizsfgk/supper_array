dnl $Id$
dnl config.m4 for extension super_array

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(super_array, for super_array support,
dnl Make sure that the comment is aligned:
dnl [  --with-super_array             Include super_array support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(super_array, whether to enable super_array support,
dnl Make sure that the comment is aligned:
[  --enable-super_array           Enable super_array support])

if test "$PHP_SUPER_ARRAY" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-super_array -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/super_array.h"  # you most likely want to change this
  dnl if test -r $PHP_SUPER_ARRAY/$SEARCH_FOR; then # path given as parameter
  dnl   SUPER_ARRAY_DIR=$PHP_SUPER_ARRAY
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for super_array files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SUPER_ARRAY_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SUPER_ARRAY_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the super_array distribution])
  dnl fi

  dnl # --with-super_array -> add include path
  dnl PHP_ADD_INCLUDE($SUPER_ARRAY_DIR/include)

  dnl # --with-super_array -> check for lib and symbol presence
  dnl LIBNAME=super_array # you may want to change this
  dnl LIBSYMBOL=super_array # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SUPER_ARRAY_DIR/$PHP_LIBDIR, SUPER_ARRAY_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SUPER_ARRAYLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong super_array lib version or lib not found])
  dnl ],[
  dnl   -L$SUPER_ARRAY_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SUPER_ARRAY_SHARED_LIBADD)

  PHP_NEW_EXTENSION(super_array, super_array.c, $ext_shared)
fi
