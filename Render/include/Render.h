#pragma once
#include "linmath.h"

namespace render
{
	struct Vector
	{
		float x;
		float y;
		float z;
		float w;
	};

	struct Color
	{
		float R;
		float G;
		float B;
		float A;
	};

	struct Vertex
	{
		Vector pos;
		Color color;
		Vector normal;
	};

	int Render(
		const Vertex* Vertices, unsigned int VerticesSize, 
		const unsigned int* Indices, unsigned int IndicesSize);
}