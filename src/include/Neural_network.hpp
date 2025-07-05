#ifndef _Neural_network_HPP_
#define _Neural_network_HPP_

#include <iostream>
#include <vector>
#include "Matrix.hpp"
#include "Layer.hpp"

using namespace std;

class NeuralNetwork{
    public:
        NeuralNetwork(vector<int> topology);
        void setCurrentInput(vector<double> input);
        void printToConsole();
        ~NeuralNetwork();
        void feedForward();
    private:
        int topologySize;
        vector<int> topology;
        vector<Layer *> layers;
        vector<Matrix *> weightMatrices;
        vector<double> input;
      
        
};

#endif