#include<math/transform.h>

namespace tf
{
    Transform::Transform()
    {
        
        model = glm::mat4(1.0f);
        
    }

    glm::mat4 Transform::projection = glm::mat4(1.0f);
    glm::mat4 Transform::view = glm::mat4(1.0f);
    int Transform::projLoc = 0;
    int Transform::viewLoc = 0;
    void Transform::setProjection(float fov, float aspect, float zNear, float zFar, glm::mat4 view1)
    {
        projection = glm::mat4(1.0f);
        projection = glm::perspective(fov, aspect, zNear, zFar);
        view = view1;
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    }

    void Transform::setULocs(int projLoc, int viewLoc, int modelLoc)
    {
        this->projLoc = projLoc;
        this->viewLoc = viewLoc;
        this->modelLoc = modelLoc;
        setMat4();
    }
    Transform::~Transform(){}

    void Transform::transform(glm::vec3 trans, glm::vec3 scale, float angle, glm::vec3 axis)
    {
        this->model = glm::translate(this->model, trans);
        this->model = glm::scale(this->model, scale);
        this->model = glm::rotate(this->model, glm::radians(angle), axis); 
        setMat4();
    }

    void Transform::setMat4()
    {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    }

    void Transform::transform(glm::mat4 trans)
    {
        model = trans;
        setMat4();
    }

    void Transform::translate(glm::vec3 trans)
    {
        model = glm::translate(model, trans);
        setMat4();
    }
    void Transform::rotate(float angle, glm::vec3 axis)
    {
        model = glm::rotate(model, glm::radians(angle), axis);
        setMat4();
    }
    void Transform::setView(glm::mat4 camView)
    {
        view = camView;
    }

}