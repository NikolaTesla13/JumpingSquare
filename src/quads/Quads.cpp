#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>
#include <vendor/glm/glm.hpp>
#include <vendor/glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>

#include <renderEngine/DisplayManager.h>
#include <quads/QuadShader.h>
#include <quads/Quads.h>
#include <tools/Debugger.h>

Quad::Quad(float x, float y, float width, float height, glm::vec3 camera)
{

    float vertecies[] = {
        x+width, y+height, 0.0f,
        x+width, y-height, 0.0f,
        x-width, y-height, 0.0f,
        x-width, y+height, 0.0f,
    };
    
    int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glCall(glGenVertexArrays(1, &VAO));
    glCall(glGenBuffers(1, &VBO));
    glCall(glGenBuffers(1, &EBO));

    glCall(glBindVertexArray(VAO));
    glCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
    glCall(glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(int) * 4, vertecies, GL_STATIC_DRAW));

    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO));
    glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(int), indices, GL_STATIC_DRAW));

    glCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0));
    glCall(glEnableVertexAttribArray(0));

    proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
    view = glm::translate(glm::mat4(1.0f), v_Camera);
    model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

    mvp = proj * view * model;

    v_Camera = camera; 
}

// Quad::Quad(const Quad& other)
// {
//     VBO = other.VBO;
//     VAO = other.VAO;
//     EBO = other.EBO;
//     v_Camera = other.v_Camera;
//     proj = other.proj;
//     view = other.view;
//     model = other.model;
//     mvp = other.mvp;
// }

void Quad::draw()
{
    shader.use();
    view = glm::translate(glm::mat4(1.0f), v_Camera);

    mvp = proj * view * model;
    shader.setMat4("u_MVP", mvp);

    glCall(glBindVertexArray(VAO));
    glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

Quad::~Quad()
{
    glCall(glDeleteVertexArrays(1, &VAO));
    glCall(glDeleteBuffers(1, &VBO));
    glCall(glDeleteBuffers(1, &EBO));
}

QuadShader Quad::getShader()
{
    return shader;
}

void Quad::setCamera(glm::vec3 camera)
{
    v_Camera = camera;
}