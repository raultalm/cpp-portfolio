#include "Data.hpp"

class LinearRegression
{
private:
    double reg_intercept, reg_coeff;
    double determination_coeff, MSE;

public:
    LinearRegression(double mean_x, double mean_y, double var_x, double var_y, double cov);
    ~LinearRegression();

    /**
     * Returns the prediction made 
     * by linear regression (using the least square method)
     * **/
    double predict(double x);

    friend ostream &operator<<(ostream &os, const LinearRegression &reg);
};

ostream &operator<<(ostream &os, const LinearRegression &reg);