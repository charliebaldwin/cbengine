#include <stdio.h>
#include <shlinkle.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void)
{

    ShlinkleFunc("BIG SHLINKY");

    if (!glfwInit())
    {
        printf("GLFW initilization failed\n");
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(600, 400, "cbengine", NULL, NULL);
    if (!window)
    {
        printf("GLFW create window failed\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}