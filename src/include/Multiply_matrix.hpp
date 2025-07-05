#ifndef _Multiply_matrix_HPP_
#define _Multiply_matrix_HPP_

#include <iostream>
#include <vector>
#include <assert.h>
#include "Matrix.hpp"

using namespace std;

class MultiplyMatrix{
    public:
    MultiplyMatrix(Matrix *a, Matrix *b);
    Matrix *execute();
    ~MultiplyMatrix();

    private:
    Matrix *a;
    Matrix *b;
    Matrix *c;

};

#endif