#include <iostream>
#include "bezier.hpp"

using namespace std;


void MyBezierLine::setup(const GLfloat* controlPoints,GLint uOrder)
{
     controlpoints = controlPoints;
     uorder = uOrder;
     //setup the bezier
     glMap1f(GL_MAP1_VERTEX_3, //to be generated data
     0.0f, //lower u range
     1.0f, //higher u range
     3, //u control point stride in array
     uorder, //order of u or number of u control point
     controlpoints); //the control points array
     //enabling bezier evaluator
     glEnable(GL_MAP1_VERTEX_3);
}

void MyBezierLine::draw(GLenum draw_mode, GLint ures)//GL_LINE or GL_POINT
{
     //setting the 1D grid map containing ures points
     //map to u range 0.0 - 1.0
     glMapGrid1f(ures, 0.0f, 1.0f);
     //evaluate the bezier surface
     glEvalMesh1(draw_mode, 0, ures);
}

void MyBezierLine::drawControlPoints()
{
     //draw the control points
     int index = 0;
     glBegin(GL_LINE_STRIP);
     for(int i=0; i < uorder; ++i)
     {
          glVertex3fv(controlpoints + index );
          index += 3;
     }
     glEnd();
}
