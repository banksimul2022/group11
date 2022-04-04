#ifndef RFID125_GLOBAL_H
#define RFID125_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RFID125_LIBRARY)
#  define RFID125_EXPORT Q_DECL_EXPORT
#else
#  define RFID125_EXPORT Q_DECL_IMPORT
#endif

#endif // RFID125_GLOBAL_H
