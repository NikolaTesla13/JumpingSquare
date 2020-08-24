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
#include <vector>

#include <quads/QuadShader.h>
#include <quads/Quads.h>
#include <renderEngine/Renderer.h>

Renderer::Renderer(){}

void Renderer::add(Quad quad) 
{
    quads.push_back(quad);
}

void Renderer::render()
{
    for(int i=0;i<quads.size();i++)
        quads[i].draw();
    
}