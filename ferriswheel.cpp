/********************************************
Course : TGD2151 Computer Graphics Fundamentals
Session: Trimester 2, 2015/16
ID and Name #1 : 1141123928 Muhammad Asyraf bin Ibrahim
Contacts #1 : 013-4642899 asyzruffz@gmail.com
ID and Name #2 : IDOfStud2 OfficialNameOfStud2
Contacts #2 : PhoneNoOfStud2 EMailOfStud2
********************************************/

#include <GL/glut.h>
#include <cmath>
#include "planetX.hpp"
#include "CGLabmain.hpp"
#include "ferriswheel.hpp"

FerrisWheel::FerrisWheel()
{
    // Create and initialize quadric
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    rotateSpeed = 0.01f;

    bodyCol[0] = 1.0f;
    bodyCol[1] = 1.0f;
    bodyCol[2] = 1.0f;
    ringCol[0] = 1.0f;
    ringCol[1] = 1.0f;
    ringCol[2] = 1.0f;
}

FerrisWheel::~FerrisWheel()
{
    // Free the quadric object
    gluDeleteQuadric(pObj);
}

void FerrisWheel::draw()
{
    glDisable(GL_CULL_FACE);

    int carriageNo = 10;
    float wheelRadius = 20.0f;

    //drawCarriage();
    drawStand(wheelRadius);

    // Loop to draw rotating carriage
    glTranslatef( 0.0f, 18.8f + wheelRadius, 0.0f);
    for(int i = 0; i < carriageNo; i++)
    {
        glPushMatrix();
            glRotatef(rotateSpeed, 0.0f, 0.0f, 1.0f);
            glTranslatef( wheelRadius*cos( i*(2*3.14159f/carriageNo) ), wheelRadius*sin( i*(2*3.14159f/carriageNo) ), 0.0f);
            setCarriageColour((i%2)*1.0f, ((i+1)%2)*1.0f, (i%3%2)*1.0f);
            drawCarriage();
        glPopMatrix();
    }

    // Draw rings
    /*glPushMatrix();
        glTranslatef( 0.0f, 0.0f, -2.5f);
        glutSolidTorus(0.2f, wheelRadius+0.5f, 6, 24);
        glTranslatef( 0.0f, 0.0f,  5.0f);
        glutSolidTorus(0.2f, wheelRadius+0.5f, 6, 24);
    glPopMatrix();*/

    glEnable(GL_CULL_FACE);
}

void FerrisWheel::setCarriageColour(GLfloat r, GLfloat g, GLfloat b)
{
    bodyCol[0] = r;
    bodyCol[1] = g;
    bodyCol[2] = b;
}

void FerrisWheel::setRingColour(GLfloat r, GLfloat g, GLfloat b)
{
    ringCol[0] = r;
    ringCol[1] = g;
    ringCol[2] = b;
}

void FerrisWheel::drawCarriage()
{
    glPushMatrix();
        glRotatef(-rotateSpeed, 0.0f, 0.0f, 1.0f);
        glTranslatef( 0.0f, 2.5f, 0.0f);

        // Draw passengers
//        Alien passenger;
//        passenger.setHeadColour(1.0f, 0.0f, 0.0f);
//        passenger.setBodyColour(0.0f, 1.0f, 0.0f);
//
//        glPushMatrix();
//            glTranslatef( -1.0f, -5.0f, 0.0f);
//            passenger.draw();
//            glTranslatef( 2.0f, 0.0f, 0.0f);
//            passenger.draw();
//        glPopMatrix();

        // Draw carriage
        glPushMatrix();
            glTranslatef( 0.0f, 0.0f, 0.0f);
            glColor3f (bodyCol[0], bodyCol[1], bodyCol[2]);

            GLfloat vertices[][3] =
            { {-2.0f, 0.0f, -2.0f }, // vertex 0
              {-2.0f, 0.0f,  2.0f }, // vertex 1
              { 2.0f, 0.0f, -2.0f }, // vertex 2
              { 2.0f, 0.0f,  2.0f }, // vertex 3
              { 3.0f, -2.0f, -2.0f }, // vertex 4
              { 3.0f, -2.0f,  2.0f }, // vertex 5
              { 3.0f, -4.0f, -2.0f }, // vertex 6
              { 3.0f, -4.0f,  2.0f }, // vertex 7
              { 2.0f, -5.0f, -2.0f }, // vertex 8// front door
              { 2.0f, -5.0f,  2.0f }, // vertex 9
              {-2.0f, -5.0f, -2.0f }, // vertex 10
              {-2.0f, -5.0f,  2.0f }, // vertex 11
              {-3.0f, -4.0f, -2.0f }, // vertex 12
              {-3.0f, -4.0f,  2.0f }, // vertex 13
              {-3.0f, -2.0f, -2.0f }, // vertex 14
              {-3.0f, -2.0f,  2.0f }  // vertex 15
            };

            // carriage body
            glBegin(GL_QUAD_STRIP);
                for(int i = 0; i < 16; i++)
                    glVertex3fv(vertices[i]);
                glVertex3fv(vertices[0]);
                glVertex3fv(vertices[1]);
            glEnd();

            // front door
            glBegin(GL_QUAD_STRIP);
                glVertex3fv(vertices[4]);
                glVertex3fv(vertices[14]);
                glVertex3fv(vertices[6]);
                glVertex3fv(vertices[12]);
                glVertex3fv(vertices[8]);
                glVertex3fv(vertices[10]);
            glEnd();

            // back door
            glBegin(GL_QUAD_STRIP);
                glVertex3fv(vertices[15]);
                glVertex3fv(vertices[5]);
                glVertex3fv(vertices[13]);
                glVertex3fv(vertices[7]);
                glVertex3fv(vertices[11]);
                glVertex3fv(vertices[9]);
            glEnd();
        glPopMatrix();

    glPopMatrix();
}

void FerrisWheel::drawStand(float wheelRadius)
{
    wheelRadius += 3;

    glColor3f (ringCol[0], ringCol[1], ringCol[2]);
    glPushMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(pObj, 5.0f, 3.0f, 2.0f, 8, 2);
        glTranslatef( 0.0f, 0.0f, 2.0f);
        gluCylinder(pObj, 3.0f, 3.0f, 4.0f, 8, 2);
        glTranslatef( 0.0f, 0.0f, 4.0f);

        float r = 3.0f;
        for(int i = 0; i < 5; i++)
        {
            float incr = 0.8f * sin((i/4.0f) * (3.14159f/2));
            gluCylinder(pObj, r, 3.0f+incr, 1.0f, 8, 1);
            glTranslatef( 0.0f, 0.0f, 1.0f);
            r = 3.0f+incr;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef( 0.0f, 8.0f + wheelRadius + 2*r, 0.0f);
        glutSolidTorus(r, r + wheelRadius+0.5f, 12, 24);
    glPopMatrix();
}
