/*
TGD2151 Computer Graphics Fundamentals
Faculty of Computing & Informatics, Multimedia University
CGLab05.cpp
Objective: Lab05 on Points & Lines
*/
#include <GL/glut.h>

#include "planetX.hpp"
#include "bezier.hpp"
#include "cubeShaper.hpp"
#include "CGimageloader.hpp"
#include "sweep.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "utilities/Mesh.hpp"
#include "utilities/Extrusion.hpp"
#include "utilities/Loft.hpp"
#include "utilities/Replicate.hpp"
#include "utilities/Lathe.hpp"

using namespace planetX;

PlanetX::PlanetX()
{
//     velx = 1.0f;
//     vely = 10.0f;
//     velz = 0.0f;
     roty = 0.0f;

}


void PlanetX::tickTime(long int elapseTime)
{
     posx = 0.0f;
     float elapseTimeInSec = elapseTime / 1000.0f;
     posx += elapseTimeInSec * velx;
     posy += elapseTimeInSec * vely;
     for(int i = 0; i<360; i = i+50)
     {
          posx +=   elapseTimeInSec * cos(i*(3.142/180));
          roty += sin(i*(3.142/180));
          //posy += elapseTimeInSec * sin(i*(3.142/180));
     }

}

void PlanetX::draw()
{
     //Quadric object
     GLUquadricObj *pObj;
     pObj = gluNewQuadric();
     gluQuadricNormals(pObj, GLU_SMOOTH);

     glPushMatrix();
          glDisable(GL_CULL_FACE);
               glColor3f(1*0.5f,1*0.5f,1*0.5f);
               gluSphere(pObj, 15.0f, 24,12);
          glEnable(GL_CULL_FACE);
     glPopMatrix();

}

void PlanetX::drawRails()
{
     glDisable(GL_CULL_FACE);
          ///Left Rails
          glLineWidth(9.0);
          glColor3f(0.8f, 0.498039f,0.196078f);
          float radius = 15.0f;
          glPushMatrix();
               glTranslatef(0.0f,0.0f,-2.0f);
               glBegin(GL_LINE_LOOP);
               for(int i = 0; i<360;i++)
               {
                    float degree = i*(3.142/180);
                    glVertex2f(cos(degree)*radius,sin(degree)*radius);
               }
               glEnd();
          glPopMatrix();
          ///Right Rails
          glPushMatrix();
               glTranslatef(0.0f,0.0f,2.0f);
               glBegin(GL_LINE_LOOP);
               for(int i = 0; i<360;i++)
               {
                    float degree = i*(3.142/180);
                    glVertex2f(cos(degree)*radius,sin(degree)*radius);
               }
               glEnd();
          glPopMatrix();
          ///Middle Rails
          glPushMatrix();
               glBegin(GL_LINES);
               for(int i = 0; i<360;i=i+30)
               {
                    float degree = i*(3.142/180);
                    glVertex3f(cos(degree)*radius,sin(degree)*radius,-2.0f);
                    glVertex3f(cos(degree)*radius,sin(degree)*radius,2.0f);
               }
               glEnd();
          glPopMatrix();

     glEnable(GL_CULL_FACE);

}


void PlanetX::drawTrain()
{
     glPushMatrix();
          glTranslatef(posx,posy,posz);
          glRotatef(roty,0.0f,0.0f,1.0f);
          ///head of train
          glColor3f(0.73f,0.16f,0.96f);
          glPushMatrix();
               glTranslatef(0.0f,15.0f,0.0f);
               CubeShaper cubeshaper;
               cubeshaper.initializer(4,1.5f,3);
               cubeshaper.draw();
          glPopMatrix();
          ///top of head of train
          glColor3f(0.52f,0.37f,0.26f);
          GLUquadricObj *pObj;
          pObj = gluNewQuadric();
          gluQuadricNormals(pObj, GLU_SMOOTH);
          glDisable(GL_CULL_FACE);
               glPushMatrix();
                    glTranslatef(0.0f,18.5f,0.0f);
                    glRotatef(90.0,1.0f,0.0f,0.0f);
                    gluCylinder(pObj,1,1,2,26,13);
               glPopMatrix();
          glEnable(GL_CULL_FACE);

          ///2nd compartment
          glColor3f(0.35f,0.16f,0.14f);
          glPushMatrix();
               glTranslatef(-2.0f,15.0f,0.0f);
               CubeShaper cubeshaperLinker;
               cubeshaperLinker.initializer(1,1,1);
               glRotatef(90.0,0.0f,0.0f,1.0f);
               cubeshaperLinker.draw();
          glPopMatrix();
          glPushMatrix();
               glColor3f(0.73f,0.16f,0.96f);
               glTranslatef(-5.0f,15.0f,0.0f);
               cubeshaper.draw();
          glPopMatrix();
     glPopMatrix();

}
//class definition / implementation
void PlanetX::drawSpaceRide()
{
     glPushMatrix();
          glTranslatef(0.0f,14.0f,-1.0f);

     glPopMatrix();
}

void PlanetX::drawCups()
{
     MySweepSurface mysweepsurface;

     glColor3f(1.0f,1.0f,1.0f);
     mysweepsurface.draw();
     glPushMatrix();

     glPopMatrix();
}

void PlanetX::drawEyesOnVader()
{

}
