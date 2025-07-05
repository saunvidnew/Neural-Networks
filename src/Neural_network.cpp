#include "include/Neural_network.hpp"
#include "include/Multiply_matrix.hpp"

void NeuralNetwork::setCurrentInput(vector<double> input){
    this->input=input;

    for(int i=0; i<input.size(); i++){
        this->layers[0]->setVal(i,input[i]);
    }
}

NeuralNetwork::NeuralNetwork(vector<int> topology){
    this->topologySize=topology.size();
    this->topology=topology;

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

void NeuralNetwork::feedForward() {
  
    for (int i = 1; i < topologySize; i++) {
        // Get activated values from previous layer (1 × N)

        Matrix *prevActivated = layers[i - 1]->matrixifyActivatedVals();
        // Get weight matrix for current connection (N × M)
        Matrix *weightMatrix = weightMatrices[i - 1];

        // Transpose weight matrix to make dimensions (M × N)
        Matrix *transposed = weightMatrix->transpose();
        // Multiply transposed weights with prev layer activations
        MultiplyMatrix mm(prevActivated, weightMatrix);
        Matrix *z = mm.execute(); // z is (1 × M)
        // Set result into current layer
        for (int j = 0; j < topology[i]; j++) {
            double val = z->getVal(0, j);
            layers[i]->setVal(j, val);  // Neuron activates internally
        }

        // Clean up
        delete prevActivated;
        delete transposed;
        delete z;
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
