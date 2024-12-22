#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "../includes/utilities.h"
#include "../helpers/includes/errors.hpp"

void processCharArray(const char str[], const size_t len) {
  if (len < 3) return;

  size_t capacity = 0;        // количество символов под выходящую строку
  size_t currentLength = 0;   // длина изначальной строки необработанной

  auto dynamicStr = static_cast<char *>(malloc(sizeof(char)));

  if (!dynamicStr) {
    ErrorReporter::mallocError();
    return;
  }

  for (size_t i = 0; i < len; i++) {
    currentLength++;
    if (str[i] == '+' && isdigit(str[i + 1]) && ispunct(str[i + 2]) && i + 2 < len) {
      continue;
    }

    if (currentLength <= len) {
      capacity += 1;
      const auto newStr = static_cast<char *>(malloc(capacity * sizeof(char)));
      if (!newStr) {
        ErrorReporter::mallocError();
        free(dynamicStr);
        return;
      }

      memcpy(newStr, dynamicStr, capacity);
      free(dynamicStr);
      dynamicStr = newStr;
    }

    dynamicStr[capacity - 1] = str[i];
  }
  dynamicStr[capacity] = '\0';
  std::cout << dynamicStr << std::endl;
  free(dynamicStr);
}