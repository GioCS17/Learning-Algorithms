#include "totalActivationFunctions.h"

int totalActivationFunctions::scalarFunction(double const &n) {  return n>=0?1:0; }
int totalActivationFunctions::scalarSymmetricFunction(double const &n){ return n>=0?1:-1;}
double totalActivationFunctions::linealFunction(double const &n) {return n;}
double totalActivationFunctions::linealPositiveFunction(double const &n) {return n>=0?n:0;}
double totalActivationFunctions::linealSaturatedFunction(double const &n) {return n>1?1:n<0?0:n;}
double totalActivationFunctions::linealSaturatedSymmetricFunction(double const &n) { return n>1?1:n<-1?-1:n;}
double totalActivationFunctions::logarithmicSigmoidFunction(double const &n) {return 1.0/(1+exp(-n));}
double totalActivationFunctions::sigmoidHyperbolicTangentFunction(double const &n) {return tanh(n); }//(exp(n)-exp(-n))/(exp(n)+exp(-n));