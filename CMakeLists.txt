cmake_minimum_required(VERSION 3.16)

project(OpenGL_notes LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Директории результатов
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Зависимости собираются первыми
add_subdirectory(dependencies)

# Автоматическое подключение дочерних проектов
file(GLOB PROJECT_DIRS LIST_DIRECTORIES true
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

foreach(DIR IN LISTS PROJECT_DIRS)
    if(IS_DIRECTORY "${DIR}"
       AND EXISTS "${DIR}/CMakeLists.txt"
       AND NOT "${DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")
        add_subdirectory("${DIR}")
    endif()
endforeach()
