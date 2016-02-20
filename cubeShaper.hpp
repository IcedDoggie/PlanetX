
#ifndef cubeShaper_hpp
#define cubeShaper_hpp
#include <iostream>
#include "CGLabmain.hpp"
using namespace std;

class CubeShaper
{
     public:
          CubeShaper() {}  ;
          void initializer(float x, float y, float z);
          void draw();
     private:
          float dimX,dimY,dimZ;
          float Xmax, Xmin, Ymax, Ymin, Zmax, Zmin;
};
#endif
