#ifndef SETCONSOLEUTF8_H
#define SETCONSOLEUTF8_H

#include <windows.h>
#undef byte

inline void setConsoleUTF() {
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
}

#endif