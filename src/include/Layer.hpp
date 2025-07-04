#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <iostream>
#include "Neuron.hpp"
#include "Matrix.hpp"
#include <vector>

using namespace std;

class Layer{
    private:
        int size;
        vector<Neuron *> neurons;
    public:
        Layer(int size);
        void setVal(int i, double v);
        Matrix *matrixifyVals();
        Matrix *matrixifyActivatedVals();
        Matrix *matrixifyDerivedVals();
        ~Layer();

        

};


#endif