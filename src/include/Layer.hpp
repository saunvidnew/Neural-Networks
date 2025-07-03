#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <iostream>
#include "Neuron.hpp"
#include <vector>

using namespace std;

class Layer{
    private:
        int size;
        vector<Neuron *> neurons;
    public:
        Layer(int size);

};


#endif