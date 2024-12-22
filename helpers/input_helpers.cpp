#include <iostream>

#include "includes/input_helpers.h"

void getStringFromUser(char str[], const int maxLength) {
  std::cout << "Введите строку:";
  std::cin.getline(str, maxLength);
}