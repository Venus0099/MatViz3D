#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QMatrix4x4>



class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void paintSphere(float radius, int numStacks, int numSlices);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setNumCubes(int numCubes);
    void setDistanceFactor(float factor);
    //void explodeCubes(int value);
    //void setColorDistanceFactor(float factor);

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    //void draw();

    int xRot;
    int yRot;
    int zRot;

    float distance;

    QPoint lastPos;
    QMatrix4x4 m_projection;
    int numCubes_;
    float distanceFactor=0.001;
    //float colordistanceFactor;

};

#endif // MYGLWIDGET_H
