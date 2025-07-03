#include "Neuron.hpp"
#include <math.h>
//constructor

Neuron::Neuron(double val){
    this->val=val;
    activate();
    derive();
}

// Fast sigmoid function
void Neuron::activate(){
    this->activatedVal=this->val / (1 + abs(this->val));
}
// derivative of sigmoid function
void Neuron::derive(){
    this->derivedVal=this->activatedVal * (1-this->activatedVal);
}
