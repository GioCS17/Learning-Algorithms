
#include "knnalgorithm.h"


knnalgorithm::knnalgorithm(int k, const char *pathFile,char separator) {

    this->separator=separator;
    loadData(pathFile);
    this->k=k;
}

knnalgorithm::~knnalgorithm() {}

void knnalgorithm::loadData(const char *pathFile) {

    std::string cad=pathFile;
    std::ifstream file(cad);

    std::string row,var;
    while(getline(file,row)){
        Element newelement(row,separator);
        listElements.push_back(newelement);
        classifiers.insert(newelement.getClassifier());
    }

    file.close();

}

void knnalgorithm::printListElements(){
    for(Element x:listElements)
        std::cout<<x.getClassifier()<<std::endl;
}


double knnalgorithm::getDistEuclidean(Element & e1, Element &e2) {
    double acum=0;
    for (int i = 0; i < e1.getAttributes().size(); ++i) {
        acum+=pow(e1.getAttributes()[i] -e2.getAttributes()[i],2);
    }
    return sqrt(acum);
}


std::string knnalgorithm::getclassifierElement() {
    if(!beacon)
        return "Necesita ingresar un elemento de prueba";

    if(!k%2){
        k--;
        if(k<=0)
            k=1;

    }
    long sizeListPatients=listElements.size();

    std::set<std::pair<double ,int>> dist_Elements;
    for (int i = 0; i < sizeListPatients; ++i) {
        double dist=getDistEuclidean(listElements[i],testElement);
        dist_Elements.insert(std::make_pair(dist,i));
    }


    std::vector<int> counters(classifiers.size());
    std::set<std::pair<double,int>>::iterator it;
    it=dist_Elements.begin();

    while(k--){
        std::string diagnosisPercent=listElements[it->second].getClassifier();
        auto itc=classifiers.begin();
        for (int i = 0; i < classifiers.size(); ++i) {
            if(*itc ==diagnosisPercent)
                counters[i]++;
            itc++;
        }

        it++;
    }
    int mayorDiagnosis=0, diagnosis=-1;

    for(int i=0;i<counters.size();i++){
        if(counters[i]>mayorDiagnosis){
            mayorDiagnosis=counters[i];
            diagnosis=i;
        }
    }
    /*
    std::cout<<std::endl;
    for(auto x:classifiers)
        std::cout<<x<<std::endl;
    std::cout<<std::endl;

    std::cout<<std::endl;
    for(auto x:counters)
        std::cout<<x<<std::endl;
    std::cout<<std::endl;
    */
    auto itc=classifiers.begin();
    while(diagnosis--)
        itc++;
    return *itc;
}

void knnalgorithm::insertAttemptElement(std::string testElementCad) {
    testElement.insertAttributes(testElementCad,separator);
    beacon=true;
    std::cout<<testElement.getClassifier()<<std::endl;
}

