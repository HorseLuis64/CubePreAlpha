#include<libs/graphics/glad.h>

#ifdef UPD_UNIFORMS
#define SIMPLE_MATX_CALC
#include <math/utilMath.h>

namespace uf
{
  

	void setInt(int &loc,  int &newValue);
	void setMat4(int loc, glm::mat4 &newValue);
	void setFloat(int loc, int &newValue);
	void setVec3(int loc, glm::vec3& newValue);
	


}

#endif