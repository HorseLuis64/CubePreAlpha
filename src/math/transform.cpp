#include<math/transform.h>

namespace tf
{
    Transform::Transform(float fov, float aspect, float zNear, float zFar, glm::mat4 view)
    {
        
        projection = glm::mat4(1.0f);
        projection = glm::perspective(fov, aspect, zNear, zFar);
        this->view = view;
        model = glm::mat4(1.0f);
        
    }

    Transform::~Transform(){}

    void Transform::transform(glm::vec3 trans, glm::vec3 scale, float angle, glm::vec3 axis)
    {
        this->model = glm::translate(this->model, trans);
        this->model = glm::scale(this->model, scale);
        this->model = glm::rotate(this->model, glm::radians(angle), axis); 
    }

    void Transform::transform(glm::mat4 trans)
    {
        model = trans;
    }

    void Transform::translate(glm::vec3 trans)
    {
        model = glm::translate(model, trans);
    }
    void Transform::setView(glm::mat4 camView)
    {
        view = camView;
    }

}