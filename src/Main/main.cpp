#define UPD_UNIFORMS


#include <graphics/shader.h>
#include <math/utilMath.h>
#include<graphics/texture.h>
#include<graphics/buffer.h>
#include<mesh/meshes.h>
#include<graphics/camera.h>
#include<math/transform.h>
const char* vertexPath = "/home/horseluis/HorseDev/CubePreAlpha/src/shaders/vertexShader.vs";
//const char* vPath = vertexPath.c_str();

const char* fragmentPath = "/home/horseluis/HorseDev/CubePreAlpha/src/shaders/fragmentShader.fs";
//const char* fPath = fragmentPath.c_str();


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

int main()
{ 

    float windowHeight, windowWidth;
    windowHeight = 800;
    windowWidth = 800;
    GLFWwindow* window = glf::glfwConfiguration(windowWidth, windowHeight);

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
    buffers.addVBO(cube.vertices, sizeof(cube.vertices), GL_DYNAMIC_DRAW);   
    buffers.addEBO(cube.indices, sizeof(cube.indices), GL_DYNAMIC_DRAW);

    buffers.addVAttribP(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
    buffers.addVAttribP(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(3 * sizeof(float)));

    int projLoc, viewLoc, modelLoc;

    cm::Camera camera(glm::vec3(0.0f,0.0f,3.0f));
    camera.setLookAt(camera.camPos, camera.target, glm::vec3(0.0f,1.0f,0.0f));
    viewLoc = shader.getLoc(shader.id, "view");
    
    tf::Transform::setProjection(45.0f,windowWidth / windowHeight, 0.1f,100.0f, camera.view);
    tf::Transform transform;

    
    projLoc = shader.getLoc(shader.id, "projection");

    
    
    transform.rotate(24.0f,glm::vec3(1.0f,0.0f,0.0f));
    
    
    modelLoc = shader.getLoc(shader.id, "model");


    glUseProgram(shader.id);
    glEnable(GL_DEPTH_TEST);
    uf::setMat4(projLoc, tf::Transform::projection);
    uf::setMat4(viewLoc, camera.view);
    uf::setMat4(modelLoc, transform.model);
    glm::vec3 newPos(0.0f,0.0f,0.0f);
    while(!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f,0.2f,0.6,1.0f);

        transform.model = glm::mat4(1.0f);
        transform.translate(newPos);
        uf::setMat4(modelLoc, transform.model);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        for(int i = 0; i < 10; i++)
        {
            transform.model = glm::mat4(1.0f);
            if(i == 0) continue;

            transform.transform(cubePositions[i], glm::vec3(0.5f,0.5f,0.5f) * cubePositions[i], 20.0f * i, glm::vec3(1.0f,1.0f,1.0f));
            
            uf::setMat4(modelLoc, transform.model);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }
        //camera.view = glm::mat4(1.0f);
        camera.setLookAt(glm::vec3((float)sin(glfwGetTime()) * 10.0f,0.0f,(float)cos(glfwGetTime()) * 10.0f), glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f));
        
        
        uf::setMat4(viewLoc, camera.view);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }   


   glfwTerminate();
}





