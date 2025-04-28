#pragma once

#define UPD_UNIFORMS
#include<graphics/uniforms.h>
namespace tf
{
    class Transform
    {
        
        

        private:
            static int projLoc;
            static int viewLoc;
            
        private:
            int modelLoc;

        public:

            static float aspect;
            static float zNear;
            static float zFar;
            static float fov;
            static bool maximized;
            static glm::mat4 projection;
            static glm::mat4 view;

            static void setProjection(float fov, float aspect, float zNear, float zFar, glm::mat4 &view1);  
            static void setAspectRatio(float x, float y);          
            
        public:
    
            glm::mat4 model;

            Transform ();
            ~Transform();

            void setModel();
            void setULocs(int projLoc, int viewLoc, int modelLoc);

            void transform(glm::mat4 trans);
            void transform(glm::vec3 trans, glm::vec3 scale, float angle, glm::vec3 axis);
            void translate(glm::vec3 trans);
            void scale(glm::vec3 scale);
            void rotate(float angle, glm::vec3 axis);

            static void setView(glm::mat4 camView);
    };

}

