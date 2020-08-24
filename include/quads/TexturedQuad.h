#pragma once

class TexturedQuad
{
public:
    TexturedQuadShader shader;
    unsigned int VBO, VAO, EBO;
    glm::mat4 proj, view, model, mvp;
    glm::vec3 v_Camera;
    unsigned int texture;
public:
    TexturedQuad(float x, float y, float width, float height, std::string texturePath,glm::vec3 camera);
    ~TexturedQuad();
    void draw();
    TexturedQuadShader getShader();
    void setCamera(glm::vec3 camera);
};