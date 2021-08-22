#include "Blaze.h"

namespace Blaze
{
	GameObject::GameObject(glm::vec3 pos, std::vector<float> vertices, std::vector<unsigned int> indices, std::string vSS, std::string fSS)
	{
		transform.Translation = pos;

		mesh = new Mesh(vertices, indices, vSS.c_str(), fSS.c_str());
	}

	GameObject::GameObject(glm::vec3 pos, int tag)
	{
		transform.Translation = pos;

		switch (tag)
		{
		case TAGS::CUBE:
			mesh = new Mesh(DEFVALS::CUBEVS, DEFVALS::CUBEIS, DEFVALS::DVSS.c_str(), DEFVALS::DFSS.c_str());
			break;

		case TAGS::PLANE:
			mesh = new Mesh(DEFVALS::PLANEVS, DEFVALS::PLANEIS, DEFVALS::DVSS.c_str(), DEFVALS::DFSS.c_str());
			break;
		}
	}

	void GameObject::Draw()
	{
		mesh->shader->Use();
		mesh->va.Bind();
		glDrawElements(GL_TRIANGLES, mesh->ib->count, GL_UNSIGNED_INT, 0);
	}

	GameObject::~GameObject()
	{
		delete mesh;
	}
}
