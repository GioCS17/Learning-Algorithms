
#include "PerceptronAlgorithm.h"
PerceptronAlgorithm::PerceptronAlgorithm(const char *pathFile, char separator,
                                         const double& lRate=0.1,const double& t=0.3,const int neurons=2)
        :learningRate(lRate),threshold(t),separator(separator){
    loadData(pathFile);
    int cantattributes=listElements.back().getAttributes().size();
    for (int i = 0; i < neurons; ++i) {
        std::vector<double> weightaux(cantattributes,0.0);
        weights.push_back(weightaux);
    }
}

PerceptronAlgorithm::~PerceptronAlgorithm() {}

void PerceptronAlgorithm::loadData(const char *pathFile) {
    std::string cad=pathFile;
    std::ifstream file(cad);

    std::string row,var;
    while(getline(file,row)){
        Element newelement(row,separator);
        listElements.push_back(newelement);
    }
    file.close();

}

void PerceptronAlgorithm::printListElements() {
    for(Element x:listElements)
        std::cout<<x.getClassifier()<<std::endl;
}

void PerceptronAlgorithm::insertAttemptElement(std::string testElementCad) {
    testElement.insertAttributes(testElementCad,separator);
    std::cout<<testElement.getClassifier()<<std::endl;
}

void PerceptronAlgorithm::training(unsigned int maxIterations) {
    if (!maxIterations)
        throw std::invalid_argument("The maximum number of iterations cannot be 0.");


    unsigned iterations(0);

    while(iterations<=maxIterations){
        iterations++;
        int cantError(0);

        for(auto &element:listElements){

            std::pair<bool,bool> output=learning(element);
            bool expected_bit1=atoi(element.getClassifier().c_str())%2;
            bool expected_bit2=atoi(element.getClassifier().c_str())/2;

            if(output.first!=expected_bit1 && output.second!=expected_bit2)
                cantError++;
        }
        if(!cantError)
            break;

    }
}
std::pair<bool,bool> PerceptronAlgorithm::learning(Element&elemet) {

    std::pair<bool,bool> result=getresult(elemet.getAttributes());
    bool expected_bit1=atoi(elemet.getClassifier().c_str())%2;
    bool expected_bit2=atoi(elemet.getClassifier().c_str())/2;


    if(result.first!=expected_bit1 && result.second!=expected_bit2){
        double error1 = expected_bit1 - result.first;
        double error2 = expected_bit2 - result.second;
        for (int i = 0; i < weights[0].size(); i++) {
            weights[0][i] += learningRate* error1 * elemet.getAttributes()[i];
        }

        for (int i = 0; i < weights[1].size(); i++) {
            weights[1][i] += learningRate* error2 * elemet.getAttributes()[i];
        }

    }
    return result;

}

std::pair<bool,bool> PerceptronAlgorithm::getresult(const std::vector<double> &inputs)
{
    /*if (inputs.size() != cantattributes)
        throw std::invalid_argument("Invalid number of inputs. Expected: "
                                    + weights.begin()->size());
      */

     bool bit1=dotProduct(inputs, weights[0])>threshold;
     bool bit2=dotProduct(inputs, weights[1])>threshold;

    return std::make_pair(bit1,bit2);
}

double PerceptronAlgorithm::dotProduct(const std::vector<double> &v1, const std::vector<double> &v2)
{

    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);}

void PerceptronAlgorithm::printWeights() {
    for(auto x:weights){
        for(auto y:x){
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
}

void PerceptronAlgorithm::getprediction(std::string testElementCad) {
    testElement.insertAttributes(testElementCad,separator);
    std::pair<bool,bool> t=getresult(testElement.getAttributes());

    std::cout<<"Value Real::"<<testElement.getClassifier()<<std::endl;
    int result = t.first+t.second*2;
    std::cout<<"Value Teorico::"<<result <<std::endl;
    std::cout<<"::Comentarios::"<<std::endl;

    switch (result){
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
    std::cout<<std::endl;
}