#include "Data.hpp"
Data::Data() {}

Data::~Data() {}

void Data::addPoint(Point p)
{
    m_points.push_back(p);
}

double Data::getMean(int index)
{
    index = index % 2;
    double mean = 0.0;
    for (auto i = m_points.begin(); i != m_points.end(); i++)
    {
        mean += (i)->getCoordinateByIndex(index);
    }
    mean /= m_points.size();
    return mean;
}

double Data::getVariance(int index)
{
    index = index % 2;
    double sum = 0.0;
    for (auto i = m_points.begin(); i != m_points.end(); i++)
    {
        sum += ((i)->getCoordinateByIndex(index) * (i)->getCoordinateByIndex(index));
    }
    sum /= m_points.size();
    double mean = getMean(index);
    return sum - mean * mean;
}

double Data::getCovariance()
{
    double sum = 0.0;
    for (auto i = m_points.begin(); i != m_points.end(); i++)
    {
        sum += ((i)->getCoordinateByIndex(0) * (i)->getCoordinateByIndex(1));
    }
    sum /= m_points.size();
    double mean = getMean(0) * getMean(1);
    return sum - mean;
}

ostream &operator<<(ostream &os, Data &d)
{
    os << "-> Details about the dataset:" << endl
       << "\tmean_x : " << d.getMean(0) << endl 
       << "\tmean_y: "<< d.getMean(1) << endl 
       << "\tvariance_x: "<< d.getVariance(0) << endl
       << "\tvariance_y: "<< d.getVariance(1) << endl
       << "\tcovariance: "<< d.getCovariance() << endl;
    return os;
}