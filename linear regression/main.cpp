/**
 * -> Details:
 *      Simple linear regression explained by the least squares method.
 *      The goal of this program isn't to program an efficient machine learning algorithm,
 *      but to play with the c++ language and some OOP principles, while doing something fun.
 * 
 *      Exceptions and errors aren't handeled, and this isn't the most accurate algorithm
 *      for doing predictions. Once again, this wasn't the goal of the exercise.
 * 
 * 
 * -> Compile: g++ -o lin_reg main.cpp Point.cpp Data.cpp LinearRegression.cpp
 * 
 * -> CSV file:
 *      Data about vehicles, comming from the website: https://archive.ics.uci.edu/ml/datasets/automobile
 *      First col: Horsepower
 *      Second col: Price
 * **/


#include "LinearRegression.hpp"
#include <string>
#include <fstream>
#include <sstream>


int main(int argc, char const *argv[])
{
    cout << "--> First example with some manual added points:" << endl;
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
    cout << "\tPrediction 2 : " << lin_reg.predict(3) << endl << endl;


    cout << "--> Let's try with an actual csv file:" << endl
         << "-> Enter the path and name of the file : ";
    string path;
    cin >> path; // Get the path

    Data csvDataset = Data();
    ifstream csvData;
    csvData.open(path);

    vector<double> data;
    // Read data from csv file
    while(csvData.good()){
        string line;
        while(getline(csvData, line)){ // Read full line
            stringstream ss(line);
            while(getline(ss, line, ',')) // Split
                data.push_back(stod(line)); // Have the two entities
        }
    }

    // Create points and add them to the dataset
    for (auto i = data.begin(); i != data.end(); i+=2){
        csvDataset.addPoint(Point(*i, *(i+1)));
    }

    cout << csvDataset << endl;

    LinearRegression lin_reg_csv = LinearRegression(csvDataset.getMean(0),
                                                csvDataset.getMean(1), csvDataset.getVariance(0),
                                                csvDataset.getVariance(1), csvDataset.getCovariance());

    cout << lin_reg_csv << endl;
    cout << "\tPrediction x = 93 : " << lin_reg_csv.predict(93) << endl << endl;

    return 0;
}
