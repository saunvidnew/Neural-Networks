#include "include/Matrix.hpp"
#include <random>
Matrix::Matrix(int numRows, int numCols, bool isRandom){
    this->numRows=numRows;
    this->numCols=numCols;
    for(int i=0;i<numRows;i++){
        vector<double> colValues;
        for(int j=0;j<numCols;j++){
            double r=0.00;
            if(isRandom){
                r=this->generateRandomNo();
            }
            colValues.push_back(r);
        }
        values.push_back(colValues);
    }

};

double Matrix::generateRandomNo(){
    std::random_device rd;               // seed
    std::mt19937 gen(rd());              // Mersenne Twister engine
    std::uniform_int_distribution<> dist(0.1, 1.0); // range: 0.1 to 1

    double randomNumber = dist(gen);
    return randomNumber;
    

}

void Matrix::printToConsole(){
    int numRows=this->getNumRows();
    int numCols=this->getNumCols();

    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            cout <<this->values[i][j] << "\t";
        }
        cout<<endl;
    }
}

void Matrix::setVal(int r, int c, double v){
    this->values[r][c]=v;

}

double Matrix::getVal(int r, int c){
    return this->values[r][c];
}

Matrix * Matrix::transpose(){
    Matrix *m= new Matrix(this->numCols,this->numRows, false);
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            m->setVal(j,i,this->getVal(i,j));

        }

    }
    
    return m;
}

