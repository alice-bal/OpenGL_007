#define _USE_MATH_DEFINES

#include <GL/glut.h>
#include <GL/glaux.h>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

#pragma comment (lib, "glaux.lib")
#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

// подключение библиотеки legacy_stdio_definitions для Visual Studio 2015 и выше
#pragma comment(lib, "legacy_stdio_definitions.lib")

int w = 600, h = 600;

struct P // координаты, скорость и размер объекта
{
    float x;
    float y;
    float vx;
    float vy;
    float r;
    int tex;
    const float DT = 0.01;
};

vector<P> p;  // список объектов
GLuint texture[4]; // массив имен текстур - всего четыре

GLvoid LoadTextures(int n, char filename[])  // загрузить текстуры
{
    // указатель на структуру для хранения картинок
    AUX_RGBImageRec* texture_load;

    // загрузка текстуры из файла
    texture_load = auxDIBImageLoadA(filename);

    // выбор текущей текстуры
    glBindTexture(GL_TEXTURE_2D, texture[n]);

    // установка линейной фильтрации
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // наложение текстуры на цвет
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //  Decal mode--where the texture is painted on top of the object(as a 
    //     decal would be applied)
    //  Replace mode--which responds the same as Decal mode for RGB
    //  Modulate mode--where the texture modulates or scales the object's 
    //     color
    //  Blend mode--where a specified constant color can be blended with 
    //     that of the object, based on the texture value. 

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // создание текстуры
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,  
        texture_load->sizeX,                 
        texture_load->sizeY,                 
        0, GL_RGB, GL_UNSIGNED_BYTE,
        texture_load->data);                 
}

void light()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Значение фонового света
    GLfloat light1[] = { 1, 1, 1, 1.0 };
    // Позиция света
    GLfloat light_position1[] = { 300, 300, 150, 1 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light1);
    //  Ambient--uniform on all points of all surfaces, disregards light 
    //     sources, usually low intensity
    //  Diffuse--rays assumed to deflect off surface equally in all 
    //     directions,so camera position is irrelevant, full intensity 
    //     when ray is perpendicular to surface, falls off to zero when 
    //     parallel to surface
    //  Specular--rays deflected off surface at inverse angle, so camera 
    //     position matters, creates bright highlights

    // включение источника света
    glEnable(GL_LIGHT0);

    // красный свет

    GLfloat light2[] = { 1, 0, 0, 1.0 };
    GLfloat light_position2[] = { 550, 10, 50, 1 };

    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light2);

    glEnable(GL_LIGHT1);

    // синий свет

    GLfloat light3[] = { 0, 0, 1, 1.0 };
    GLfloat light_position3[] = { 10, 550, 50, 1 };

    glLightfv(GL_LIGHT2, GL_POSITION, light_position3);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light3);

    glEnable(GL_LIGHT2);

    // включение освещения
    glEnable(GL_LIGHTING);
}

void init(void)
{
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, 0, 10);
    gluLookAt(0, 0, 3,  0, 0, 0,  0, 1, 0);

    // генерация имен текстур
    glGenTextures(4, texture);
    char file[] = "t1.bmp";
    LoadTextures(0, file);
    strcpy_s(file, "t2.bmp");
    LoadTextures(1, file);
    strcpy_s(file, "t3.bmp");
    LoadTextures(2, file);
    strcpy_s(file, "t4.bmp");
    LoadTextures(3, file);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);

    glColor3d(1, 1, 1);

    float n = 30;
    for (vector<P>::iterator i = p.begin(); i != p.end(); ++i)
    {        
        // присвоить текстуру
        glBindTexture(GL_TEXTURE_2D, texture[i->tex]);

        // нарисовать все полигоны из списка
        glBegin(GL_POLYGON);
        {
            for (int a = 0; a < n; ++a)
            {
                float x = i->r * cos(2 * a * M_PI / n);
                float y = i->r * sin(2 * a * M_PI / n);
                // закрепить координату текстуры с координатой вершины
                glTexCoord2f(x / (2 * i->r) + 0.5, y / (2 * i->r) + 0.5);  
                glVertex2f(x + i->x, y + i->y);
            }
        }
        glEnd();
    }

    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void timer(int)
{
    for (vector<P>::iterator i = p.begin(); i != p.end(); ++i)
    {        
        //отталкивание от экрана
        if (i->x - i->r <= 0 || i->x + i->r >= w)
            i->vx *= -1;
        if (i->y - i->r <= 0 || i->y + i->r >= h)
            i->vy *= -1;

        //переместить элемент
        i->x += i->vx * i->DT;
        i->y += i->vy * i->DT;
    }

    // отразить изменения
    glutPostRedisplay();
    // следующий кадр
    glutTimerFunc(10, timer, 0);
}

void exit_key(unsigned char key, int x, int y) 
{
    if (key == 27)
        exit(0);
}

int main(int argc, char** argv)
{
    cout << "Number of objects = ";
    int n;
    cin >> n;

    int rad = 30;

    srand(6);

    // инициализация объектов
    for (int i = 0; i < n; ++i)
    {
        P p0 = { rand() % (w - 2 * rad) + rad, // положение на экране
            rand() % (h - 2 * rad) + rad,
            rand() / 250.0 - 20, // скорость
            rand() / 250.0 - 20,
            rad,   // размер
            rand() % 4 };  // текстура
        p.push_back(p0);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("");

    init();
    glutDisplayFunc(display);
    light();
    timer(0);
    glutKeyboardFunc(exit_key);

    glutMainLoop();

    p.clear();
    glDeleteTextures(4, texture);
    glDisable(GL_LIGHTING);

    return 0;
}
