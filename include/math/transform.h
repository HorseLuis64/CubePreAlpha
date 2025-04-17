#define SIMPLE_MATX_CALC
#include<math/utilMath.h>

namespace tf
{
    class Transform
    {
        private:
            
        public:

            glm::mat4 view;
            glm::mat4 projection;
            glm::mat4 model;
            Transform(float fov, float aspect, float zNear, float zFar, glm::mat4 view);
            ~Transform();

            void transform(glm::mat4 trans);
            void transform(glm::vec3 trans, glm::vec3 scale, float angle, glm::vec3 axis);
            void translate(glm::vec3 trans);
            void scale(glm::vec3 scale);
            void rotate(float angle, glm::vec3 axis);

            void setView(glm::mat4 camView);
    };

}