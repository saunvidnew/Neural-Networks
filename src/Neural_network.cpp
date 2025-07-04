#include "include/Neural_network.hpp"

void NeuralNetwork::setCurrentInput(vector<double> input){
    this->input=input;

    for(int i=0; i<input.size(); i++){
        this->layers[0]->setVal(i,input[i]);
    }
}

NeuralNetwork::NeuralNetwork(vector<int> topology){
    this->topologySize=topology.size();

    for(int i=0;i<topologySize;i++){
        Layer *l=new Layer(topology[i]);
        this->layers.push_back(l);
    }

    for(int i=0; i<(topologySize-1);i++){
        Matrix *m= new Matrix(topology[i], topology[i+1], true);

        this->weightMatrices.push_back(m);
    }
}

void NeuralNetwork::printToConsole(){
    for(int i=0; i<this->layers.size();i++){
        if(i==0){
            Matrix *m= this->layers[i]->matrixifyVals();
            m->printToConsole();
            delete m;

        }
        else{
            Matrix *m=this->layers[i]->matrixifyActivatedVals();
            m->printToConsole();
            delete m;
        }
    }
}

NeuralNetwork::~NeuralNetwork() {
    for (Layer* l : layers) {
        delete l;
    }

    for (Matrix* m : weightMatrices) {
        delete m;
    }
}
