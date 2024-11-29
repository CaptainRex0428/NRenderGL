
#include "org/template.h"
#include "tutorial/RectDraw.h"
#include "Render.h"

int main(int argc, const char * argv[])
{
#pragma region OfficialTemplate
	/*static const Vertex vertices[3] =
	{
		{ { -0.6f, -0.4f }, { 1.f, 0.f, 0.f } },
		{ {  0.6f, -0.4f }, { 0.f, 1.f, 0.f } },
		{ {   0.f,  0.6f }, { 0.f, 0.f, 1.f } }
	};

	templateGL::draw(vertices, sizeof(vertices));*/
#pragma endregion

#pragma region RectDraw
	/*rectDraw::Vertex VertexPos[] =
	{
		{{ -.6f, -.4f, 0.f, 1.f},{ 1.f, 0.f, 0.f, 1.f },{ 0.f, 0.f, 1.f, 1.f }},
		{{  .6f, -.4f, 0.f, 1.f},{ 0.f, 1.f, 0.f, 1.f },{ 0.f, 0.f, 1.f, 1.f }},
		{{  .6f,  .6f, 0.f, 1.f},{ 1.f, 0.f, 1.f, 1.f },{ 0.f, 0.f, 1.f, 1.f }},
		{{ -.6f,  .6f, 0.f, 1.f},{ 0.f, 1.f, 1.f, 1.f },{ 0.f, 0.f, 1.f, 1.f }}
	};

	unsigned int Indices[] =
	{
		0,1,2,
		2,3,0
	};

	rectDraw::Render(
		VertexPos, sizeof(VertexPos),
		Indices, sizeof(Indices));*/

#pragma endregion

	render::Vertex VertexPos[] =
	{
		{{ -.6f, -.4f, 0.f, 1.f},{ 1.f, 0.f, 0.f, 1.f },{ 0.f, 0.f, 1.f, 1.f }},
		{{  .6f, -.4f, 0.f, 1.f},{ 0.f, 1.f, 0.f, 1.f },{ 0.f, 0.f, 1.f, 1.f }},
		{{  .6f,  .6f, 0.f, 1.f},{ 0.f, 0.f, 1.f, 1.f },{ 0.f, 0.f, 1.f, 1.f }},
		{{ -.6f,  .6f, 0.f, 1.f},{ 1.f, 0.f, 1.f, 1.f },{ 0.f, 0.f, 1.f, 1.f }}
	};

	unsigned int Indices[] =
	{
		0,1,2,
		2,3,0
	};

	render::Render(
		VertexPos, sizeof(VertexPos),
		Indices, sizeof(Indices));
}