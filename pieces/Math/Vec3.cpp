#include<pieces/Math/Vec3.h>

Vec3::Vec3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->glmVec = glm::vec3(x, y, z);
}