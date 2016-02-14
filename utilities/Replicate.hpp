/**
Replicate by path, Replicate.hpp

Co-Authors: Kah Loon, Bruce, IceBoy

@12/1/16

References: Lab Materials by Dr.Wong Ya Ping
            Loft Class by Hii Yong Lian
            OpenGL Utilities by Bruce

**/
#ifndef REPLICATE_HPP
#define REPLICATE_HPP

#include<vector>
#include "VecMatMath.hpp"
#include "Drawable.hpp"
#include "Mesh.hpp"
#include <cmath>
class Replicate
{
    public:
        Replicate();
        Replicate(const std::vector<vec3> &points, Drawable *picture);
        Replicate(const std::vector<vec3> &points, Drawable *picture, std::string rotateOrNot);
        void draw();
    private:
        std::vector<vec3> pointsObj;
        std::vector<vec3> plottedPoints;
        Drawable *drawable;
        std::string rotateOrNot = "Y";
        float radian;
        float degree;
        float axisValue;
        std::vector<vec3> axis;
};



#endif // REPLICATE_HPP
