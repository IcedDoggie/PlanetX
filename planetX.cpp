/*
TGD2151 Computer Graphics Fundamentals
Faculty of Computing & Informatics, Multimedia University
CGLab05.cpp
Objective: Lab05 on Points & Lines
*/
#include <GL/glut.h>

#include "planetX.hpp"
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
               gluSphere(pObj, 4.0f, 24, 12);
          glEnable(GL_CULL_FACE);
     glPopMatrix();
}

//class definition / implementation
