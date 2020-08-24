#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>
#include <vendor/glm/glm.hpp>
#include <vendor/glm/gtc/matrix_transform.hpp>
#include <vendor/imgui/imgui.h>
#include <vendor/imgui/imgui_impl_glfw_gl3.h>
#include <vendor/stb_image.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
#include <math.h>

#include <API.h>

void customize_imgui()
{
    ImGuiStyle * style = &ImGui::GetStyle();
 
	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 5.0f;
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 4.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;
    style->WindowBorderSize = 0.0f;
 
	style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.06f, 0.05f, 0.07f, 1.0f); //
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Column] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ColumnHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ColumnActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);


    ImGuiIO& io = ImGui::GetIO();
	io.AddInputCharacter(GLFW_KEY_W);
    io.AddInputCharacter(GLFW_KEY_A);
    io.AddInputCharacter(GLFW_KEY_D);
}

const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;

const glm::vec3 DARK_BLUE(5/255.0f, 31/255.0f, 57/255.0f), \
                PURPLE(74/255.0f, 36/255.0f, 128/255.0f), \
                PINK(197/255.0f, 58/255.0f, 157/255.0f), \
                ORANGE(255/255.0f, 142/255.0f, 128/255.0f);

glm::vec3 camera(0,0,0), enemy_camera(0,0,0);
int jumps=0, score=0;

enum stages {
    START, PLAY, FINISH
};

stages current_stage = START;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W && action == GLFW_PRESS && jumps < 2) { 
        camera.y+=0.6f;
        jumps++;
    } 

    if (key == GLFW_KEY_A)
        camera.x-=0.1f;
    if (key == GLFW_KEY_D)
        camera.x+=0.1f;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main() {
    
    HideConsole();

    DisplayManager displayManager(SCR_WIDTH, SCR_HEIGHT, "Jumping Square");

    GLFWimage icons[1];
    int channels;
    icons[0].pixels = stbi_load("../../assets/images/player.png", &icons[0].width, &icons[0].height, &channels, 0);
    glfwSetWindowIcon(displayManager.getWindow(), 1, icons);
    stbi_image_free(icons[0].pixels);

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(displayManager.getWindow(), true);
    ImGui::StyleColorsDark();
    customize_imgui();

    glfwSetKeyCallback(displayManager.getWindow(), key_callback);
    glfwSetFramebufferSizeCallback(displayManager.getWindow(), framebuffer_size_callback);

    TexturedQuad player(0.0f, 0.0f, 0.2f, 0.2f, "../../assets/images/player.png", camera);   
    TexturedQuad enemy(8.0f, -0.6f, 0.2f, 0.2f, "../../assets/images/enemy.png", camera);  
    Quad ground(-1.0f, -1.0f, 4.0f, 0.2f, camera);

    displayManager.setBackgroundColor(DARK_BLUE.x*255, DARK_BLUE.y*255, DARK_BLUE.z*255);

    float offset = 0.05f, i=0.05f;

    ground.getShader().use();
    ground.getShader().setVec3("aColor", PURPLE.x, PURPLE.y, PURPLE.z); // orange ??

    int frames=0;

    while(!displayManager.windowShouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT); 

        std::string scr_msg= "Score: ";
        scr_msg+=std::to_string(score);

        if(current_stage == PLAY) 
        {
            if(camera.y > -0.6f) camera.y-=0.01f;
            else jumps=0;
            frames++;
            if(frames>60) 
            {
                auto val = Random::get(0.05f, 0.15f);
                enemy_camera.x -= val;
            }

            player.setCamera(camera);
            enemy.setCamera(enemy_camera);

            ground.draw();
            enemy.draw();
            player.draw();

            if(round(enemy_camera.x - camera.x) == -8 && round(enemy_camera.y - camera.y) == 1) {
                current_stage = FINISH;
            }

            if(round(enemy_camera.x) == -12) {
                auto val = Random::get(0.0f, 6.0f);
                enemy_camera.x = val;
                score++;
            }   

            ImGui_ImplGlfwGL3_NewFrame();
            {
                ImGui::Begin("Details");
                ImGui::Text(scr_msg.c_str());
                ImGui::End();
            }
            ImGui::Render();
            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        }
        if(current_stage == START)
        {
            ImGui_ImplGlfwGL3_NewFrame();
            {
                ImGui::Begin("Jumping Square");
                if(ImGui::Button("Start the game!"))
                    current_stage = PLAY;
                ImGui::End();
            }
            ImGui::Render();
            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        }
        if(current_stage == FINISH)
        {
            ImGui_ImplGlfwGL3_NewFrame();
            {
                ImGui::Begin("Jumping Square");
                ImGui::Text("u ded");
                scr_msg = "Final " + scr_msg;
                ImGui::Text(scr_msg.c_str());
                if(ImGui::Button("play again")) {
                    current_stage = PLAY;
                    auto val = Random::get(0.0f, 6.0f);
                    enemy_camera.x = val;
                    score=0;
                }
                if(ImGui::Button("exit"))
                    exit(0);
                ImGui::End();
            }
            ImGui::Render();
            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        }

        displayManager.update();
    }

    return 0;
}
