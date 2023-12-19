#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Macros
const unsigned int SCREEN_WIDTH = 400;
const unsigned int SCREEN_HEIGHT = 300;

void processInput(GLFWwindow* window, int keyState);

int main(int argc, char* argv[])
{
  // Instantiate GLFW
  if (!glfwInit())
  {
    std::cout << "LOG::Failed to initialize GLFW\n";
    return 1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Make window
  GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGLWindow", nullptr, nullptr);
  if (window == nullptr)
  {
    std::cout << "LOG::Failed to create window\n";
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);
  glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

  if (glewInit() != GLEW_OK)
  {
    std::cout << "LOG::Failed to initialize GLEW\n";
    return 1;
  }

  // Render loop
  while(!glfwWindowShouldClose(window))
  {
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    processInput(window, GLFW_KEY_ESCAPE);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }


  glfwTerminate();
  return 0;
}

void processInput(GLFWwindow* window, int keyState)
{
  if (glfwGetKey(window, keyState) == GLFW_PRESS)
  {
    std::cout << "LOG::Window closed due to input\n";
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}

