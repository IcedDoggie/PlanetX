/********************************************
Course : TGD2151 Computer Graphics Fundamentals
Session: Trimester 2, 2015/16
ID and Name #1 : 1141123928 Muhammad Asyraf bin Ibrahim
Contacts #1 : 013-4642899 asyzruffz@gmail.com
ID and Name #2 : IDOfStud2 OfficialNameOfStud2
Contacts #2 : PhoneNoOfStud2 EMailOfStud2
********************************************/

#include <GL/glut.h>
#include <iostream>
#include "alien.hpp"

Alien::Alien()
{
    headCol[0] = 1.0f;
    headCol[1] = 1.0f;
    headCol[2] = 1.0f;

    bodyCol[0] = 1.0f;
    bodyCol[1] = 1.0f;
    bodyCol[2] = 1.0f;
}

void Alien::draw()
{
    glEnable(GL_CULL_FACE);

    //Quadric Object
    GLUquadricObj *pObj;

    //create and initialize quadric
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
        glRotatef(-90.f, 1.0f, 0.0f, 0.0f);
        glTranslatef( 0.0f, 0.0f, 0.0f);
        glColor3f (bodyCol[0], bodyCol[1], bodyCol[2]);
        gluCylinder(pObj, 0.5f, 0.5f, 3.0f, 8, 2);
        glTranslatef( 0.0f, 0.0f, 3.0f);
        gluDisk(pObj, 0.0f, 0.5f, 8, 2);
        glTranslatef( 0.0f, 0.0f, 0.5f);
        glColor3f (headCol[0], headCol[1], headCol[2]);
        gluSphere(pObj, 0.5f, 8, 6);
    glPopMatrix();

    //free the quadric object
    gluDeleteQuadric(pObj);

    glDisable(GL_CULL_FACE);
}

void Alien::setHeadColour(GLfloat r, GLfloat g, GLfloat b)
{
    headCol[0] = r;
    headCol[1] = g;
    headCol[2] = b;
}

void Alien::setBodyColour(GLfloat r, GLfloat g, GLfloat b)
{
    bodyCol[0] = r;
    bodyCol[1] = g;
    bodyCol[2] = b;
}
