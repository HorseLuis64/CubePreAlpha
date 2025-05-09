#include<graphics/camera.h>

namespace cm
{
    Camera::Camera(glm::vec3 initPosition, bool setAutoTarget)
    {
        camPos = initPosition;
        view = glm::mat4(1.0f);
        if(setAutoTarget)
        {
            setTarget();
        }
    }
    Camera::~Camera(){}

    void Camera::setTarget(glm::vec3 target)
    {
        this->target = target;
    }

    void Camera::setPosition(glm::vec3 newPosition)
    {
        camPos = newPosition;
    }

    void Camera::setLookAt(glm::vec3 pos, glm::vec3 target, glm::vec3 up)
    {
        view = glm::lookAt(pos, target, up);
    }
    /*
    glm::vec3 Camera::gcamPos()
    {
        return this->camPos;
    }
    glm::mat4 Camera::gcamLookAt()
    {
        return this->camLookAt;
    }
    glm::vec3 Camera::gtarget()
    {
        return this->target;
    }*/
}