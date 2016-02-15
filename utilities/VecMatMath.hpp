#pragma once

#include <cmath>
#include <algorithm>
#include <functional>
#include <array>
#include <vector>
#include <float.h>

typedef std::array<float, 3> vec3;
typedef std::array<float, 2> vec2;
typedef std::array<vec3, 3> mat3;

vec3 cross(const vec3 &a, const vec3 &b);
vec3 mult(const mat3& m, const vec3& a);
mat3 getRotationMatrix(vec3 axis, float rads);
mat3 getRotationMatrix(const vec3 &sourceNormal, const vec3 &targetNormal);
// find the directional vector of each vertex given a polyspline
std::vector<vec3> getDirections(const std::vector<vec3> &spline);

std::vector<vec3> generateSpline(float start, float finish, int segments,
                                 std::function<float(float)> zFunc = [](float z)->float { return 0; },
                                 std::function<float(float)> xFunc = [](float x)->float { return x; },
                                 std::function<float(float)> yFunc = [](float y)->float { return 0; });

std::vector<vec3> getCircle(float radius, int segments, float y = 0, float start = 0, float finish = 6.2831853);

template<typename T>
float dot(const T &a, const T &b)
{
    float res = 0;

    for (int i = 0; i < a.size(); i++) {
        res += (a[i] * b[i]);
    }

    return res;
}

template<typename T>
float magnitude(const T &a)
{
    float sumSquare = 0;

    for (auto &b : a) {
        sumSquare += (b*b);
    }

    return std::sqrt(sumSquare);
}

template<typename T, typename R = typename T::value_type>
T applyVecOp(const T &a, const T &b, std::function<R(const R &p, const R &q)> op)
{
    T c;
    for (int i = 0; i < c.size(); i++) {
        c[i] = op(a[i], b[i]);
    }

    return c;
}

template<typename T, typename R = typename T::value_type>
T add(const T &a, const T &b)
{
    return applyVecOp<T, R>(a, b, [](const R &p, const R &q)->R { return p + q; });
}

template<typename T, typename R = typename T::value_type>
T deduct(const T &a, const T &b)
{
    return applyVecOp<T, R>(a, b, [](const R &p, const R &q)->R { return p - q; });
}

template<typename T, typename R = typename T::value_type>
T mult(const T &a, const T &b)
{
    return applyVecOp<T, R>(a, b, [](const R &p, const R &q)->R { return p * q; });
}

template<typename T>
T unitVec(const T &a)
{
    T unitV;
    float mag = magnitude(a);

    for (int i = 0; i < unitV.size(); i++) {
        unitV[i] = a[i] / mag;
    }

    return unitV;
}

template<typename T>
T negative(const T &a)
{
    T neg;

    for (int i = 0; i < neg.size(); i++) {
        neg[i] = -a[i];
    }

    return neg;
}

template<typename T, typename R = typename T::value_type>
T findCenter(const std::vector<T> &pts)
{
    if (pts.size() == 0) return T();

    T minVec, maxVec;
    for (auto &f : minVec) f = FLT_MAX;
    for (auto &f : maxVec) f = FLT_MIN;

    for (auto &p : pts) {
        for (int i = 0; i < minVec.size(); i++) {
            minVec[i] = std::min(minVec[i], p[i]);
            maxVec[i] = std::max(maxVec[i], p[i]);
        }
    }

    return applyVecOp<T, R>(minVec, maxVec, [](const R &p, const R &q)->R { return (p + q) / 2; });
}
