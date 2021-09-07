#include <iostream>
using namespace std;
#pragma once
class Point
{
private:
    double m_x, m_y;

public:
    Point(double x, double y);
    ~Point();

    // Getters
    double getX();
    double getY();

    /**
     * Returns
     *      if index == 0: m_x
     *      if index == 1: m_y
     *      otherwise index = index % 2
     * **/
    double getCoordinateByIndex(int index);

    // Operators
    Point operator+(Point point);
    Point operator-(Point point);
    Point operator*(Point point);

    Point operator*(double scalaire);
    Point operator*(int scalaire);

    // Friends
    friend Point operator*(double scalaire, const Point &p);
    friend Point operator*(int scalaire, const Point &p);
    friend ostream &operator<<(ostream &os, const Point &p);
};

Point operator*(double scalaire, const Point &p);
Point operator*(int scalaire, const Point &p);
ostream &operator<<(ostream &os, const Point &p);
