#ifndef MyBezierLine_HPP
#define MyBezierLine_HPP
#include "CGLabmain.hpp"


using namespace std;

class MyBezierLine
{
     public:
          MyBezierLine() { }
          ~MyBezierLine() { }
          void setup(const GLfloat* controlPoints,
          GLint uOrder);
          void draw(GLenum draw_mode = GL_LINE,GLint ures = 100); //or GL_POINT
          void drawControlPoints();
     private:
          GLint uorder;
          const GLfloat* controlpoints;
};
#endif
