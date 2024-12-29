#include <stdio.h>
#include <string>

#define GL_SILENCE_DEPRECATION
// Without this gl.h gets included instead of gl3.h
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
// For includes related to OpenGL, make sure their are included after glfw3.h
#include <OpenGL/gl3.h>

#include <imgui/imgui.h>
#include <imgui/misc/single_file/imgui_single_file.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

#include "node.h"

int initGLFW();

// callbacks
void errorCallback(int error, const char *description);
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void frameBufferResizeCallback(GLFWwindow *window, int width, int height);
void registerCallbacks(GLFWwindow* window);


int main(void)
{
    
    initGLFW();
    GLFWwindow* window = glfwCreateWindow(1200, 400, "CB-ENGINE", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    registerCallbacks(window);

    // ImGui::CreateContext();
    // ImGuiIO& io = ImGui::GetIO(); (void)io;
    // ImGui_ImplGlfw_InitForOpenGL(window, true);
    // ImGui_ImplOpenGL3_Init("#version 150");


    // Main Loop
    while (!glfwWindowShouldClose(window))
    {

        // Resize the viewport
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClearColor(1.0f, 0.0f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}


int initGLFW() {
    // Set callback for errors
    glfwSetErrorCallback(errorCallback);

    // Initialize the library
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // Without these two hints, nothing above OpenGL version 2.1 is supported
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 1;
}


// Callbacks
void registerCallbacks(GLFWwindow* window) {
    glfwSetKeyCallback(window, keyCallback);
}
void errorCallback(int error, const char *description)
{
    fputs(description, stderr);
}
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    printf("pressed key %s\n", glfwGetKeyName(key, scancode));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
void frameBufferResizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}