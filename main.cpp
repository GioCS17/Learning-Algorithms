#include <iostream>
#include "NN/Knn/KnnAlgorithm.h"
#include "NN/Perceptron/PerceptronAlgorithm.h"
#include "NN/BackPropagation2/Backpropagation2.h"
using namespace std;

int main() {

    //Prueba KNNALGORITHM
    cout<<"-----------------------------------"<<endl;
    cout<<"-------Prueba como KNNAlgorithm------"<<endl;
    cout<<"-----------------------------------"<<endl;
    KnnAlgorithm newattempt(17, "../cleveland.dat",',');
    newattempt.insertAttemptElement("57.0, 1.0, 4.0, 165.0, 289.0, 1.0, 2.0, 124.0, 0.0, 1.0, 2.0, 3.0, 7.0, 4");
    newattempt.getclassifierElement();


    cout<<endl;

    //Prueba Perceptron
    cout<<"-----------------------------------"<<endl;
    cout<<"-------Prueba como Perceptron------"<<endl;
    cout<<"-----------------------------------"<<endl;

    PerceptronAlgorithm perceptronAttemp("../cleveland.dat",',',0.1,0.3,2);
    perceptronAttemp.training(10000);
   // perceptronAttemp.printWeights();

    perceptronAttemp.getprediction("59.0, 1.0, 4.0, 164.0, 176.0, 1.0, 2.0, 90.0, 0.0, 1.0, 2.0, 2.0, 6.0, 3");
    perceptronAttemp.getprediction("44.0, 1.0, 2.0, 130.0, 219.0, 0.0, 2.0, 188.0, 0.0, 0.0, 1.0, 0.0, 3.0, 0");
    perceptronAttemp.getprediction("54.0, 1.0, 4.0, 120.0, 188.0, 0.0, 0.0, 113.0, 0.0, 1.4, 2.0, 1.0, 7.0, 2");

    //perceptronAttemp.printListElements();



    Backpropagation2 bk;
    //bk.all();

    return 0;
}