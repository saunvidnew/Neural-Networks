// src/main.cpp
#include <iostream>
#include "include/Neuron.hpp"
#include "include/Matrix.hpp"
#include "include/Neural_network.hpp"
using namespace std;

int main() {
   
    vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(3);

    vector<double> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    NeuralNetwork *nn= new NeuralNetwork(topology);
    nn->setCurrentInput(input);
    nn->feedForward();
    nn->printToConsole();

    delete nn;

    return 0;
}
