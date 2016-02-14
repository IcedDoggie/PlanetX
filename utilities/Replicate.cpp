/**
Replicate by path, Replicate.cpp

Co-Authors: Kah Loon, Bruce, IceBoy

@12/1/16

References: Lab Materials by Dr.Wong Ya Ping
            Loft Class by Hii Yong Lian
            OpenGL Utilities by Bruce

**/

#include "Replicate.hpp"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <iostream>
#include <cmath>

Replicate::Replicate()
{

}

Replicate::Replicate(const std::vector<vec3> &points,Drawable *picture)
{
    //Initialized
    pointsObj = getDirections(points);
    plottedPoints = points;
    drawable =  picture;

    radian = 0;
}

Replicate::Replicate(const std::vector<vec3> &points,Drawable *picture,std::string rotateOrNot)
{
    //Initialized
    pointsObj = getDirections(points);
    plottedPoints = points;
    drawable =  picture;

    radian = 0;
}

void Replicate::draw()
{
    //Creating the spline
    glBegin(GL_LINES);
        glColor3f(0.0f,1.0f,0.0f);
        for(auto it=plottedPoints.begin();it!=plottedPoints.end();it++)
        {
            if(it+1 != plottedPoints.end())
            {
                glVertex3f((*it)[0],(*it)[1],(*it)[2]);
                glVertex3f((*(it+1))[0],(*(it+1))[1],(*(it+1))[2]);
            }
        }
    glEnd();


        for(int i = 0; i < plottedPoints.size(); i++)
        {
            glPushMatrix();
                radian = acos(dot({{ 0, 1,0 }}, pointsObj[i]));
                auto axis = (cross({{ 0, 1,0 }}, pointsObj[i]));

                //conversion from radian to degree
                degree = radian * (180.0/3.14159265);

                glTranslatef(plottedPoints[i][0], plottedPoints[i][1],plottedPoints[i][2]);
                if(rotateOrNot=="Y")
                {
                    glRotatef(degree,axis[0],axis[1],axis[2]);
                }
                drawable->draw();
            glPopMatrix();
        }

}
