//
// Created by DongHoon Kim on 11/16/20.
//

#ifndef RK_MPI_BASIS_H
#define RK_MPI_BASIS_H

#include <iostream>
#include <string>

#include <vector>
#include <map>

#include <cmath>

#include "complexNumber.h"

typedef std::map<std::string,double> SDMap_t;
typedef std::vector<complexNumber> CNVector_t;
typedef std::vector<double> REVector_t;

class basis {
private:
    int numberOfGrid;
    double gridDistance;
    double siteDistance;

    double elasticConstant;
    double potentialV;
    double potentialFreq;
    double particleMass;

    double pulseAmp;
    double pulseFreq;
    double pulseAveT;
    double pulseDelay;

    double timeAU;
    int basisInteger;

    SDMap_t parameter;
    REVector_t leftSpaceDifferenceSquare;
    REVector_t rightSpaceDifferenceSquare;

    CNVector_t waveFunctionIn;
    CNVector_t waveFunctionOut;

    CNVector_t leftWaveFunction;
    CNVector_t rightWaveFunction;

    CNVector_t momentumEnergy;

    REVector_t cosPotential;
    REVector_t strainPotential;
    REVector_t pulsePotential;

public:
    basis(int basisInteger, CNVector_t waveFunctionIn, CNVector_t leftWaveFunction, CNVector_t rightWaveFunction, double *parameterIn);
    basis(int basisInteger, double *parameterIn);//Initial Zero Basis

    void mapToparameter();

    void parameterTomap(double *parameter);
    void setCosPotential(int basisInteger);
    void setDistanceSquare();

    void setMomentumEnergy();
    void setStrainPotential(CNVector_t leftWaveFunction, CNVector_t rightWaveFunction);
    void setPulseInput(double timeAU);

    void hamiltonian();

    double totalPopulation(CNVector_t waveFunction);
    void resultToInput();

    CNVector_t CNVectorSum(CNVector_t one, CNVector_t two);
    CNVector_t CNVectorSum(CNVector_t one, REVector_t two);
    CNVector_t CNVectorSum(REVector_t one, CNVector_t two);
    CNVector_t CNVectorSum(REVector_t one, REVector_t two);

    REVector_t REVectorSum(REVector_t one, REVector_t two);

    CNVector_t returnWaveFunctionOut();
    void setLeftRightWaveFunction(CNVector_t left, CNVector_t right);


    void VPrint(REVector_t target){
        int vSize = target.size();
        for(int i0=0;i0<vSize;i0++){
            std::cout<<target[i0]<<" ";
        }
        std::cout<<std::endl;
    }
    void VPrint(CNVector_t target){
        int vSize = target.size();
        for(int i0=0;i0<vSize;i0++){
            if(target[i0].imagN()>=0){
                std::cout<<"("<<target[i0].realN()<<" + i"<<target[i0].imagN()<<") ";
            }
            else{
                std::cout<<"("<<target[i0].realN()<<" - i"<<-target[i0].imagN()<<") ";

            }
        }
        std::cout<<std::endl;
    }
};


#endif //RK_MPI_BASIS_H
