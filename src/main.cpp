// src/main.cpp
#include <iostream>
#include "include/Neuron.hpp"
#include "include/Matrix.hpp"
using namespace std;

int main() {
    Neuron *n=new Neuron(98);

    Matrix *m= new Matrix(3,2,true);
    m->printToConsole();

    Matrix *mt= m->transpose();
    mt->printToConsole();
     
    return 0;
}
