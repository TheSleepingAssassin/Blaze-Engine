#include "Blaze.h"

namespace Blaze
{
	VA::VA()
	{
		glGenVertexArrays(1, &this->ID);
		glBindVertexArray(this->ID);
	}

	void VA::AddBuffer(const VBO *vb, const VBL &vbl)
	{
		vb->Bind();
		const auto &elements = vbl.GetElements();
		unsigned int offset = 0;
		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto &e = elements[i];
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, e.count, e.type, e.normalized ? GL_TRUE : GL_FALSE, vbl.GetStride(), (void *)offset);
			offset += e.count * VBEL::GetSizeOfType(e.type);
		}
	}

	void VA::Bind() const
	{
		glBindVertexArray(this->ID);
	}

	void VA::Unbind() const
	{
		glBindVertexArray(0);
	}

	VA::~VA()
	{
	}
}
