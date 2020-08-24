#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>

#include <renderEngine/DisplayManager.h>
#include <tools/Debugger.h>

DisplayManager::DisplayManager(unsigned int width, unsigned int height, std::string title)
{
    scr_width = width;
    scr_height = height;
    win_title = title;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(scr_width, scr_height, title.c_str(), NULL, NULL);

    if(window == NULL) {
        std::cout<<"Failed to create the window\n";
    }

    glfwMakeContextCurrent(window);


    //load opengl pointers
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout<<"Failed to init GLAD\n";
        return;
    }

    glfwSwapInterval(1);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

unsigned int DisplayManager::getWidth() const
{
    return scr_width;
}
unsigned int DisplayManager::getHeight() const
{
    return scr_height;
}
bool DisplayManager::windowShouldClose()
{
    return glfwWindowShouldClose(window);
}
void DisplayManager::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void DisplayManager::setBackgroundColor(unsigned int r, unsigned int g, unsigned int b) const
{
    glCall(glClearColor(r/255.0f, g/255.0f, b/255.0f, 1.0f));
}

DisplayManager::~DisplayManager()
{
    glfwTerminate();
}