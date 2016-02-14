//
//  Loft.cpp
//  OpenGL-Utilities-XCODE
//
//  Created by Yong Lian Hii on 30/12/2015.
//  Copyright © 2015 Yong Lian Hii. All rights reserved.
//

#include "Loft.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <iostream>

Loft::Loft(const std::vector<vec2> &points, const std::vector<vec3> &path): points2d(points),path(path)
{
    init();
}
void Loft::init()
{
    directions = getDirections(path);
    for(int i = 0; i < path.size(); i++)
    {
        std::vector<vec3> row;
        points3d.push_back(row);
    }
    for(auto it = path.begin(); it != path.end(); it++)
    {
        long i = std::distance( path.begin(), it );
        mat3 rotationMatrix = getRotationMatrix( {{0,1,0}}, directions[i] );

        for(auto jt = points2d.begin(); jt != points2d.end(); jt++)
        {
            vec3 temp = mult( rotationMatrix, {{ (*jt)[0], 0,        (*jt)[1] }} );
            points3d[i].push_back(add(temp,  {{ (*it)[0], (*it)[1], (*it)[2] }}));
        }
    }
}
void Loft::draw()
{
    //Guideline for Loft
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    for (auto it = path.begin(); it != path.end(); it++) {
        if (( it + 1) != path.end()) {
        glVertex3f((*it)[0], (*it)[1], (*it)[2] );
        glVertex3f((*(it+1))[0], (*(it+1))[1], (*(it+1))[2] );
        }
    }
    glEnd();
    glPushMatrix();

    //Draw polygon over loft path
    for(auto it = points3d.begin(); it != points3d.end(); it++) {
        glBegin(GL_POLYGON);
        for(auto jt = (*it).begin(); jt != (*it).end(); jt++) {
            glVertex3f((*jt)[0], (*jt)[1], (*jt)[2]);
        }
        glEnd();

        if( ( it + 1) != points3d.end()) {
            for(auto jt = (*it).begin(); jt != (*it).end(); jt++) {
                long j = std::distance( (*it).begin(), jt );

                glBegin(GL_QUADS);
                glColor3f(1.0, 0.0, 0.0);
                glVertex3f((*jt)[0], (*jt)[1], (*jt)[2]);

                if ( (jt+1) != (*it).end() ) {
                    glVertex3f((*(jt+1))[0], (*(jt+1))[1], (*(jt+1))[2]);
                }else {
                    auto temp_it = (*it).begin();
                    glVertex3f ((*temp_it)[0], ((*temp_it)[1]), ((*temp_it)[2]));
                }

                auto next_point_it = (*(it + 1)).begin() + j;
                if ( (next_point_it+1) != (*(it + 1)).end() ) {
                    glVertex3f((*(next_point_it+1))[0], (*(next_point_it+1))[1], (*(next_point_it+1))[2]);
                }else {
                    auto temp_it = (*(it + 1)).begin();
                    glVertex3f ((*temp_it)[0], ((*temp_it)[1]), ((*temp_it)[2]));
                }
                glVertex3f((*next_point_it)[0], (*next_point_it)[1], (*next_point_it)[2]);
                glEnd();

            }
        }
    }
    glPopMatrix();

}
