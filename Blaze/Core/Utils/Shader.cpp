#include "Blaze.h"

static unsigned int CompileShader(unsigned int type, const char *source)
{
	unsigned int ID = glCreateShader(type);
	glShaderSource(ID, 1, &source, NULL);
	glCompileShader(ID);

	return ID;
}

static unsigned int CreateShader(const char *vSS, const char *fSS)
{
	unsigned int ID = glCreateProgram();
	unsigned int vS = CompileShader(GL_VERTEX_SHADER, vSS);
	unsigned int fS = CompileShader(GL_FRAGMENT_SHADER, fSS);
	glAttachShader(ID, vS);
	glAttachShader(ID, fS);
	glLinkProgram(ID);

	glDeleteShader(vS);
	glDeleteShader(fS);

	return ID;
}

namespace Blaze
{
	Shader::Shader(const char *vSS, const char *fSS)
	{
		this->ID = CreateShader(vSS, fSS);
		glUseProgram(this->ID);
	}

	void Shader::Use() const
	{
		glUseProgram(this->ID);
	}

	void Shader::Disuse() const
	{
		glUseProgram(0);
	}

	void Shader::SetMat4(const glm::mat4 &mat, const char *name)
	{
		glUseProgram(this->ID);
		int location = glGetUniformLocation(this->ID, name);
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
		glUseProgram(0);
	}

	void Shader::SetVec4(glm::vec4 vec, const char *name)
	{
		glUseProgram(this->ID);
		int location = glGetUniformLocation(this->ID, name);
		glUniform4f(location, vec[0], vec[1], vec[2], vec[3]);
		glUseProgram(0);
	}

	Shader::~Shader()
	{
	}
}
