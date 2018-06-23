
#ifndef PROJECTPOO2_KNNALGORITHM_H
#define PROJECTPOO2_KNNALGORITHM_H

#include <iostream>
#include <vector>
#include "Element.h"
#include <string>
#include <fstream>
#include <cmath>
#include <set>

class knnalgorithm {

private:
    std::vector<Element> listElements;
    Element testElement;
    std::set<std::string> classifiers;
    int k;
    bool beacon=false;
    double getDistEuclidean(Element&,Element&);
    void loadData(const char *);
    char separator;

public:
    knnalgorithm(int, const char *,char);
    ~knnalgorithm();
    void printListElements();
    std::string getclassifierElement();
    void insertAttemptElement(std::string);
};


#endif //PROJECTPOO2_KNNALGORITHM_H
