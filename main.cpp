#include <iostream>
#include <string>

using namespace std;

#include "helpers/includes/input_helpers.h"
#include "includes/utilities.h"
#include "helpers/includes/errors.hpp"
#include "tools/setConsoleUTF8.h"


int main() {
  setConsoleUTF();

  try {
    while (true) {
      int choice;
      cout << "Выберите метод обработки строки:" << endl;
      cout << "1. Массив символов\n";
      cout << "2. Массив в стиле C\n";
      cout << "3. Строка из файла\n";
      cout << "0. Выход\n";

      cin >> choice;
      cin.ignore();

      if (choice == 0) {
        break;
      }

      if (choice == 1) {
        constexpr int MAX_LEN = 100;
        char str[MAX_LEN];

        getStringFromUser(str, MAX_LEN);

        const size_t len = strlen(str);
        if (len > INT_MAX) {
          ErrorReporter::reportError("Строка слишком длинная для обработки.");
          continue;
        }

        processCharArray(str, len);
      } else if (choice == 2) {
        constexpr int MAX_LEN = 100;
        char str[MAX_LEN];

        getStringFromUser(str, MAX_LEN);

        processCString(str);
      } else if (choice == 3) {
        char inputFile[100], outputFile[100];
        cout << "Введите имя входного файла (без пути):";
        cin >> inputFile;

        cout << "Введите имя выходного файла (без пути):";
        cin >> outputFile;

        string inputFilePath = "../files/" + string(inputFile);
        string outputFilePath = "../files/" + string(outputFile);

        processFile(inputFilePath.c_str(), outputFilePath.c_str());
      } else {
        cout << "Неверный выбор" << endl;
      }
    }
  } catch (const exception &e) {
    ErrorReporter::reportError("Произошла ошибка: " + string(e.what()));
  } catch (...) {
    ErrorReporter::unknownError();
  }

  return 0;
}
