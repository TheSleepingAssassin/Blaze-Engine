#include "Blaze.h"

namespace Blaze
{
	IBO::IBO(int size, const void *data) : count(size)
	{
		glGenBuffers(1, &this->ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), data, GL_STATIC_DRAW);
	}

	void IBO::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
	}

	void IBO::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	IBO::~IBO()
	{
	}
}
