#include <vector>
#include <algorithm>
#include "Point.hpp"

class Data
{
private:
    /**
     * mean_x: mean of x
     * mean_y: mean of y
     * var_x: marginal variance of x
     * var_y: marginal variance of y
     * cov: the covariance
     * **/
    double mean_x, mean_y, var_x, var_y, cov;
    double reg_intercept, reg_coeff;

    vector<Point> m_points;

public:
    Data();
    ~Data();

    void addPoint(Point p);

    /**
     * Returns the mean of:
     *      if index == 0: x
     *      if index == 1: y
     *      otherwise index = index % 2
     * **/
    double getMean(int index);

    /**
     * Returns the variance of:
     *      if index == 0: x 
     *      if index == 1: y
     *      otherwise index = index % 2
     * **/
    double getVariance(int index);

    /**
     * Returns the covariance
     * **/
    double getCovariance();

    vector<Point> getData();


    friend ostream &operator<<(ostream &os, Data &d);
};

ostream &operator<<(ostream &os, Data &d);