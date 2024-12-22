#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/utilities.h"

void processCString(const char str[]) {
  int capacity = 1;
  char *dynamicStr = calloc(capacity, sizeof(char));

  if (!dynamicStr) {
    fprintf(stderr, "Ошибка выделения памяти.\n");
    return;
  }

  size_t len = 0;

  for (size_t i = 0; str[i] != '\0'; i++) {
    const char ch = str[i];

    if (len >= capacity - 1) {
      capacity += 1;
      char *temp = realloc(dynamicStr, capacity);
      if (!temp) {
        fprintf(stderr, "Ошибка перераспределения памяти.\n");
        free(dynamicStr);
        return;
      }
      dynamicStr = temp;
    }

    dynamicStr[len++] = (char)ch;
  }
  dynamicStr[len] = '\0';

  size_t writeIndex = 0;
  for (size_t i = 0; i < len; i++) {
    if (dynamicStr[i] == '+' && i + 1 < len && isdigit(dynamicStr[i + 1])) {
      if (i + 2 < len && ispunct(dynamicStr[i + 2])) {
        continue;
      }
    }
    dynamicStr[writeIndex++] = dynamicStr[i];
  }
  dynamicStr[writeIndex] = '\0';

  printf("%s\n", dynamicStr);
  free(dynamicStr);
}
