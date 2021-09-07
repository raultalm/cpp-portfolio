#include "LinearRegression.hpp"
LinearRegression::LinearRegression(double mean_x, double mean_y, double var_x, double var_y, double cov)
{
    // Regression line eq
    reg_coeff = cov / var_x;
    reg_intercept = mean_y - reg_coeff * mean_x;

    // Calculate the Residual variance == MSE function
    determination_coeff = (cov * cov)/(var_x*var_y);
    MSE = var_y*(1-determination_coeff);
}

LinearRegression::~LinearRegression() {}

double LinearRegression::predict(double x)
{
    return reg_coeff*x + reg_intercept;
}

ostream &operator<<(ostream &os, const LinearRegression &reg)
{
    os << "-> Details about the linear regression:" << endl
       << "\tintercept : " << reg.reg_intercept << endl 
       << "\tcoefficient: "<< reg.reg_coeff << endl 
       << "\tf(x) = "<< reg.reg_coeff <<"*x + " << reg.reg_intercept << endl
       << "\tdetermination coefficient: "<< reg.determination_coeff << endl
       << "\tMSE: "<< reg.MSE << endl;
    return os;
}