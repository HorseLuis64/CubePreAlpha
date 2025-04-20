#include<math/transform.h>

namespace tf
{
    Transform::Transform()
    {
        
        model = glm::mat4(1.0f);
        
    }

    float Transform::aspect = 0.0f;
    float Transform::zNear = 0.0f;
    float Transform::zFar = 0.0f; 
    float Transform::fov = 0.0f; 
    bool Transform::maximized = false;
    glm::mat4 Transform::projection = glm::mat4(1.0f);
    glm::mat4 Transform::view = glm::mat4(1.0f);
    int Transform::projLoc = 0;
    int Transform::viewLoc = 0;

    void Transform::setAspectRatio(float x, float y)
    {
        Transform::aspect = x/y;
        Transform::setProjection(Transform::fov, aspect ,Transform::zNear, Transform::zFar, Transform::view);
    }

    void Transform::setProjection(float fov, float aspect, float zNear, float zFar, glm::mat4 &view1)
    {
        Transform::aspect = aspect;
        Transform::zNear = zNear;
        Transform::zFar = zFar;
        Transform::fov = fov;
        Transform::projection = glm::mat4(1.0f);
        Transform::projection = glm::perspective(fov, Transform::aspect, Transform::zNear, Transform::zFar);
        view = view1;
        uf::setMat4(projLoc, projection);
        uf::setMat4(viewLoc, view);
    }

    void Transform::setULocs(int projLoc, int viewLoc, int modelLoc)
    {
        this->projLoc = projLoc;
        this->viewLoc = viewLoc;
        this->modelLoc = modelLoc;
        setModel();
    }

    Transform::~Transform(){}

    void Transform::setModel()
    {
        uf::setMat4(modelLoc, model);
    }

    void Transform::transform(glm::vec3 trans, glm::vec3 scale, float angle, glm::vec3 axis)
    {
        this->model = glm::translate(this->model, trans);
        this->model = glm::scale(this->model, scale);
        this->model = glm::rotate(this->model, glm::radians(angle), axis); 
        setModel();
    }
    void Transform::transform(glm::mat4 trans)
    {
        model = trans;
        setModel();
    }  

    void Transform::translate(glm::vec3 trans)
    {
        model = glm::translate(model, trans);
        setModel();
    }
    void Transform::rotate(float angle, glm::vec3 axis)
    {
        model = glm::rotate(model, glm::radians(angle), axis);
        setModel();
    }
    void Transform::setView(glm::mat4 camView)
    {
        view = camView;
    }

}