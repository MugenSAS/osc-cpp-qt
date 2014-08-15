#ifndef OSC_GLOBAL_H
#define OSC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(OSC_LIBRARY)
#  define OSCSHARED_EXPORT Q_DECL_EXPORT
#else
#  define OSCSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // OSC_GLOBAL_H
