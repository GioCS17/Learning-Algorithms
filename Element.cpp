//
// Created by gante07 on 6/21/18.
//

#include "Element.h"

Element::Element(){}
Element::Element(std::string & attributesString,char& separator) {

    std::istringstream srow(attributesString);
    std::string var;
    std::vector<std::string> attributesList;
    while(getline(srow,var,separator))
        attributesList.push_back(var);

    for (int i = 0; i < attributesList.size()-1; ++i)
        attributes.push_back(atof(attributesList[i].c_str())) ;

    classifier=attributesList[attributesList.size()-1];
}
Element::~Element() {}

const std::vector<double> &Element::getAttributes() const {
    return attributes;
}

void Element::setAttributes(const std::vector<double> &attributes) {
    Element::attributes = attributes;
}

const std::string &Element::getClassifier() const {
    return classifier;
}

void Element::setClassifier(const std::string &classifier) {
    Element::classifier = classifier;
}

void Element::insertAttributes(std::string & attributesString,char& separator) {

        std::istringstream srow(attributesString);
        std::string var;
        std::vector<std::string> attributesList;
        while(getline(srow,var,separator))
            attributesList.push_back(var);

        for (int i = 0; i < attributesList.size()-1; ++i)
            attributes.push_back(atof(attributesList[i].c_str())) ;

        classifier=attributesList[attributesList.size()-1];

}