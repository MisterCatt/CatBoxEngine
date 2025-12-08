#pragma once
#include <string>
class Shader
{
private:
	std::string LoadShader(const char* aPath);
	unsigned int LoadVertexShader(const char* aShaderPath, unsigned int aShaderType);
	unsigned int LoadFragmentShader(const char* aShaderPath, unsigned int aShaderType);
public:
	unsigned int myShaderProgram;
	void Initialize(const char* aVertexPath, const char* aFragmentPath);
	void Use();
};

