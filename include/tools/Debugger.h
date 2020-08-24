#pragma once

#define ASSERT(x) if(!(x)) exit(-1);
#define glCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError()
{
    while(glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
    while(GLenum error = glGetError())
    {
        std::cout<< "[OpenGL Error] ("<<error<<"): in function "<<function<<", file "<<file<<" at line "<<line<<std::endl;
        return false;
    }
    return true;
}