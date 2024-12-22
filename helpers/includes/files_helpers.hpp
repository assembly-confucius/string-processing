#ifndef FILES_HELPERS_H
#define FILES_HELPERS_H

#include <fstream>
#include <string>

bool openInputFile(const std::string &inputFileName, std::ifstream &inputFile);
void createNewFile(const std::string &fileName);
bool openOutputFile(const std::string &outputFileName, std::ofstream &outputFile);
char *allocateLineBuffer(size_t bufferSize);
bool allocateResultBuffer(char **resultBuffer, size_t length);

#endif
