#ifndef SWEEP_HPP
#define SWEEP_HPP
#include <iostream>
#include "CGLabmain.hpp"

using namespace std;

class MySweepSurface
{
     public:
          MySweepSurface() { }
          ~MySweepSurface()
          {
               if (surfacepoints)
                    delete[] surfacepoints;
          }
               //note: size of profilePoints = 3*numOfProfilePoints
          void setup(const GLfloat* profilePoints,
          GLint numOfProfilePoints,
          GLfloat degreeStart,
          GLfloat degreeEnd,
          GLfloat degreeStep );
          void draw();

          const GLfloat* profilepoints;
          GLint numofprofilepoints;
          GLfloat *surfacepoints;
          GLint numofsurfacepoints;
          GLint numofverticallines;
};

#endif // SWEEP_HPP
