/********************************************
Course : TGD2151 Computer Graphics Fundamentals
Session: Trimester 2, 2015/16
ID and Name #1 : 1141123928 Muhammad Asyraf bin Ibrahim
Contacts #1 : 013-4642899 asyzruffz@gmail.com
ID and Name #2 : IDOfStud2 OfficialNameOfStud2
Contacts #2 : PhoneNoOfStud2 EMailOfStud2
********************************************/

#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include "CGLabmain.hpp"

class Object
{
public:
    Object(): timetick(0){}
    virtual void draw() = 0;
    virtual void tickTime(long int elapseTime){
        timetick += elapseTime;
    }
protected:
    long int timetick;
};

#endif // OBJECT_HPP_INCLUDED
