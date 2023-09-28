#pragma once
#include <stdlib.h>//для использования функции random при задании значения скорости вращения
#include <time.h>//для инициализации "зерна" генератора
#include <GL/glut.h>

class Quad
{
public:
	Quad();
	~Quad();
	void Update();
	void Render();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void RotateLeft();
	void RotateRight();
	void setPos(int _x, int _y);
	void setColorRed();
	void setColorGreen();


private:
	float x, y, angle;
	int size;
	float speedX;//скорость перемещения по оси x
	float speedY;//скорость перемещения по оси y
	float rotateSpeed;//скорость вращения
};

