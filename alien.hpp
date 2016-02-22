/********************************************
Course : TGD2151 Computer Graphics Fundamentals
Session: Trimester 2, 2015/16
ID and Name #1 : 1141123928 Muhammad Asyraf bin Ibrahim
Contacts #1 : 013-4642899 asyzruffz@gmail.com
ID and Name #2 : IDOfStud2 OfficialNameOfStud2
Contacts #2 : PhoneNoOfStud2 EMailOfStud2
********************************************/

#ifndef ALIEN_HPP_INCLUDED
#define ALIEN_HPP_INCLUDED

#include <iostream>


class Alien
{
public:
    Alien();
    void draw();
    void setHeadColour(GLfloat r, GLfloat g, GLfloat b);
    void setBodyColour(GLfloat r, GLfloat g, GLfloat b);
private:
    GLfloat headCol[3];
    GLfloat bodyCol[3];
};

#endif // ALIEN_HPP_INCLUDED
