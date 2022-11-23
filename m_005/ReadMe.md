## ЛР № 5. Построение 3D-сцены

Необходимо реализовать программу с использованием библиотеки OpenGL, которая отображает трехмерную сцену из множества трехмерных текстурированных объектов. Объекты можно создать самому, можно использовать объекты, описанные в модулях glaux (auxSolidSphere, auxSolidBox, auxSolidCylinder, auxSolidIcosahedron, auxSolidTeapot и др.) или glu (gluSphere, gluDisk, gluCylinder).

## run
```
cd ../ && cd 005 && g++ 005.cpp -lGL -lGLU -lGLEW -lglut -o 005 && ./005
```