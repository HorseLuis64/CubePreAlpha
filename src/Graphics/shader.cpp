#define UPD_UNIFORMS
#include <graphics/shader.h>


namespace opg
{
void checkShaderCompilation(unsigned int shader);
void checkProgramLinking(unsigned int program);
std::string loadShaderSource(const char* filePath);
}

namespace opg
{

	Shader::Shader(const char* vpath, const char* fpath, bool autoDelete) : vPath(vpath), fPath(fpath)
	{
		createShaders(autoDelete);
	}

	Shader::~Shader(){};

	void Shader::createProgram(unsigned int &shader1, unsigned int &shader2)
	{
		id = glCreateProgram();
		glAttachShader(id, shader1);
		glAttachShader(id, shader2);
		glLinkProgram(id);
		checkProgramLinking(id);
		glDeleteShader(shader1);
		glDeleteShader(shader2);
	}

	void Shader::deleteShaders(unsigned int &shader1, unsigned int &shader2)
	{
		glDeleteShader(shader1);
		glDeleteShader(shader2);
	}
	void Shader::createShaders(bool autoDelete)
	{
		std::string s_vSource;
		std::string s_fSource;
		
		s_vSource = loadShaderSource(vPath);
		s_fSource = loadShaderSource(fPath);

		vSource = s_vSource.c_str();
		fSource = s_fSource.c_str();

		vShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vShader, 1, &vSource, NULL);
		glCompileShader(vShader);
		std::cout<<"vertex shader: "<<"\n";
		checkShaderCompilation(vShader);

		fShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fShader, 1, &fSource, NULL);
		glCompileShader(fShader);
		std::cout<<"fragment shader: "<<"\n";
		checkShaderCompilation(fShader);

		createProgram(vShader, fShader);
		if(autoDelete)
		{
			deleteShaders(vShader, fShader);
		}
	}

	int Shader::getLoc(unsigned int program, const char* name)
	{
		return glGetUniformLocation(program, name);
	}


	///NOT MINEEEEE



	void checkShaderCompilation(unsigned int shader)
	{
		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
			return;
		}
		std::cout<<"SUCCESS!"<<"\n";
		
	}

	void checkProgramLinking(unsigned int program)
	{
		int success;
		char infoLog[512];
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
	}

	std::string loadShaderSource(const char* filePath) 
	{
		std::ifstream file(filePath);
		if (!file.is_open()) {
			std::cerr << "Error al abrir el archivo de shader: " << filePath << std::endl;
			return "";
		}
	
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		return buffer.str();
	}

}

















//GLFW STUFF
namespace opg 
{
	

}