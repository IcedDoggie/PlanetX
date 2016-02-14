#include "Transformable.hpp"

void Transformable::applyTransform(std::function<void()> drawCall)
{
    glPushMatrix();
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    glTranslatef(translateX, translateY, translateZ);
    glScalef(scale, scale, scale);

    drawCall();
    glPopMatrix();
}

void Transformable::resetTransformations()
{
    rotateX
        = rotateY
          = rotateZ
            = translateX
              = translateY
                = translateZ = 0;
    scale = 1;
}

GLfloat Transformable::getScale() const
{
    return scale;
}

void Transformable::setScale(const GLfloat &value)
{
    scale = value;
}

GLfloat Transformable::getRotateX() const
{
    return rotateX;
}

void Transformable::setRotateX(const GLfloat &value)
{
    rotateX = value;

}
GLfloat Transformable::getRotateY() const
{
    return rotateY;
}

void Transformable::setRotateY(const GLfloat &value)
{
    rotateY = value;

}
GLfloat Transformable::getRotateZ() const
{
    return rotateZ;
}

void Transformable::setRotateZ(const GLfloat &value)
{
    rotateZ = value;
}

void Transformable::setTranslate(const vec3 &t)
{
    translateX = t[0];
    translateY = t[1];
    translateZ = t[2];
}

GLfloat Transformable::getTranslateX() const
{
    return translateX;
}

void Transformable::setTranslateX(const GLfloat &value)
{
    translateX = value;

}

GLfloat Transformable::getTranslateY() const
{
    return translateY;
}

void Transformable::setTranslateY(const GLfloat &value)
{
    translateY = value;

}
GLfloat Transformable::getTranslateZ() const
{
    return translateZ;
}

void Transformable::setTranslateZ(const GLfloat &value)
{
    translateZ = value;
}
