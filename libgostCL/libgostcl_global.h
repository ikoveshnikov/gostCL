#ifndef LIBGOSTCL_GLOBAL_H
#define LIBGOSTCL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBGOSTCL_LIBRARY)
#  define LIBGOSTCLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBGOSTCLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBGOSTCL_GLOBAL_H
