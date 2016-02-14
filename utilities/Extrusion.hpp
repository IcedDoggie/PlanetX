#pragma once

#include <vector>
#include "VecMatMath.hpp"
#include "Drawable.hpp"

class Extrusion : public Drawable
{
public:
    Extrusion(const std::vector<vec2> &points, int depth = 1);

    void draw() override;

    void setDepth(const int d);
    int getDepth() const;

private:
    const std::vector<vec2> &points2d;
    int depth;
};
