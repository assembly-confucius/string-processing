#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "includes/files_helpers.hpp"
#include "includes/errors.hpp"

void createNewFile(const std::string &fileName) {
  std::ofstream createFile(fileName);
  if (!createFile) {
    ErrorReporter::fileCreationError(fileName);
    return;
  }

  std::cout << "Файл пуст. Введите содержимое для записи в файл:";
  std::string input;
  std::cin.ignore();
  std::getline(std::cin, input);

  createFile << input << std::endl;
  createFile.close();
  std::cout << "Содержимое записано в файл." << std::endl;
}

bool openInputFile(const std::string &inputFileName, std::ifstream &inputFile) {
  inputFile.open(inputFileName);
  if (!inputFile.is_open()) {
    std::cout << "Входной файл не существует. Создание нового файла." << std::endl;
    createNewFile(inputFileName);
    inputFile.open(inputFileName);
  }
  return inputFile.is_open();
}

bool openOutputFile(const std::string &outputFileName, std::ofstream &outputFile) {
  outputFile.open(outputFileName);
  if (!outputFile.is_open()) {
    ErrorReporter::fileOpenError(outputFileName);
    return false;
  }
  return true;
}

char *allocateLineBuffer(const size_t bufferSize) {
  const auto lineBuffer = static_cast<char *>(malloc(bufferSize * sizeof(char)));
  if (!lineBuffer) {
    ErrorReporter::mallocError();
  }
  return lineBuffer;
}

bool allocateResultBuffer(char **resultBuffer, const size_t length) {
  *resultBuffer = static_cast<char *>(malloc(length + 1));
  if (!*resultBuffer) {
    ErrorReporter::mallocError();
    return false;
  }
  return true;
}
