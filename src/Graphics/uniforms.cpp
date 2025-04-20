#define UPD_UNIFORMS
#include<graphics/uniforms.h>

namespace uf
{
    void setInt(int &loc,  int &newValue)
	{
		glUniform1i(loc, newValue);
	}
	void setMat4(int loc, glm::mat4 &newValue)
	{
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(newValue));
	}
	void setFloat(int loc, float &newValue)
	{
		glUniform1f(loc, newValue);
	}
	void setVec3(int loc, glm::vec3 &newValue)
	{
		glUniform3f(loc, newValue.x, newValue.y, newValue.z);
	}
}
