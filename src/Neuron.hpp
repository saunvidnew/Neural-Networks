#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>
using namespace std;

class Neuron{
    public:

    Neuron(double val);
    // fast sigmoid function
    void activate();

    void derive();

    // Getter
    double getVal(){
        return this->val;
    }
    double getactivatedVal(){
        return this->activatedVal;
    }
    double getderivedVal(){
        return this->derivedVal;
    }

    private:
    double val; // Current value of neuron eg:0.5,0.9
    double activatedVal; // activated/normalized version of val
    double derivedVal; // derivative of activated value



};


#endif
