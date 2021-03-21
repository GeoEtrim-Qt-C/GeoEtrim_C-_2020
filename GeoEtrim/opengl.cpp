#include "opengl.h"
#include "math.h"
#include "QDebug"

#include <iostream>
#include <vector>

using namespace std;

GLdouble model[16];
GLdouble proj[16];
GLint view[16];

OpenGL::OpenGL(QWidget *parent):QOpenGLWidget{parent}
{
}

void OpenGL::mousePressEvent(QMouseEvent *event)
{
    this->hareketeBaslamaNoktasi.setX(event->x());
    this->hareketeBaslamaNoktasi.setY(event->y());
    update();
}

void OpenGL::mouseMoveEvent(QMouseEvent *event)
{
    if (!((this->hareketeBaslamaNoktasi.x() != this->hareketiBitirmeNoktasi.x()) | (this->hareketeBaslamaNoktasi.y() != this->hareketiBitirmeNoktasi.y()))) { return; }

        this->KonumY = ((-event->y() + this->hareketeBaslamaNoktasi.y()) + this->KonumY);
        this->KonumX = (-(-event->x() + this->hareketeBaslamaNoktasi.x()) + (this->KonumX));

        this->hareketeBaslamaNoktasi.setX(event->x());
        this->hareketeBaslamaNoktasi.setY(event->y());

    update();
}

void OpenGL::mouseReleaseEvent(QMouseEvent *event)
{
    this->hareketeBaslamaNoktasi.setX(this->hareketiBitirmeNoktasi.x());
    this->hareketeBaslamaNoktasi.setY(this->hareketiBitirmeNoktasi.y());
    update();

}

void OpenGL::wheelEvent(QWheelEvent *event)
{
    QPoint numPixels = event->pixelDelta();
    QPoint numDegrees = event->angleDelta() / 10;


    mercek += (numDegrees.y() / 8) *0.01f;
    update();


    qDebug()<<numDegrees;
}

void OpenGL::initializeGL()
{

    initializeOpenGLFunctions();

    glClearColor(0.1,0.1,0.1,1);

    DegerleriAl();
}

void OpenGL::resizeGL(int h, int w)
{

}

void OpenGL::DegerleriAl()
{
    list =txt.Read("C:/Users/Casper/Desktop/GeoEtrim_C-_2020-master/Gokturk_2_Karaman_L1_0.txt");
}

void OpenGL::paintGL()
{
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glGetDoublev(GL_MODELVIEW_MATRIX, model);
    glGetDoublev(GL_PROJECTION_MATRIX, proj);
    glGetIntegerv(GL_VIEWPORT, view);

    glOrtho(-KonumX - (Genislik / 2.0), -KonumX + ( Genislik / 2.0), -KonumY - (Yukseklik / 2.0), -KonumY + (Yukseklik / 2.0), -(1000 * Genislik) / 2.0, (1000 * Genislik) / 2.0);
    glViewport(0, 0, Genislik,Yukseklik);

    glRotated(45,0,0,0);

    glScaled(mercek,mercek,4.0);

    glColor3d(1,1,1);

    for(int i=0;i<list.count();i++)
    {
      glBegin(GL_QUADS);
      glVertex3f(list[i][2].toFloat() - 50 , list[i][3].toFloat() - 50,200);
      glVertex3f(list[i][2].toFloat() + 50, list[i][3].toFloat()- 50,200);
      glVertex3f(list[i][2].toFloat() + 50 , list[i][3].toFloat() + 50,200);
      glVertex3f(list[i][2].toFloat() - 50, list[i][3].toFloat()+ 50,200);
      glEnd();
    }
}

