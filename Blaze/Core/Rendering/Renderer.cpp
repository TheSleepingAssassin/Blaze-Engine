#include "Blaze.h"

namespace Blaze
{
	Renderer::Renderer(CamTransform *cam, float width, float height)
	{
		this->cam = cam;
		this->width = width;
		this->height = height;
	}

	Renderer::Renderer(float width, float height)
	{
		this->width = width;
		this->height = height;
	}

	void Renderer::Init(CamTransform *cam)
	{
		this->cam = cam;
	}

	void Renderer::Draw()
	{
		for (auto o : this->objects)
		{
			o->mesh->shader->SetMat4(this->cam->GetProj(this->width, this->height), "proj");
			o->mesh->shader->SetMat4(this->cam->GetTransform(), "view");
			o->mesh->shader->SetMat4(o->transform.GetTransform(), "model");
			o->Draw();
		}
	}

	void Renderer::AddObject(GameObject *gameObject)
	{
		this->objects.push_back(gameObject);
	}

	void Renderer::SetCamera(CamTransform *cam)
	{
		this->cam = cam;
	}

	Renderer::~Renderer()
	{
	}
}
