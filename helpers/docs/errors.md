# ErrorReporter Documentation

## reportError

**Description:**  
Выводит сообщение об ошибке на стандартный поток ошибок.

**Parameters:**

- `const std::string &message`: Сообщение, которое нужно вывести в качестве ошибки.

**Returns:**
- `void`: Не возвращает значения.

---

## unknownError

**Description:**  
Выводит стандартное сообщение об ошибке при возникновении неизвестной ошибки.

**Parameters:**
- Нет параметров.

**Returns:**
- `void`: Не возвращает значения.

---

## mallocError

**Description:**  
Выводит сообщение об ошибке при сбое выделения памяти с помощью `malloc`.

**Parameters:**
- Нет параметров.

**Returns:**
- `void`: Не возвращает значения.

---

## fileCreationError

**Description:**  
Выводит сообщение об ошибке при неудачной попытке создания файла.

**Parameters:**

- `const std::string &fileName`: Имя файла, который не удалось создать.

**Returns:**
- `void`: Не возвращает значения.

---

## fileOpenError

**Description:**  
Выводит сообщение об ошибке при неудачной попытке открытия файла.

**Parameters:**

- `const std::string &fileName`: Имя файла, который не удалось открыть.

**Returns:**
- `void`: Не возвращает значения.

---
