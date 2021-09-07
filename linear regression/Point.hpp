#include <iostream>
using namespace std;

class Point
{
private:
    double m_x, m_y;

public:
    Point(double x, double y);

    // Getters
    double *getPoint();
    double getX();
    double getY();

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
