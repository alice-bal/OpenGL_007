## TUTORIALS

[книга](http://pm.samgtu.ru/sites/pm.samgtu.ru/files/materials/comp_graph/RedBook_OpenGL.pdf)

[туторы Basic OpenGL](http://www.opengl-tutorial.org/beginners-tutorials/)

[норм туторы](http://citforum.ru/programming/opengl/opengl_05.shtml)

[странные туторы](https://www.opengl.org/resources/libraries/glut/spec3/spec3.html)

### примеры

[примеры GIT](https://github.com/progschj/OpenGL-Examples)

[шестеренки](http://www.gamedev.ru/code/forum/?id=126000)

[часы](https://russianblogs.com/article/1931477112/)

[круги на воде](https://github.com/Liza-S/Simple-Animation-of-circles-OpenGL)

[цветные кружочки](https://github.com/nikolas/stars)

### инструменты

[конвертер цветов](https://colorscheme.ru/color-converter.html)

[звезда координаты](https://intuit.ru/studies/courses/595/451/lecture/10074?page=10)

[компиляция Opgl](http://titan.csit.rmit.edu.au/~e20068/teaching/i3dg&a/2016/compiling.html)

----------------------------------------------------------------------

## BUILD & RUN 

### with terminal

```
# cd example
g++ example.cpp -lGL -lGLU -lGLEW -lglut -o example && ./example

# cd 001
g++ 001.cpp -lGL -lGLU -lGLEW -lglut -o 001 && ./001
```
----------------------------------------------------------------------

## PUSH TO ORIGIN

### new origin

```
git init
git remote add origin git@github.com:alice-bal/OPGL_007.git
git remote -v
git checkout -b main
git add .
git commit -m "v1"
git push origin main
```

### old origin

```
git add .
git commit -m "v1"
git push origin main
```
### delete remote origin

```
find . -name ".git" | xargs rm -Rf
```