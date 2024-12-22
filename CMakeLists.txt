cmake_minimum_required(VERSION 3.30)
project(str_lab)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Основные файлы проекта
add_executable(str_lab
	main.cpp

	# Заголовочные файлы
	includes/utilities.h

	# Исходники
	src/file1.cpp
	src/file2.c
	src/file3.cpp

	# Инструменты
	tools/setConsoleUTF8.h

	# Вспомогательные файлы
	helpers/errors.cpp
	helpers/files_helpers.cpp
	helpers/input_helpers.cpp

	helpers/includes/errors.hpp
	helpers/includes/files_helpers.hpp
	helpers/includes/input_helpers.h
)

# Опция для Windows: отключить макросы min/max
if(WIN32 AND NOT DEFINED NOMINMAX)
	target_compile_definitions(str_lab PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN)
endif()
