#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>
#include <vendor/glm/glm.hpp>
#include <vendor/glm/gtc/matrix_transform.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <vendor/stb_image.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>

#include <renderEngine/DisplayManager.h>
#include <quads/TexturedQuadShader.h>
#include <quads/TexturedQuad.h>
#include <tools/Debugger.h>

TexturedQuad::TexturedQuad(float x, float y, float width, float height, std::string texturePath,glm::vec3 camera)
{
    float vertecies[] = {
        x+width, y+height, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
        x+width, y-height, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
        x-width, y-height, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
        x-width, y+height, 0.0f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f
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
    glCall(glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float) * 4, vertecies, GL_STATIC_DRAW));

    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO));
    glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(int), indices, GL_STATIC_DRAW));

    glCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0));
    glCall(glEnableVertexAttribArray(0));

    glCall(glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (3 * sizeof(float))));
    glCall(glEnableVertexAttribArray(1));

    glCall(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6* sizeof(float))));
    glCall(glEnableVertexAttribArray(2));

    glCall(glGenTextures(1, &texture));
    glCall(glBindTexture(GL_TEXTURE_2D, texture));

    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    int t_Width, t_Height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(texturePath.c_str(), &t_Width, &t_Height, &nrChannels, 0);

    if(data) {
        glCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, t_Width, t_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
        glCall(glGenerateMipmap(GL_TEXTURE_2D));
    } else {
        std::cout<<"Failed to load texture\n";
    }

    stbi_image_free(data);

    proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
    view = glm::translate(glm::mat4(1.0f), v_Camera);
    model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

    mvp = proj * view * model;

    v_Camera = camera; 
}

void TexturedQuad::draw()
{
    glBindTexture(GL_TEXTURE_2D, texture);

    shader.use();
    view = glm::translate(glm::mat4(1.0f), v_Camera);

    mvp = proj * view * model;
    shader.setMat4("u_MVP", mvp);

    glCall(glBindVertexArray(VAO));
    glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

TexturedQuad::~TexturedQuad()
{
    glCall(glDeleteVertexArrays(1, &VAO));
    glCall(glDeleteBuffers(1, &VBO));
    glCall(glDeleteBuffers(1, &EBO));
}

TexturedQuadShader TexturedQuad::getShader()
{
    return shader;
}

void TexturedQuad::setCamera(glm::vec3 camera)
{
    v_Camera = camera;
}