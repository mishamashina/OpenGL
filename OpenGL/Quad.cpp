#include "Quad.h"

Quad::Quad()
{
	x = 0;
	y = 0;
	angle = 0;
	size = 20;
}

Quad::~Quad()
{

}

void Quad::Update()
{

}

void Quad::Render()
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-size, -size, 0);
	glVertex3f(size, -size, 0);
	glVertex3f(size, size, 0);
	glVertex3f(-size, size, 0);


}