@ECHO OFF
cls
REM prompt $T $B $P$G 
REM title Game Engine Dev

g++ -c src/quads/Quads.cpp -o bin/lib/Quads.o -Iinclude -Lbin/lib -lmingw32 -lglfw3 -lopengl32 -lgdi32 -luser32
g++ -c src/quads/TexturedQuad.cpp -o bin/lib/TexturedQuad.o -Iinclude -Lbin/lib -lmingw32 -lglfw3 -lopengl32 -lgdi32 -luser32
g++ -c src/renderEngine/DisplayManager.cpp -o bin/lib/DisplayManager.o -Iinclude -Lbin/lib -lmingw32 -lglfw3 -lopengl32 -lgdi32 -luser32
g++ -c src/renderEngine/Renderer.cpp -o bin/lib/Renderer.o -Iinclude -Lbin/lib -lmingw32 -lglfw3 -lopengl32 -lgdi32 -luser32
g++ src/sandbox/sandbox.cpp bin/lib/imgui.o bin/lib/imgui_draw.o bin/lib/imgui_impl_glfw_gl3.o bin/lib/Quads.o bin/lib/TexturedQuad.o bin/lib/Renderer.o bin/lib/DisplayManager.o bin/lib/glad.o -o bin/debug/sandbox.exe -Iinclude -Lbin/lib -lmingw32 -lglfw3 -lopengl32 -lgdi32 -luser32

cd bin
cd debug
sandbox
cd..
cd..