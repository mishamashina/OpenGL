#include "Quad.h"

Quad::Quad()
{
	x = 0;
	y = 0;
	angle = 0;
	size = 20;
	srand(time(0));// для того чтобы значения всегда были случайные мы инициализируем наш генератор зерном. в качестве зерна выступает текущее время

	speedX = rand() % 10;// %10 - указывает, что выбирается случайное значение до 10

	speedY = rand() % 10;

	rotateSpeed = rand() % 10;
}

Quad::~Quad()
{

}

void Quad::setPos(int _x, int _y) {//устанавливаем координаты квадрата
	x = _x;
	y = _y;
}

void Quad::setColorRed() {//перекрашиваем квадрат в красный цвет
	glColor3f(1.0f, 0.0f, 0.0f);

}

void Quad::setColorGreen() {//перекрашиваем квадрат в зеленый цвет
	glColor3f(0.0f, 1.0f, 0.0f);
}

void Quad::MoveUp()

{
	if (y + size < 200)
		y += 10;
}
void Quad::MoveDown()
{
	if (y - size > -200)
		y -= 10;
}
void Quad::MoveLeft()

{
	if (x - size > -200)
		x -= 10;
}

void Quad::MoveRight()

{
	if (x + size < 200)
		x += 10;
}

void Quad::RotateLeft()

{
	angle += 10;
}



void Quad::RotateRight()

{
	angle -= 10;
}

void Quad::Update()
{
	x += speedX;
	y += speedY;
	angle += rotateSpeed;

	if (angle > 360)
		angle = 0;
	//для того чтобы квадрат отскакивал от границ экрана
	if (x + size > 200 || x - size < -200)//задаем правую и левую границу экраны
		speedX *= -1;//начало движения в противоположном направлении
	if (y + size > 200 || y - size < -200)
		speedY *= -1;
}

void Quad::Render()
{
	glTranslatef(x, y, 0);//подключаем матрицу и перемещаем ее на наш квадратик
	//Функция glTranslatef умножает текущую матрицу на матрицу преобразования.

	glRotatef(angle, 0, 0, 1);//делаем поворот, указывая ось вокруг которой происходит вращение. в нашем случае z=1 - будем вращать вокруг данной оси
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-size, -size, 0);
	glVertex3f(size, -size, 0);
	glVertex3f(size, size, 0);
	glVertex3f(-size, size, 0);
	glEnd();
	glRotatef(-angle, 0, 0, 1);//возвращаем объект обратно
	glTranslatef(-x, -y, 0);
}