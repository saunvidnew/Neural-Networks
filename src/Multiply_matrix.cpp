#include "include/Multiply_matrix.hpp"

MultiplyMatrix::MultiplyMatrix(Matrix *a, Matrix *b){
    this->a=a;
    this->b=b;
    if(a->getNumCols()!=b->getNumRows()){
        cout<<"Matrix A column does not match matrix B row and hence cannot be multipled.";
    }
    this->c= new Matrix(a->getNumRows(), b->getNumCols(), false);

}

Matrix *MultiplyMatrix::execute(){
    for(int i=0;i<a->getNumRows();i++){
        for(int j=0;j<b->getNumCols();j++){
            for(int k=0;k<a->getNumCols();k++){
                double p=this->a->getVal(i,k) * this->b->getVal(k,j);
                double newVal= this->c->getVal(i,j)+p;
                this->c->setVal(i,j,newVal);
            }
        }
    }
    return this->c;
}

MultiplyMatrix::~MultiplyMatrix(){
    
}