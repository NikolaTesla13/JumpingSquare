#pragma once

class Renderer
{
private:
    std::vector<Quad> quads;
public:
    Renderer();
    void add(Quad quad);
    void render();
};