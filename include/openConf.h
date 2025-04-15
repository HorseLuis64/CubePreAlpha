#ifndef OPG_CONF
#define OPG_CONF


#include <glfwConf.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifdef UPD_UNIFORMS
#define MATX_CALC
#include <utilMath.h>
namespace opg
{
	void UpdSetInt(unsigned int program, const char* value, int newValue);
	void UpdSetMat4(unsigned int program, const char* value, glm::mat4 newValue);
	void UpdSetFloat(unsigned int program, const char* value, int newValue);
	void UpdSetVec3(unsigned int program, const char* value, glm::vec3 newValue);
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
			Shader(const char* vpath, const char* fpath);
			~Shader();
			
			unsigned int id;
		private:
			unsigned int vShader;
			unsigned int fShader;
			const char* vSource;
			const char* fSource;

			void createShaders();
			void createProgram(unsigned int &shader1, unsigned int &shader2);
	};

	std::string loadShaderSource(const char* filePath);
	
};



#endif