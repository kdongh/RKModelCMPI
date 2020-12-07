//
// Created by DongHoon Kim on 11/16/20.
//

#include <iostream>

//#include "modules/atomicUnit.h"
#include "complexNumber.h"
#include "basis.h"

int main(){

    std::cout<<"Test Out"<<std::endl;
    double testParameter[11];
    testParameter[0]=6; //NumberOfGrid
    testParameter[1]=0.01; //GridDistance
    testParameter[2]=5; //SiteDistnace
    testParameter[3]=5; //ElasticConstant
    testParameter[4]=5; //PotentialV
    testParameter[5]=1; //PotentialFreq
    testParameter[6]=0.1; //ParticleMass
    testParameter[7]=0.1; //PulseAmp
    testParameter[8]=0.1; //PulseFreq
    testParameter[9]=0.1; //PulseAveT
    testParameter[10]=0.1; //PulseDelay

    basis testBasis(0,testParameter);
    testBasis.hamiltonian();

}