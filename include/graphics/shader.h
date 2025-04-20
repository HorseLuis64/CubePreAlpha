#ifndef OPG_CONF
#define OPG_CONF


#include <libs/graphics/glfwConf.h>
#include<graphics/uniforms.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>




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