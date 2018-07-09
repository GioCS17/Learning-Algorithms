#ifndef PROJECTPOO2_PERCEPTRONALGORITHM_H
#define PROJECTPOO2_PERCEPTRONALGORITHM_H

#include <iostream>
#include <vector>
#include <fstream>
#include "../Element.h"


class PerceptronAlgorithm {

private:
    std::vector<Element> listElements;
    Element testElement;
    double learningRate;
    double threshold;
    std::vector<std::vector<double>> weights;
    std::vector<double> faults;
    double dotProduct(const std::vector<double> &v1, const std::vector<double> &v2);
    std::pair<bool,bool> getresult(const std::vector<double> &);
public:
    PerceptronAlgorithm(const char *,char,const double&,const double&,int);
    ~PerceptronAlgorithm();
    void loadData(const char *);
    char separator;
    void printListElements();
    void insertAttemptElement(std::string);
    std::pair<bool,bool> learning(Element&);
    void getprediction(std::string);
    void training(unsigned int);
    void printWeights();
};




#endif //PROJECTPOO2_PERCEPTRONALGORITHM_H
