#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Blaze
{
	class Window
	{
	public:
		Window(const char *);
		bool ShouldClose();
		~Window();
		GLFWwindow *handle;
		int width, height;
	};

	class VBO
	{
	public:
		VBO(unsigned int, const void *);
		void Bind() const;
		void Unbind() const;
		~VBO();
		unsigned int ID;
	};

	class IBO
	{
	public:
		IBO(int, const void *);
		void Bind() const;
		void Unbind() const;
		~IBO();
		unsigned int ID;
		int count;
	};

	class Shader
	{
	public:
		Shader(const char *, const char *);
		void Use() const;
		void Disuse() const;
		void SetMat4(const glm::mat4 &, const char *);
		void SetVec4(glm::vec4, const char *);
		~Shader();
		unsigned int ID;
	};

	struct Transform
	{
		glm::vec3 Translation = {0.0f, 0.0f, 0.0f};
		glm::vec3 Rotation = {0.0f, 0.0f, 0.0f};
		glm::vec3 Scale = {1.0f, 1.0f, 1.0f};

		glm::mat4 GetTransform()
		{
			glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

			return glm::translate(glm::mat4(1.0f), Translation) * rotation * glm::scale(glm::mat4(1.0f), Scale);
		}
	};

	struct VBEL
	{
		unsigned int type;
		unsigned int count;
		bool normalized;
		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT:
				return 4;
			case GL_UNSIGNED_INT:
				return 4;
			case GL_UNSIGNED_BYTE:
				return 1;
			}
			return 0;
		}
	};

	class VBL
	{
	private:
		std::vector<VBEL> elements;
		unsigned int stride;

	public:
		VBL() : stride(0) {}

		template <typename T>
		void Push(unsigned int count);

		inline const std::vector<VBEL> GetElements() const { return elements; }
		inline unsigned int GetStride() const { return stride; }
	};

	template <>
	inline void VBL::Push<float>(unsigned int count)
	{
		elements.push_back({GL_FLOAT, count, false});
		stride += count * VBEL::GetSizeOfType(GL_FLOAT);
	}

	template <>
	inline void VBL::Push<unsigned int>(unsigned int count)
	{
		elements.push_back({GL_UNSIGNED_INT, count, false});
		stride += count * VBEL::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template <>
	inline void VBL::Push<unsigned char>(unsigned int count)
	{
		elements.push_back({GL_UNSIGNED_BYTE, count, false});
		stride += count * VBEL::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	class VA
	{
	public:
		VA();
		void AddBuffer(const VBO *, const VBL &);
		void Bind() const;
		void Unbind() const;
		~VA();
		unsigned int ID;
	};

	struct Mesh
	{
		VA va;
		VBL vbl;
		VBO *vb;
		IBO *ib;
		Shader *shader;
		glm::vec4 color = {1.0f, 1.0f, 1.0f, 1.0f};

		Mesh(std::vector<float>, std::vector<unsigned int>, const char *vSS, const char *fSS);
		void SetColor(glm::vec4);
		~Mesh();
	};

	struct CamTransform
	{
		glm::vec3 Translation = {0.0f, 0.0f, 0.0f};
		glm::vec3 Rotation = {0.0f, 0.0f, 0.0f};
		float fov = 90.0f;

		glm::mat4 GetProj(float width, float height)
		{
			return glm::perspective(glm::radians(this->fov), width / height, 0.1f, 1000.0f);
		}

		glm::mat4 GetTransform()
		{
			glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

			return glm::translate(glm::mat4(1.0f), Translation) * rotation;
		}
	};

	class GameObject
	{
	public:
		Transform transform;
		Mesh *mesh;

		GameObject(glm::vec3, std::vector<float>, std::vector<unsigned int>, std::string vSS, std::string fSS);
		GameObject(glm::vec3, int);
		void Draw();
		~GameObject();
	};

	class Renderer
	{
	public:
		std::vector<GameObject *> objects;
		CamTransform *cam;
		int width, height;

		Renderer(CamTransform *, float, float);
		Renderer(float, float);
		void Init(CamTransform *);
		void Draw();
		void AddObject(GameObject *);
		void SetCamera(CamTransform *);
		~Renderer();
	};

	enum TAGS
	{
		CUBE = 0x12201,
		PLANE = 0x12202
	};

	namespace DEFVALS
	{
		extern std::vector<float> CUBEVS;
		extern std::vector<unsigned int> CUBEIS;
		extern std::vector<float> PLANEVS;
		extern std::vector<unsigned int> PLANEIS;
		extern std::string DVSS;
		extern std::string DFSS;
	}
}
