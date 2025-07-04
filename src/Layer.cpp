#include "include/Layer.hpp"

Matrix *Layer::matrixifyVals(){
    Matrix *m=new Matrix(1, this->neurons.size(), false);
    for(int i=0; i<this->neurons.size(); i++){
        m->setVal(0, i, this->neurons[i]->getVal());
        
    }
    return m;

}

Matrix *Layer::matrixifyActivatedVals(){
    Matrix *m=new Matrix(1, this->neurons.size(), false);
    for(int i=0; i<this->neurons.size(); i++){
        m->setVal(0, i, this->neurons[i]->getactivatedVal());
    }
    return m;
    
}

Matrix *Layer::matrixifyDerivedVals(){
    Matrix *m=new Matrix(1, this->neurons.size(), false);
    for(int i=0; i<this->neurons.size(); i++){
        m->setVal(0, i, this->neurons[i]->getderivedVal());
    }
    return m;
    
}

Layer::Layer(int size){
    this->size=size;

    for(int i=0;i<size;i++){
        Neuron *n=new Neuron(0.00);
        neurons.push_back(n);
    }
}

void Layer::setVal(int i, double v){
    this->neurons[i]->setVal(v);
}

Layer::~Layer() {
    for (Neuron* n : neurons) {
        delete n;
    }
}
