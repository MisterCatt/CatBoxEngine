#include "Shader.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <glad/glad.h>

std::string Shader::LoadShader(const char* aPath)
{
    std::string shaderCode;
    std::ifstream shaderFile(aPath); // Initialize with file path

    if (!shaderFile.is_open()) { //Handle error if no file exists
		std::cerr << "Failed to open shader file: " << aPath << std::endl;
        return "";
    }

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();

    shaderFile.close();
    shaderCode = shaderStream.str();
    return shaderCode;
}

unsigned int Shader::LoadVertexShader(const char* aShaderPath, unsigned int aShaderType)
{
	int result;
    char Log[512];

	std::string shaderCodeString = LoadShader(aShaderPath);
	const char* shaderCode = shaderCodeString.c_str();

    unsigned int shaderObject;
	shaderObject = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shaderObject, 1, &shaderCode, NULL);
    glCompileShader(shaderObject);

	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &result);

    if (!result) {
        glGetShaderInfoLog(shaderObject, 512, NULL, Log);
		std::cerr << "Vertex Shader Compilation Failed: " << Log << std::endl;

    }
    return shaderObject;
}

unsigned int Shader::LoadFragmentShader(const char* aShaderPath, unsigned int aShaderType)
{
    int result;
    char Log[512];

    std::string shaderCodeString = LoadShader(aShaderPath);
    const char* shaderCode = shaderCodeString.c_str();

    unsigned int shaderObject;
    shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shaderObject, 1, &shaderCode, NULL);
    glCompileShader(shaderObject);

    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &result);

    if (!result) {
        glGetShaderInfoLog(shaderObject, 512, NULL, Log);
        std::cerr << "Vertex Shader Compilation Failed: " << Log << std::endl;

    }
    return shaderObject;
}

void Shader::Initialize(const char* aVertexPath, const char* aFragmentPath)
{
    int result;
    char Log[512];

    unsigned int vertexShader = LoadVertexShader(aVertexPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = LoadFragmentShader(aFragmentPath, GL_FRAGMENT_SHADER);
    
    myShaderProgram = glCreateProgram();

    glAttachShader(myShaderProgram, vertexShader);
    glAttachShader(myShaderProgram, fragmentShader);
    glLinkProgram(myShaderProgram);

	glGetProgramiv(myShaderProgram, GL_LINK_STATUS, &result);
    if (!result) {
		glGetProgramInfoLog(myShaderProgram, 512, NULL, Log);
		std::cerr << "Shader Program Linking Failed: " << Log << std::endl;
    }

    glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Use()
{
	glUseProgram(myShaderProgram);
}
