
#ifndef PROJECTPOO2_KNNALGORITHM_H
#define PROJECTPOO2_KNNALGORITHM_H

#include <iostream>
#include <vector>
#include "../Element.h"
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <set>

class KnnAlgorithm {

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
    KnnAlgorithm(int, const char *,char);
    ~KnnAlgorithm();
    void printListElements();
    void getclassifierElement();
    void insertAttemptElement(std::string);
};


#endif //PROJECTPOO2_KNNALGORITHM_H
