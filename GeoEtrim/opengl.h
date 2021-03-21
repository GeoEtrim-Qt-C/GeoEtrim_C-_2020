#ifndef OPENGL_H
#define OPENGL_H

#include "QOpenGLWidget"
#include "QOpenGLFunctions"
#include "GL/gl.h"
#include "GL/glu.h"
#include <QMouseEvent>
#include <QTimer>
#include <QVector3D>
#include <txtread.h>

class OpenGL:public QOpenGLWidget,public QOpenGLFunctions
{
public:
    OpenGL(QWidget *parent = nullptr);

    txtRead txt;



protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void wheelEvent(QWheelEvent *event);

private:


    QPoint hareketeBaslamaNoktasi;
    QPoint hareketiBitirmeNoktasi;

    float KonumX = 0;
    float KonumY = 0;
    float Genislik = 500;
    float Yukseklik = 500;
    float mercek = 0.025f;

    QList<QStringList>list;


    void DegerleriAl();
protected:

    void initializeGL()override;
    void resizeGL(int h,int w)override;
    void paintGL()override;


};

#endif // OPENGL_H
