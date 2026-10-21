# OpenGL notes

[Заметки](https://k-re.ru/opengl/) по OpenGL для сайта k-re.ru

**Важное замечание**: заметки находятся в процессе обновления. Подробную информацию можно получить в шапке сайта.

## Зависимости

Исходники внешних библиотек подключаются через Git-сабмодули:

| Библиотека | Назначение |
| --- | --- |
| [glfw](https://github.com/glfw/glfw) | Окна, контекст OpenGL и ввод |
| [glad 2](https://github.com/Dav1dde/glad) | Загрузчик функций OpenGL |
| [GLM](https://github.com/g-truc/glm) | Векторы, матрицы и математические операции |
| [TinyGLTF](https://github.com/syoyo/tinygltf) | Загрузка моделей glTF 2.0 |
| [TinyObjLoader](https://github.com/tinyobjloader/tinyobjloader) | Загрузка моделей OBJ |

Клонирование репозитория с модулями:

```bash
git clone --recurse-submodules https://github.com/RE-Kovalev/OpenGL_notes.git
cd OpenGL_notes
```

Если репозиторий уже склонирован и необходимо инициализировать модули:
```bash
git submodule update --init --recursive
```

## Требования

- CMake;

- компилятор C++ с поддержкой C++17 (рекомендуется GCC или MinGW-w64 GCC);

- Python 3 с модулем `jinja2` для генерации GLAD 2;

- для Linux - пакеты разработки X11 и/или Wayland, необходимые GLFW.

## Сборка

Команды сборки необходимо вызывать из корневой директории репозитория:

```bash
cmake -S . -B build
cmake --build build --parallel
```

Различные конфигурации:

```bash
# Конфигурация с отладочной информацией для GDB
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# Конфигурация с оптимизациями
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

cmake --build build --parallel
```


**Важное замечание:** При сборке заголовочные файлы не копируются в директорию `build`. Пути к ним распространяются через CMake-цели (`target_link_libraries`, `target_include_directories`).

### Сборка отдельного примера

```bash
cmake --build build --target 01 --parallel
```

### Очистка и пересборка

```bash
# Удалить результаты компиляции, сохранив конфигурацию
cmake --build build --target clean

# Очистить и пересобрать
cmake --build build --clean-first --parallel

# Полностью удалить директорию сборки
# Использование cmake позволяет избежать взаимодействия с Windows rm /S /Q
cmake -E rm -rf build
```

После полной очистки вновь выполните команды конфигурации и сборки из раздела выше.

## Visual Studio Code

Рекомендуемые расширения:

- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)


## Запуск

Исполняемые файлы обычно находятся в директории `build/bin/`, которая задается `CMakeLists.txt` корневого каталога переменной `CMAKE_RUNTIME_OUTPUT_DIRECTORY`.

При использовании динамических библиотек они должны быть доступны загрузчику во время запуска. CMake может настроить пути поиска для приложений в каталоге сборки.
