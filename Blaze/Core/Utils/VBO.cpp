#include "Blaze.h"

namespace Blaze
{
	VBO::VBO(unsigned int size, const void *data)
	{
		glGenBuffers(1, &this->ID);
		glBindBuffer(GL_ARRAY_BUFFER, this->ID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	void VBO::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->ID);
	}

	void VBO::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VBO::~VBO()
	{
	}
}
