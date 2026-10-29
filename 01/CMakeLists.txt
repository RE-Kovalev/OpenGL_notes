# Имя проекта из названия директории
get_filename_component(TARGET_NAME "${CMAKE_CURRENT_SOURCE_DIR}" NAME)

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
add_executable(${TARGET_NAME}
    ${SOURCES}
    ${HEADERS}
)

# Путь к заголовочным файлам
target_include_directories(${TARGET_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Библиотеки
target_link_libraries(${TARGET_NAME} PRIVATE
    glad
    glfw
)
