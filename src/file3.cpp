#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

#include "../includes/utilities.h"
#include "../helpers/includes/files_helpers.hpp"
#include "../helpers/includes/errors.hpp"

void processFile(const char *inputFileName, const char *outputFileName) {
  std::ifstream inputFile;
  std::ofstream outputFile;

  if (!openInputFile(inputFileName, inputFile)) {
    ErrorReporter::fileOpenError(inputFileName);
    return;
  }

  if (!openOutputFile(outputFileName, outputFile)) {
    ErrorReporter::fileOpenError(outputFileName);
    inputFile.close();
    return;
  }

  std::string line;
  while (std::getline(inputFile, line)) {
    const size_t len = line.length();
    if (len < 3) return;

    auto capacity = 0;
    auto currentLength = 0;

    auto dynamicStr = static_cast<char *>(malloc(sizeof(char)));

    if (!dynamicStr) {
      ErrorReporter::mallocError();
      inputFile.close();
      outputFile.close();
      return;
    }

    for (size_t i = 0; i < len; i++) {
      currentLength++;
      if (line[i] == '+' && isdigit(line[i + 1]) && ispunct(line[i + 2]) && i + 2 < len) {
        continue;
      }

      if (currentLength <= len) {
        capacity += 1;
        const auto newStr = static_cast<char *>(malloc(capacity * sizeof(char)));

        if (!newStr) {
          ErrorReporter::mallocError();
          free(dynamicStr);
          inputFile.close();
          outputFile.close();
          return;
        }

        memcpy(newStr, dynamicStr, capacity);
        free(dynamicStr);
        dynamicStr = newStr;
      }

      dynamicStr[capacity - 1] = line[i];
    }
    dynamicStr[capacity] = '\0';
    outputFile << dynamicStr << std::endl;
    free(dynamicStr);
  }

  inputFile.close();
  outputFile.close();
}
