#define UPD_UNIFORMS


#include <graphics/shader.h>
#include <math/utilMath.h>
#include<graphics/texture.h>
#include<graphics/buffer.h>
#include<mesh/meshes.h>
const char* vertexPath = "/home/horseluis/HorseDev/CubePreAlpha/src/shaders/vertexShader.vs";
//const char* vPath = vertexPath.c_str();

const char* fragmentPath = "/home/horseluis/HorseDev/CubePreAlpha/src/shaders/fragmentShader.fs";
//const char* fPath = fragmentPath.c_str();


float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};


glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f), 
    glm::vec3( 2.0f,  5.0f, -15.0f), 
    glm::vec3(-1.5f, -2.2f, -2.5f),  
    glm::vec3(-3.8f, -2.0f, -12.3f),  
    glm::vec3( 2.4f, -0.4f, -3.5f),  
    glm::vec3(-1.7f,  3.0f, -7.5f),  
    glm::vec3( 1.3f, -2.0f, -2.5f),  
    glm::vec3( 1.5f,  2.0f, -2.5f), 
    glm::vec3( 1.5f,  0.2f, -1.5f), 
    glm::vec3(-1.3f,  1.0f, -1.5f)  
};


unsigned int indices[] = 
{
    0, 1, 3,
    1, 2, 3
};

int main()
{ 

    GLFWwindow* window = glf::glfwConfiguration(800, 800);

    opg::Shader shader(vertexPath, fragmentPath);

    tx::Texture texture;
    texture.texParami(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    texture.texParami(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    texture.texParami(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texture.texParami(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);

    texture.createImage("/home/horseluis/HorseDev/CubePreAlpha/assets/textures/man.jpeg");

    texture.addTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 0, GL_RGB, GL_UNSIGNED_BYTE);
   
    msh::Cube cube;
    msh::Pyramid pyramid;

    bf::Buffer buffers;
    buffers.addVBO(pyramid.vertices, sizeof(cube.vertices), GL_DYNAMIC_DRAW);   
    buffers.addEBO(pyramid.indices, sizeof(cube.indices), GL_DYNAMIC_DRAW);

    buffers.addVAttribP(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
    buffers.addVAttribP(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));

    int projLoc, viewLoc, modelLoc;
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(45.0f, 1.0f, 0.1f,100.0f);
    projLoc = glGetUniformLocation(shader.id, "projection");

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f,0.0f,-5.0f));
    viewLoc = glGetUniformLocation(shader.id, "view");

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(24.0f), glm::vec3(1.0f,0.0f,0.0f));
    modelLoc = glGetUniformLocation(shader.id, "model");


    glUseProgram(shader.id);
    glEnable(GL_DEPTH_TEST);
    opg::setMat4(projLoc, projection);
    opg::setMat4(viewLoc, view);
    opg::setMat4(modelLoc, model);

    while(!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f,0.2f,0.6,1.0f);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f,0.0f,0.0f));
        opg::setMat4(modelLoc, model);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        for(int i = 0; i < 10; i++)
        {
            model = glm::mat4(1.0f);
            if(i == 0) continue;

            model = glm::translate(model, cubePositions[i]);
            model = glm::rotate(model, glm::radians(20.0f * i), glm::vec3(1.0f,1.0f,1.0f));
            opg::setMat4(modelLoc, model);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }
        view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f,0.0f,-5.0f));
        view = glm::rotate(view, (float)glfwGetTime() * glm::radians(90.0f), glm::vec3(1.0f,0.0f,0.0f));
        opg::setMat4(viewLoc, view);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }   


   glfwTerminate();
}





