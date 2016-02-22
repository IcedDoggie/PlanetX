/********************************************
Course : TGD2151 Computer Graphics Fundamentals
Session: Trimester 2, 2015/16
ID and Name #1 : 1141123928 Muhammad Asyraf bin Ibrahim
Contacts #1 : 013-4642899 asyzruffz@gmail.com
ID and Name #2 : IDOfStud2 OfficialNameOfStud2
Contacts #2 : PhoneNoOfStud2 EMailOfStud2
********************************************/

#ifndef CURVEPATH_HPP_INCLUDED
#define CURVEPATH_HPP_INCLUDED

#include <vector>
#include <cmath>
using namespace std;

#include "bezier.hpp"

#define PI 3.14159265

class CurvePath
{
public:
    CurvePath();
    void draw();
    void setPoints(GLfloat pt[], int pointNo);
    void viewControlPath(bool toggle);
    void setCurveColour(GLfloat r, GLfloat g, GLfloat b);
    void setControlLineColour(GLfloat r, GLfloat g, GLfloat b);
    void getPointOnPath(GLfloat &x, GLfloat &y, GLfloat &z, float t);
    void getDirectionOnPath(GLfloat &x, GLfloat &y, GLfloat &z, float t);
private:
    GLfloat curveCol[3];
    GLfloat lineCol[3];
    bool controlPathSwitch;
    vector<MyBezierLine> curves;
    GLfloat mid(GLfloat a, GLfloat b); // to calculate midpoint
};

#endif // CURVEPATH_HPP_INCLUDED
