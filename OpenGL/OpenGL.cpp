// OpenGL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <GL/glut.h>
#include "Quad.h"

Quad* quad;

void Init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200, 200, -200, 200, -50, 50);

    quad = new Quad();

}

void Keyboard(unsigned char key, int x, int y)//первый аргумент это значение кнопки и координаты мыши. данная функция вызывается тогда когда нажат какой-нибудь символьный код (т.е. буквы и цифры)

{
    switch (key)

    {
    case 'a': quad->RotateLeft(); break;//вращаемся влево
    case 'd': quad->RotateRight(); break;//вращаемся вправо
    }
}



void SpecialKeyboard(int key, int x, int y)//вызывается когда нажата спец клавиша (стрелка, шифт, и т.д.)
{
    switch (key)
    {
    case GLUT_KEY_LEFT: quad->MoveLeft(); break;
    case GLUT_KEY_RIGHT: quad->MoveRight(); break;
    case GLUT_KEY_UP: quad->MoveUp(); break;
    case GLUT_KEY_DOWN: quad->MoveDown(); break;
    }
}

void mouseMove(int ax, int ay) {
    //quad->setPos(ax, ay);
}



void mousePressed(int button, int state, int x, int y) {

    quad->setPos(x, y);
    switch (button)
    {
    case GLUT_LEFT_BUTTON: quad->setColorGreen(); break;
    case GLUT_RIGHT_BUTTON: quad->setColorRed(); break;
    default:
        break;
    }
}



void mousePressedMove(int ax, int ay) {
    //quad->setPos(ax, ay);
}


void Update(int)
{
    glutPostRedisplay();
    quad->Update();
    glutTimerFunc(30, Update, 0);
}

void Render()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    quad->Render();

    glutSwapBuffers();
}

int main()
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(Render);
    glutTimerFunc(100, Update, 0);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SpecialKeyboard);
    glutMotionFunc(mousePressedMove);
    glutPassiveMotionFunc(mouseMove);
    glutMouseFunc(mousePressed);
    Init();
    glutMainLoop();
    delete quad;
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
