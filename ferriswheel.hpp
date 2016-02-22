/********************************************
Course : TGD2151 Computer Graphics Fundamentals
Session: Trimester 2, 2015/16
ID and Name #1 : 1141123928 Muhammad Asyraf bin Ibrahim
Contacts #1 : 013-4642899 asyzruffz@gmail.com
ID and Name #2 : IDOfStud2 OfficialNameOfStud2
Contacts #2 : PhoneNoOfStud2 EMailOfStud2
********************************************/

#ifndef FERRISWHEEL_HPP_INCLUDED
#define FERRISWHEEL_HPP_INCLUDED

#include <iostream>

using namespace std;

class FerrisWheel
{
public:
    FerrisWheel();
    ~FerrisWheel();
    void draw();
    void setRingColour(GLfloat r, GLfloat g, GLfloat b);
private:
    GLfloat bodyCol[3];
    GLfloat ringCol[3];
    GLUquadricObj *pObj;
    float rotateSpeed;
    void drawCarriage();
    void setCarriageColour(GLfloat r, GLfloat g, GLfloat b);
    void drawStand(float wheelRadius);
};

#endif // FERRISWHEEL_HPP_INCLUDED
