#ifndef OPG_CONF
#define OPG_CONF


#include <graphics/glfwConf.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifdef UPD_UNIFORMS
#define SIMPLE_MATX_CALC
#include <math/utilMath.h>
namespace opg
{
	void setInt(int &loc,  int &newValue);
	void setMat4(int loc, glm::mat4 &newValue);
	void setFloat(int loc, int &newValue);
	void setVec3(int loc, glm::vec3& newValue);
	
}
#endif


namespace opg
{

	class Shader
	{
		private:
			const char* vPath;
			const char* fPath;
		public:
			Shader(const char* vpath, const char* fpath, bool autoDelete = true);
			~Shader();
			void deleteShaders(unsigned int &shader1, unsigned int &shader2);
			int getLoc(unsigned int program, const char* name);
			unsigned int id;
		private:
			unsigned int vShader;
			unsigned int fShader;
			const char* vSource;
			const char* fSource;

			void createShaders(bool autoDelete);
			void createProgram(unsigned int &shader1, unsigned int &shader2);
			
	};

	std::string loadShaderSource(const char* filePath);
	
};



#endif