
#include "LinearRegression.hpp"

int main(int argc, char const *argv[])
{
    Point p1 = Point(2, 13495);
    Point p2 = Point(2, 16500);
    Point p3 = Point(4, 17710);
    Point p4 = Point(4, 17710);
    Point p5 = Point(2, 16430);
    Point p6 = Point(4, 16925);
    Point p7 = Point(2, 7957);

    Data dataset = Data();
    dataset.addPoint(p1);
    dataset.addPoint(p2);
    dataset.addPoint(p3);
    dataset.addPoint(p4);
    dataset.addPoint(p5);
    dataset.addPoint(p6);
    dataset.addPoint(p7);

    cout << dataset << endl;

    LinearRegression lin_reg = LinearRegression(dataset.getMean(0),
                                                dataset.getMean(1), dataset.getVariance(0),
                                                dataset.getVariance(1), dataset.getCovariance());
    cout << lin_reg << endl;
    cout << "Prediction 2 : " << lin_reg.predict(2) << endl;
    return 0;
}
