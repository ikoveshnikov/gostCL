#ifndef LIBGOSTCL_GLOBAL_H
#define LIBGOSTCL_GLOBAL_H

#if defined(_MSC_VER)
#   define DLL_EXPORT __declspec(dllexport)
#   define DLL_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#   define DLL_EXPORT __attribute__((visibility("default")))
#   define DLL_IMPORT
#   if __GNUC__ > 4
#       define DLL_LOCAL __attribute__((visibility("hidden")))
#   else
#       define DLL_LOCAL
#   endif
#endif

#if defined(LIBGOSTCL_LIBRARY)
#  define LIBGOSTCLSHARED_EXPORT DLL_EXPORT
#else
#  define LIBGOSTCLSHARED_EXPORT DLL_IMPORT
#endif

#endif // LIBGOSTCL_GLOBAL_H
