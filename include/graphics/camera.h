#pragma once

#include<libs/graphics/glad.h>

#include<math/utilMath.h>

namespace cm
{
    class Camera
    {
        private:
       
        public:
            
            glm::vec3 camPos;
            glm::mat4 view;
            glm::vec3 target;
            Camera(glm::vec3 initPosition, bool setAutoTarget = true);

            ~Camera();

            /*ik this is unnecesary
            glm::vec3 gcamPos();
            glm::mat4 gcamLookAt();
            glm::vec3 gtarget();
            */

            void setTarget(glm::vec3 target = glm::vec3(0.0f,0.0f,0.0f));

            void setPosition(glm::vec3 newPosition);

            void setLookAt(glm::vec3 pos, glm::vec3 target , glm::vec3 up);
    };
}

