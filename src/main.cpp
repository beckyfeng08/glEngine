/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#define IMGUI_DEFINE_MATH_OPERATORS
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
glViewport(0, 0, width, height);

}

int main(void)
{
    // const char* glsl_version =  (char*) glGetString(330);
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    // https://stackoverflow.com/questions/62990972/why-is-opengl-giving-me-the-error-error-01-version-330-is-not-support
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        std::cout << "I'm apple machine" << std::endl;
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    //

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(600, 400, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental=GL_TRUE;
    GLenum err = glewInit(); 

    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

    }
    
    {
        float positions[] = {
            100.0f, 100.f, 0.0f, 0.0f,
            200.0f, 100.0f, 1.0f, 0.0f,
            200.0f, 200.0f, 1.0f, 1.0f,
            200.0f, 200.0f, 0.0f, 1.0f

        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        VertexArray va;
        VertexBuffer vb(positions, 4 * 4 * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);
        
        IndexBuffer ib(indices, 6);

        glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100,0,0));
     

        Shader shader("../res/shaders/basic.shader");
        shader.Bind();


        GLCall(Texture texture("../res/textures/4ca36.png"));
        GLCall(texture.Bind());
        GLCall(shader.SetUniform1i("u_Texture", 0)); // we bound our texture to slot 0

        va.Unbind();
        shader.Unbind();
        vb.Unbind();
        ib.Unbind();

        Renderer renderer;

        //initialize imgui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init((char*)glGetString(330));

        //setting up values
        bool show_demo_window = true;
        bool show_another_window = false;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        glm::vec3 translationA(200,200,0);
        glm::vec3 translationB(200,200,0);

        
        glfwSwapInterval(1);
    
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            renderer.Clear();

            {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
            glm::mat4 mvp = proj*view*model; 

            shader.Bind();
            // shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);ß
            shader.SetUniformMat4f("u_MVP", mvp);
            
            renderer.Draw(va, ib, shader);
            }
            {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
            glm::mat4 mvp = proj*view*model; 

            shader.Bind();
            // shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);ß
            shader.SetUniformMat4f("u_MVP", mvp);
            
            renderer.Draw(va, ib, shader);
            }
            

            glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);


            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
            

            // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
            {
                static float f = 0.0f;
                static int counter = 0;


                ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

                ImGui::Text("This is some useful text.");             

                ImGui::SliderFloat3("translation", &translationA.x, 0.0f, 960.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::SliderFloat3("translationB", &translationB.x, 0.0f, 960.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
                ImGui::End();
            }
            // Rendering
                ImGui::Render();
                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());



            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();

        }
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}
