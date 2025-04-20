#include <libs/graphics/glfwConf.h>

namespace glf
{
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		int widthW = 0, heightW = 0;
		glfwGetWindowSize(window, &widthW, &heightW);
		glViewport(0, 0, width, height);
		//TODO: SCALE PROJECTION
		//tf::Transform::setAspectRatio(800, 600);
		std::cout<<"x = "<<widthW<<" y= "<<heightW<<"\n";
	}


	void window_maximize_callback(GLFWwindow* window, int maximized)
	{
		if (maximized == GLFW_TRUE) {
			std::cout << "Ventana maximizada!" << std::endl;
			tf::Transform::maximized = true;
		} else {
			std::cout << "Ventana restaurada!" << std::endl;
			tf::Transform::maximized = false;
		}
	}

	GLFWwindow* glfwConfiguration(int a, int b)
	{
		glfwInit();
		//configure aspects of glfw, first argument the option, second the setting
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



		GLFWwindow* window = glfwCreateWindow(a, b, "VENTANITA WOO", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "kkkk";
			glfwTerminate();
			
		}

		glfwMakeContextCurrent(window);


		//opengl its just a reference api, glad take charge of send the references of
		// the functions to the OS specific libraries, and opengl acces it, glfw send the 
		//specific references
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Failed to initialize GLAD" << std::endl;
			glfwTerminate();
		}
	


		//tells opengl the area of rendering
		glViewport(0, 0, 800, 800);

		//indicate opengl this is the funcion to resize a window, fill automatic other parameters
		//abstraction
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		glfwSetWindowMaximizeCallback(window, window_maximize_callback);

		return window;
	}
}