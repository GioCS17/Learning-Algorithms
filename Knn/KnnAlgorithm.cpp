
#include "KnnAlgorithm.h"


KnnAlgorithm::KnnAlgorithm(int k, const char *pathFile,char separator) {

    this->separator=separator;
    loadData(pathFile);
    this->k=k;
}

KnnAlgorithm::~KnnAlgorithm() {}

void KnnAlgorithm::loadData(const char *pathFile) {

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

void KnnAlgorithm::printListElements(){
    for(Element x:listElements)
        std::cout<<x.getClassifier()<<std::endl;
}


double KnnAlgorithm::getDistEuclidean(Element & e1, Element &e2) {
    double acum=0;
    for (int i = 0; i < e1.getAttributes().size(); ++i) {
        acum+=pow(e1.getAttributes()[i] -e2.getAttributes()[i],2);
    }
    return sqrt(acum);
}


void KnnAlgorithm::getclassifierElement() {
    if(!beacon)
        throw "Necesita ingresar un elemento de prueba";

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
    std::cout<<"El valor real es::"<<*itc<<std::endl;
    std::cout<<"::Comentarios::"<<std::endl;

    switch (atoi((*itc).c_str())){
        case 0:
            std::cout<<"Usted es una persona sana, piense siempre en come sano y haga ejercicio."<<std::endl;
            break;
        case 1:
            std::cout<<"Usted es una persona con una pequeña probabilidad de paro cardiaco de 25%\n"
                    "No se alto para preocuparse pero haga algunos cambios en su rutina diaria\n"
                    "Piense siempre en comer sano y haga ejercicio."<<std::endl;
            break;
        case 2:
            std::cout<<"Usted es una persona con una probabilidad considerable de paro cardiaco de 50%\n"
                    "Debe cambiar inmediatamente algunos habitos de su vida\n"
                    "Piense siempre en comer sano y haga ejercicio."<<std::endl;
            break;
        case 3:
            std::cout<<"Usted es una persona con una probabilidad alta de paro cardiaco de 75%\n"
                    "Debe cambiar inmediatamente algunos habitos de su vida y acudir a un centro de salud\n"
                    "Piense siempre en comer sano y haga ejercicio."<<std::endl;
            break;
        case 4:
            std::cout<<"Usted es una persona que podria padecer de paro cardiaco tiene una probabilidad de 100%\n"
                    "Debe cambiar inmediatamente algunos habitos de su vida y acudir a un centro de salud pronto\n"
                    "Piense siempre en comer sano y haga ejercicio."<<std::endl;

    }
}

void KnnAlgorithm::insertAttemptElement(std::string testElementCad) {
    testElement.insertAttributes(testElementCad,separator);
    beacon=true;
    std::cout<<"El valor teorico es::"<<testElement.getClassifier()<<std::endl;

}

