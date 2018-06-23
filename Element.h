//
// Created by gante07 on 6/21/18.
//

#ifndef PROJECTPOO2_ELEMENT_H
#define PROJECTPOO2_ELEMENT_H

#include <vector>
#include <string>
#include <sstream>

class Element {
private:
    std::vector<double> attributes;
    std::string classifier;

public:
    Element();
    Element(std::string&,char&);
    ~Element();
    const std::vector<double> &getAttributes() const;
    void setAttributes(const std::vector<double> &attributes);
    const std::string &getClassifier() const;
    void setClassifier(const std::string &classifier);
    void insertAttributes(std::string&,char&);
};


#endif //PROJECTPOO2_ELEMENT_H
