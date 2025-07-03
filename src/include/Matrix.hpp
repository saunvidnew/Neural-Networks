#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <vector>
using namespace std;

class Matrix{
    private:
    int numRows;
    int numCols;

    vector <vector<double>> values;

    public:
    Matrix(int numRows, int numCols, bool isRandom);

    Matrix *transpose();

    double genrateRandomNo();
    double getNumRows(){
        return this->numRows;
    }
    double getNumCols(){
        return this->numCols;
    }
    void printToConsole();

    void setVal(int r,int c, double v);
    double getVal(int r, int c);



};

#endif