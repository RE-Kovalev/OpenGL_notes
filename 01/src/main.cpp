#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_CAPTION "OPENGL notes on k-re.ru"

// Функция-callback для обработки изменения размеров поверхности окна
void window_resize_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "Изменены размеры окна, w:" << width << " h: " << height << "\n";

    glViewport(0, 0, width, height); // Задание области просмотра
}


int main(void)
{
    // Инициализация GLFW3
    if (!glfwInit())
        throw std::runtime_error("Ошибка инициализации GLFW");

    atexit(glfwTerminate); // Закончим работу с библиотекой при завершении программы

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // Мажорная версия спецификаций OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // Минорная версия спецификаций OpenGL
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Контекст OpenGL, который поддерживает только основные функции

    // Создание окна GLFW3 с заданными шириной, высотой и заголовком окна
    GLFWwindow* window = glfwCreateWindow( WINDOW_WIDTH   // Ширина окна
                                         , WINDOW_HEIGHT  // Высота окна
                                         , WINDOW_CAPTION // Заголовок окна
                                         , NULL           // Дескриптор монитора для полноэкранного режима, NULL - для оконного режима
                                         , NULL           // Дескриптор окна для использования общего контекста OpenGL и ресурсов
                                         );
    if (!window)
        throw std::runtime_error("Ошибка создания окна GLFW");

    // Делает контекст OpenGL, связанный с окном, текущим для рендера в этом потоке
    glfwMakeContextCurrent(window);
    // Установка callback-функции для обработки изменения размеров
    glfwSetFramebufferSizeCallback(window, window_resize_callback);

    // Вертикальная синхронизация для ограничения частоты кадров
    glfwSwapInterval(1);

    // Загрузка функций OpenGL с помощью GLAD
    if (!gladLoadGL(glfwGetProcAddress))
        throw std::runtime_error("Ошибка GLAD при инициализации функций OpenGL");

    // Установка цвета очистки буфера цвета
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Пока не произойдет событие запроса закрытия окна
    while(!glfwWindowShouldClose(window))
    {
        // Очистка буфера цвета
        glClear(GL_COLOR_BUFFER_BIT);


        // Тут производится рендер
        // ...

        // Представление содержимого буфера цепочки показа на окно
        glfwSwapBuffers(window);
        // Обработка системных событий
        glfwPollEvents();
    }

    glfwDestroyWindow(window); // Уничтожим окно

    return 0;
}
