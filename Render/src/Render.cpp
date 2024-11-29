#include "Render.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>

#include <glew.h>
#include <GLFW/glfw3.h>

struct ShaderSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

static std::string GetShaderPath(const std::string & shadername)
{
	std::filesystem::path workPath = std::filesystem::current_path();
	std::filesystem::path filepath = workPath / "res" / "Shader" / shadername;
	return filepath.string();
};

static ShaderSource ParseShader(const std::string & filepath)
{
	enum class ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	std::ifstream stream(filepath);

	std::stringstream shaderStream[2];
	ShaderType type = ShaderType::NONE;

	std::string line;
	while(getline(stream,line))
	{
		if(line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
		{
			shaderStream[(int)type] << line << std::endl;
		}
	}

	return {shaderStream[(int)ShaderType::VERTEX].str(), shaderStream[(int)ShaderType::FRAGMENT].str()};
}

static unsigned int CompileShader(unsigned int type,const std::string & source)
{
	unsigned int id = glCreateShader(type);
	const char * src = source.c_str();

	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id,GL_COMPILE_STATUS, &result);
	if (!result)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char * message = (char * )malloc(length * sizeof(char));
		glGetShaderInfoLog(id,length,&length,message);
		
		std::cout << message << std::endl;

		glDeleteShader(id);

		return 0;
	}

	std::cout << "Shader compiled >> " << type << " : " << id << std::endl;

	return id;
}

static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int VS = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int FS = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	
	glAttachShader(program, VS);
	glAttachShader(program, FS);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(VS);
	glDeleteShader(FS);

	std::cout << "Shader program compiled >> " << program << std::endl;

	return program;
}

int render::Render(
	const Vertex* Vertices, unsigned int VerticesSize,
	const unsigned int* Indices, unsigned int IndicesSize)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	
	/* Initialize GLEW library */
	if (glewInit() != GLEW_OK)
	{
		return -1;
	}

	std::cout << "OpenGL Version " << glGetString(GL_VERSION) << std::endl;

#pragma region buffer

	unsigned int buffer;
	glGenBuffers(1,&buffer); // integer here is a specific identifier of buffer
	glBindBuffer(GL_ARRAY_BUFFER,buffer);
	glBufferData(GL_ARRAY_BUFFER, VerticesSize, Vertices,GL_STATIC_DRAW);// specify the data and specify how to call draw

	unsigned int indicesBuffer;
	glGenBuffers(1, &indicesBuffer); // integer here is a specific identifier of buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, IndicesSize, Indices, GL_STATIC_DRAW);// specify the data and specify how to call draw

#pragma endregion

#pragma region CompileShader

	ShaderSource shaderSource = ParseShader(GetShaderPath("Basic.shader"));
	unsigned int shader = CreateShader(shaderSource.VertexSource, shaderSource.FragmentSource);

	glUseProgram(shader);

#pragma endregion

#pragma region BindShaderParameters

	// 第一个参数（index）指定了你在着色器中为顶点属性所设置的位置索引。
	// 它用于将 OpenGL 绑定的顶点属性数据与顶点着色器中的相应输入变量相匹配。
	const unsigned int vPos_Idx =  glGetAttribLocation(shader,"vPos");
	glEnableVertexAttribArray(vPos_Idx);
	glVertexAttribPointer(
		vPos_Idx,
		sizeof(render::Vector) / sizeof(float), 
		GL_FLOAT, GL_FALSE, 
		sizeof(render::Vertex), 
		(void*)offsetof(render::Vertex, pos));

	const unsigned int vColor_Idx = glGetAttribLocation(shader, "vCol");
	glEnableVertexAttribArray(vColor_Idx);
	glVertexAttribPointer(
		vColor_Idx,
		sizeof(render::Color) / sizeof(float),
		GL_FLOAT, GL_FALSE,
		sizeof(render::Vertex),
		(void*)offsetof(render::Vertex, color));

	const unsigned int MVP_Idx = glGetUniformLocation(shader, "MVP");

#pragma endregion

#pragma region draw

	while (!glfwWindowShouldClose(window))
	{
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		const float ratio = width / (float)height;

		/* Render here */
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		/*mat4x4 m, p, mvp;
		mat4x4_identity(m);
		mat4x4_rotate_Z(m, m, (float)glfwGetTime());
		mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		mat4x4_mul(mvp, p, m);

		glUniformMatrix4fv(MVP_Idx, 1, GL_FALSE, (const GLfloat*)&mvp);*/
		
		glDrawElements(GL_TRIANGLES, IndicesSize / sizeof(unsigned int), GL_UNSIGNED_INT, nullptr);

		// glDrawArrays(GL_TRIANGLES, 0, 3);
		
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}

#pragma endregion

#pragma region clear

	glDeleteShader(shader);

	glfwTerminate();

#pragma endregion

	return 0;
}
