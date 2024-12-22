#ifndef UTILITIES_H
#define UTILITIES_H

#ifdef __cplusplus
extern "C" {
#endif

void processCharArray(const char str[], size_t len);
void processCString(const char str[]);
void processFile(const char *inputFileName, const char *outputFileName);

#ifdef __cplusplus
}
#endif

#endif
