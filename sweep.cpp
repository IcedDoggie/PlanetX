#include "sweep.hpp"
#include<iostream>
#include<cmath>

using namespace std;


void MySweepSurface::setup(const GLfloat* profilePoints,GLint numOfProfilePoints,GLfloat degreeStart,GLfloat degreeEnd,
GLfloat degreeStep )
{
     profilepoints = profilePoints;
     numofprofilepoints = numOfProfilePoints;
//     if (surfacepoints)
//          delete[] surfacepoints;

     numofverticallines = 1 + static_cast<int>(floor((degreeEnd - degreeStart)/degreeStep));
     numofsurfacepoints = numofprofilepoints* numofverticallines;

     surfacepoints = new GLfloat[3 * numofsurfacepoints];
     int surfptsindex = 0;
     GLfloat degree = degreeStart;
     for (int i=0; i<numofverticallines; ++i, degree+=degreeStep)
     {
          GLfloat radian = degree*3.142/180.0;
          GLfloat c = cos(radian);
          GLfloat s = sin(radian);
          GLfloat x,y,z;
          for (int j=0, profileindex=0; j<numofprofilepoints; ++j)
          {
               surfacepoints[surfptsindex] = c*profilepoints[profileindex]
               + s*profilepoints[profileindex+2];
               surfacepoints[surfptsindex+1] = profilepoints[profileindex+1];
               surfacepoints[surfptsindex+2] = -s*profilepoints[profileindex]
               + c*profilepoints[profileindex+2];
               profileindex += 3;
               surfptsindex += 3;
          }
     }
}

void MySweepSurface::draw()
{
     glDisable(GL_CULL_FACE);
     int index = 0;
     for (int i=0; i<numofverticallines-1; ++i)
     {
          glBegin(GL_QUAD_STRIP);
          for (int j=0; j<numofprofilepoints; ++j)
          {
               glVertex3fv( surfacepoints+index );
               glVertex3fv( surfacepoints+index+3*numofprofilepoints );
               index+=3;
          }
          glEnd();
     }
     glEnable(GL_CULL_FACE);
}
