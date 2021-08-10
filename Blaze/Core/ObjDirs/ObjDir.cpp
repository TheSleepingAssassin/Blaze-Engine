#include "Blaze.h"

namespace Blaze
{
	namespace DEFVALS
	{
		std::vector<float> CUBEVS{-0.5f, 0.5f, 0.5f,
															0.5f, 0.5f, 0.5f,
															-0.5f, -0.5f, 0.5f,
															0.5f, -0.5f, 0.5f,

															-0.5f, 0.5f, -0.5f,
															0.5f, 0.5f, -0.5f,
															-0.5f, -0.5f, -0.5f,
															0.5f, -0.5f, -0.5f};

		std::vector<unsigned int> CUBEIS{0, 1, 2,
																		 1, 2, 3,

																		 0, 4, 6,
																		 1, 6, 2,

																		 1, 5, 7,
																		 1, 7, 3,

																		 0, 1, 4,
																		 1, 4, 5,

																		 2, 3, 6,
																		 3, 6, 7,

																		 4, 5, 6,
																		 5, 6, 7};

		std::vector<float> PLANEVS{-0.5f, 0.0f, 0.5f,
															 0.5f, 0.0f, 0.5f,
															 -0.5f, 0.0f, -0.5f,
															 0.5f, 0.0f, -0.5f};

		std::vector<unsigned int> PLANEIS{0, 1, 2,
																			1, 2, 3};

		std::string DVSS = R"glsl(
		#version 330 core

		layout (location = 0) in vec3 aPos;

		uniform mat4 proj;
		uniform mat4 view;
		uniform mat4 model;

		void main()
		{
			gl_Position = proj * view * model * vec4(aPos, 1.0);
		};
	)glsl";

		std::string DFSS = R"glsl(
		#version 330 core

		out vec4 color;

		uniform vec4 uColor;

		void main()
		{
			color = uColor;
		};
	)glsl";
	}
}
