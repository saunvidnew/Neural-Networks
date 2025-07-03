// src/main.cpp
#include <iostream>
#include "Neuron.hpp"
using namespace std;

int main() {
    Neuron *n=new Neuron(98);

    cout<< "Val: "<< n->getVal() <<endl;

    cout<< "Activated Val: "<< n->getactivatedVal() <<endl;
    cout<< "Derived Val: "<< n->getderivedVal() <<endl;
     
    return 0;
}
