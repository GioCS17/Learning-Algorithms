#include <iostream>
#include "knnalgorithm.h"

using namespace std;

int main() {
    knnalgorithm newattempt(17, "../cleveland.dat",',');
    //newattempt.printListElements();
    // 53 1 4 130 182 0 0 148 0 0 -9 -9 -9 0
    //52 1 4 170 -9 0 0 126 1 1.5 2 -9 -9 2
    //55 1 4 145 248 0 0 96 1 2 2 -9 -9 3
    newattempt.insertAttemptElement("57.0, 1.0, 4.0, 165.0, 289.0, 1.0, 2.0, 124.0, 0.0, 1.0, 2.0, 3.0, 7.0, 4");

    /*element2(52,1,4,170,-9,0,0,126,1,1.5,2,-9,-9,2);
    element3(55,1,4,145,248,0,0,96,1,2,2,-9,-9,3);
   */
    cout<<newattempt.getclassifierElement()<<endl;


    return 0;
}