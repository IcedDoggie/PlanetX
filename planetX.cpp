/*
TGD2151 Computer Graphics Fundamentals
Faculty of Computing & Informatics, Multimedia University
CGLab05.cpp
Objective: Lab05 on Points & Lines
*/
#include <GL/glut.h>

#include "planetX.hpp"
#include "bezier.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "utilities/Mesh.hpp"
#include "utilities/Extrusion.hpp"
#include "utilities/Loft.hpp"
#include "utilities/Replicate.hpp"
#include "utilities/Lathe.hpp"

using namespace planetX;

void PlanetX::draw()
{
     //Quadric object
     GLUquadricObj *pObj;
     pObj = gluNewQuadric();
     gluQuadricNormals(pObj, GLU_SMOOTH);

     glPushMatrix();
          glDisable(GL_CULL_FACE);
               glColor3f(1*0.5f,1*0.5f,1*0.5f);
               gluSphere(pObj, 15.0f, 24, 12);
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




     glEnable(GL_CULL_FACE);

}

//class definition / implementation
