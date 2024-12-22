#include <iostream>

#include "includes/errors.hpp"

void ErrorReporter::reportError(const std::string &message) {
  std::cerr << message << std::endl;
}

void ErrorReporter::unknownError() {
  reportError("Произошла неизвестная ошибка");
}

void ErrorReporter::mallocError() {
  reportError("Ошибка выделения памяти");
}

void ErrorReporter::fileCreationError(const std::string &fileName) {
  reportError("Не удалось создать файл: " + fileName);
}

void ErrorReporter::fileOpenError(const std::string &fileName) {
  reportError("Не удалось открыть файл: " + fileName);
}
