#pragma once

class Quad
{
public:
    QuadShader shader;
    unsigned int VBO, VAO, EBO;
    glm::mat4 proj, view, model, mvp;
    glm::vec3 v_Camera;
public:
    Quad(float x, float y, float width, float height, glm::vec3 camera);
    ~Quad();
    void draw();
    QuadShader getShader();
    void setCamera(glm::vec3 camera);
};