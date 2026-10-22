# Исходные файлы
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Заголовочные файлы
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

# Исполняемый файл
add_executable(01
    ${SOURCES}
    ${HEADERS}
)

# Путь к заголовочным файлам
target_include_directories(01 PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Библиотеки
target_link_libraries(01 PRIVATE
    glad
    glfw
)
