#pragma once

#include <functional>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "VecMatMath.hpp"

class Transformable
{
public:
    void applyTransform(std::function<void()> drawCall);

    GLfloat getScale() const;
    GLfloat getRotateX() const;
    GLfloat getRotateY() const;
    GLfloat getRotateZ() const;
    GLfloat getTranslateX() const;
    GLfloat getTranslateY() const;
    GLfloat getTranslateZ() const;

    void setScale(const GLfloat &value);
    void setRotateX(const GLfloat &value);
    void setRotateY(const GLfloat &value);
    void setRotateZ(const GLfloat &value);
    void setTranslate(const vec3 &t);
    void setTranslateX(const GLfloat &value);
    void setTranslateY(const GLfloat &value);
    void setTranslateZ(const GLfloat &value);

    void resetTransformations();

private:
    GLfloat rotateX;
    GLfloat rotateY;
    GLfloat rotateZ;

    GLfloat translateX;
    GLfloat translateY;
    GLfloat translateZ;

    GLfloat scale;
};


