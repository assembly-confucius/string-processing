#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <string>

class ErrorReporter {
public:
  static void reportError(const std::string &message);
  static void unknownError();
  static void mallocError();
  static void fileCreationError(const std::string &fileName);
  static void fileOpenError(const std::string &fileName);
};

#endif
