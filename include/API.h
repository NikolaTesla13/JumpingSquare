#pragma once

#include <shaders/shader.h>
#include <renderEngine/DisplayManager.h>
#include <quads/QuadShader.h>
#include <quads/Quads.h>
#include <renderEngine/Renderer.h>
#include <quads/TexturedQuadShader.h>
#include <quads/TexturedQuad.h>
#include <vendor/random.hpp>

#define NVIDIA_USE 0

#if NVIDIA_USE
extern "C" {
 _declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}
#endif

using Random = effolkronium::random_static;