#include "Point.hpp"

Point::Point(double x, double y) : m_x(x), m_y(y) {}

Point::~Point() {}

double Point::getX() { return m_x; }
double Point::getY() { return m_y; }

double Point::getCoordinateByIndex(int index)
{
    index = index % 2;
    return (index == 0) ? m_x : m_y;
}

Point Point::operator+(Point point)
{
    Point new_point = Point(m_x + point.getX(), m_y + point.getY());
    return new_point;
}

Point Point::operator-(Point point)
{
    Point new_point = Point(m_x - point.getX(), m_y - point.getY());
    return new_point;
}

Point Point::operator*(Point point)
{
    Point new_point = Point(m_x * point.getX(), m_y * point.getY());
    return new_point;
}

Point Point::operator*(double scalaire)
{
    Point new_point = Point(m_x * scalaire, m_y * scalaire);
    return new_point;
}

Point Point::operator*(int scalaire)
{
    Point new_point = Point(m_x * scalaire, m_y * scalaire);
    return new_point;
}

ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.m_x << ";" << p.m_y << ")";
    return os;
}

Point operator*(double scalaire, const Point &p)
{
    Point new_point = Point(p.m_x * scalaire, p.m_y * scalaire);
    return new_point;
}
Point operator*(int scalaire, const Point &p)
{
    Point new_point = Point(p.m_x * scalaire, p.m_y * scalaire);
    return new_point;
}