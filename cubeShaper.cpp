#include "cubeShaper.hpp"
#include <iostream>
using namespace std;

void CubeShaper::initializer(float x, float y, float z)
{
     this->dimX = x;
     this->dimY = y;
     this->dimZ = z;
     this->Xmax = this->dimX / 2.0;
     this->Ymax = this->dimY;
     this->Zmax = this->dimZ / 2.0;
     this->Xmin = -Xmax;
     this->Ymin = -Ymax;
     this->Zmin = -Zmax;
}

void CubeShaper:: draw()
{
     float xmax = this->Xmax;
     float xmin = this->Xmin;
     float ymax = this->Ymax;
     float ymin = this->Ymin;
     float zmax = this->Zmax;
     float zmin = this->Zmin;
     glBegin(GL_QUADS);
          glVertex3f(xmin,ymax,zmax);
          glVertex3f(xmin,ymin,zmax);
          glVertex3f(xmax,ymin,zmax);
          glVertex3f(xmax,ymax,zmax);
          //back
          glVertex3f(xmin,ymax,zmin);
          glVertex3f(xmax,ymax,zmin);
          glVertex3f(xmax,ymin,zmin);
          glVertex3f(xmin,ymin,zmin);
          //right
          glVertex3f(xmax,ymax,zmax);
          glVertex3f(xmax,ymin,zmax);
          glVertex3f(xmax,ymin,zmin);
          glVertex3f(xmax,ymax,zmin);
          //left
          glVertex3f(xmin,ymax,zmax);
          glVertex3f(xmin,ymax,zmin);
          glVertex3f(xmin,ymin,zmin);
          glVertex3f(xmin,ymin,zmax);
          //top
          glVertex3f(xmin,ymax,zmax);
          glVertex3f(xmax,ymax,zmax);
          glVertex3f(xmax,ymax,zmin);
          glVertex3f(xmin,ymax,zmin);
          //bottom
          glVertex3f(xmin,ymin+0.2,zmax);
          glVertex3f(xmax,ymin+0.2,zmax);
          glVertex3f(xmax,ymin+0.2,zmin);
          glVertex3f(xmin,ymin+0.2,zmin);
     glEnd();
}
