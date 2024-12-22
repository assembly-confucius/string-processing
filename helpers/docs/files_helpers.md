# Files Helpers Documentation

## openInputFile

**Description:**  
Открывает входной файл и сообщает, если файл не существует. Если файл не найден, создается новый файл.

**Parameters:**

- `const std::string &inputFileName`: Имя входного файла, который нужно открыть.
- `std::ifstream &inputFile`: Ссылка на объект `ifstream`, который будет использоваться для открытия файла.

**Returns:**

- `bool`: Возвращает `true`, если файл успешно открыт, иначе `false`.

---

## createNewFile

**Description:**  
Создает пустой файл, если его нет, и предлагает ввести данные для записи в файл.

**Parameters:**

- `const std::string &fileName`: Имя файла, который нужно создать.

**Returns:**

- `void`: Не возвращает значения.

---

## openOutputFile

**Description:**  
Открывает выходной файл и проверяет, успешно ли это.

**Parameters:**

- `const std::string &outputFileName`: Имя выходного файла, который нужно открыть.
- `std::ofstream &outputFile`: Ссылка на объект `ofstream`, который будет использоваться для открытия файла.

**Returns:**

- `bool`: Возвращает `true`, если файл успешно открыт, иначе `false`.

---

## allocateLineBuffer

**Description:**  
Выделяет память для буфера строк заданного размера.

**Parameters:**

- `const size_t bufferSize`: Размер буфера, который нужно выделить.

**Returns:**

- `char*`: Указатель на выделенный буфер или `nullptr` в случае ошибки.

---

## allocateResultBuffer

**Description:**  
Выделяет память для результата, размером на один символ больше, чем длина строки.

**Parameters:**

- `char **resultBuffer`: Указатель на указатель, который будет указывать на выделенный буфер.
- `const size_t length`: Длина строки, для которой нужно выделить память.

**Returns:**

- `bool`: Возвращает `true`, если память успешно выделена, иначе `false`.
