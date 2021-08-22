#include "Blaze.h"

namespace Blaze
{
	Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, const char *vSS, const char *fSS)
	{
		this->shader = new Shader(vSS, fSS);
		this->SetColor(this->color);
		this->shader->Use();

		float vert[vertices.size()];
		// printf("\nVert:\n");
		for (int i = 0; i < vertices.size(); i++)
		{
			vert[i] = vertices[i];
			// printf("%i:\n", i);
			// printf("\t%1.1f\n", vert[i]);
		}

		unsigned int ind[indices.size()];
		// printf("\nInd:\n");
		for (int i = 0; i < indices.size(); i++)
		{
			ind[i] = indices[i];
			// printf("%i:\n", i);
			// printf("\t%i\n", ind[i]);
		}

		// glGenVertexArrays(1, &this->va);
		// glBindVertexArray(this->va);
		this->va;
		this->va.Bind();
		this->vb = new VBO(sizeof(vert), vert);
		// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
		// glEnableVertexAttribArray(0);
		this->vbl.Push<float>(3);
		va.AddBuffer(vb, vbl);
		this->ib = new IBO(sizeof(ind) / sizeof(ind[0]), ind);
		glBindVertexArray(0);
		this->vb->Unbind();
		this->ib->Unbind();
	}

	void Mesh::SetColor(glm::vec4 vec)
	{
		this->shader->SetVec4(vec, "uColor");
		this->color = vec;
	}

	Mesh::~Mesh()
	{
		delete vb, ib, shader;
	}
}
