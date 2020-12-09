//
// Created by DongHoon Kim on 11/16/20.
//

#include "basis.h"

basis::basis(int basisInteger, CNVector_t waveFunctionIn, CNVector_t leftWaveFunction, CNVector_t rightWaveFunction, double *parameterIn){

    parameterTomap(parameterIn);

    mapToparameter();

    basis::basisInteger = basisInteger;

    basis::waveFunctionIn = waveFunctionIn;
    setCosPotential(basisInteger);
}
basis::basis(int basisInteger, double *parameterIn){

    parameterTomap(parameterIn);

    mapToparameter();

    basis::basisInteger = basisInteger;

    complexNumber complexZero(0,1);
    for(int i0 = 0; i0< numberOfGrid;i0++){
        waveFunctionIn.push_back(complexZero);
        leftWaveFunction.push_back(complexZero);
        rightWaveFunction.push_back(complexZero);
    }
    setCosPotential(basisInteger);
}

void basis::mapToparameter() {

    basis::numberOfGrid = int(parameter.find("NumberOfGrid")->second);
    basis::gridDistance = parameter.find("GridDistance")->second;
    basis::siteDistance = parameter.find("SiteDistance")->second;
    basis::elasticConstant = parameter.find("ElasticConstant")->second;

    basis::potentialV = parameter.find("PotentialV")->second;
    basis::potentialFreq = parameter.find("PotentialFreq")->second;
    basis::particleMass = parameter.find("ParticleMass")->second;

    basis::pulseAmp = parameter.find("PulseAmp")->second;
    basis::pulseFreq = parameter.find("PulseFreq")->second;
    basis::pulseAveT = parameter.find("PulseAveT")->second;
    basis::pulseDelay = parameter.find("PulseDelay")->second;
}


void basis::parameterTomap(double *parameter){

    basis::parameter.insert(std::pair<std::string,double>("NumberOfGrid",parameter[0]));
    basis::parameter.insert(std::pair<std::string,double>("GridDistance",parameter[1]));
    basis::parameter.insert(std::pair<std::string,double>("SiteDistance",parameter[2]));

    basis::parameter.insert(std::pair<std::string,double>("ElasticConstant",parameter[3]));
    basis::parameter.insert(std::pair<std::string,double>("PotentialV",parameter[4]));
    basis::parameter.insert(std::pair<std::string,double>("PotentialFreq",parameter[5]));
    basis::parameter.insert(std::pair<std::string,double>("ParticleMass",parameter[6]));

    basis::parameter.insert(std::pair<std::string,double>("PulseAmp",parameter[7]));
    basis::parameter.insert(std::pair<std::string,double>("PulseFreq",parameter[8]));
    basis::parameter.insert(std::pair<std::string,double>("PulseAveT",parameter[9]));
    basis::parameter.insert(std::pair<std::string,double>("PulseDelay",parameter[10]));


}

void basis::setCosPotential(int basisInteger) {

    double potentialPerGrid;
    double insertTerm;
    for(int i0 = 0; i0<numberOfGrid;i0++){
        insertTerm = potentialFreq*(i0*gridDistance+(siteDistance+gridDistance*(numberOfGrid-1))*basisInteger);
        potentialPerGrid = potentialV*cos(insertTerm);

        cosPotential.push_back(potentialPerGrid);
    }

}

void basis::setDistanceSquare() {//It is in setStrainPotential

    double distance;
    for(int i0=0;i0<numberOfGrid;i0++){
        for (int i1 = 0;i1<numberOfGrid;i1++){
            distance = siteDistance + gridDistance * (numberOfGrid + i0 - i1 - 1);
            leftSpaceDifferenceSquare.push_back(elasticConstant*distance*distance/2);
            distance = siteDistance + gridDistance * (numberOfGrid - i0 + i1 - 1);
            rightSpaceDifferenceSquare.push_back(elasticConstant*distance*distance/2);
        }
    }
}

void basis::setStrainPotential(CNVector_t leftWaveFunction, CNVector_t rightWaveFunction){

    setDistanceSquare();
    double energy;
    for(int i0=0;i0<numberOfGrid;i0++){
        energy = 0;
        for(int i1=0;i1<numberOfGrid;i1++) {
            energy += leftSpaceDifferenceSquare[numberOfGrid*i0+i1] * leftWaveFunction[i1].absValue();
            energy += rightSpaceDifferenceSquare[numberOfGrid*i0+i1] * rightWaveFunction[i1].absValue();
        }
        strainPotential.push_back(energy);
    }

}

void basis::setMomentumEnergy() {
    complexNumber result;

    double divideFactor = 2*gridDistance;
    int endInteger = numberOfGrid-1;
    for(int i0=0;i0<numberOfGrid;i0++){
        if(i0==0){
            result=waveFunctionIn[1]/divideFactor;
        } else if(i0==endInteger){
            result=waveFunctionIn[endInteger-1]/(-divideFactor);
        } else{
            result=(waveFunctionIn[i0+1]-waveFunctionIn[i0-1]);
            result= result/divideFactor;
        }
        result = result*result;
        momentumEnergy.push_back(result/(2*particleMass));
    }
}

void basis::setPulseInput(double timeAU) {

    double pulseAmpPerTime;
    double delayedTime = timeAU - pulseDelay;
    pulseAmpPerTime = pulseAmp*cos(pulseFreq*delayedTime)*exp(-delayedTime*delayedTime/(pulseAveT*pulseAveT));

    for(int i0=0;i0<numberOfGrid;i0++){
        pulsePotential.push_back(pulseAmpPerTime);
    }
}

void basis::hamiltonian() {
    setMomentumEnergy();
    setStrainPotential(leftWaveFunction,rightWaveFunction);
    CNVector_t resultCNV;
    resultCNV = CNVectorSum(strainPotential,momentumEnergy);
    resultCNV = CNVectorSum(resultCNV,cosPotential);
    if(basisInteger==0){
        setPulseInput(timeAU);
        resultCNV = CNVectorSum(resultCNV,pulsePotential);
    }

    waveFunctionOut = resultCNV;
}

double basis::totalPopulation(CNVector_t waveFunction) {
    int size = waveFunction.size();
    double buff = 0;
    double sum = 0;

    for(int i0=0;i0<size;i0++){
        buff = waveFunction[i0].absValue();
        sum += buff*buff;
    }
    return sum;
}

/*                          */
//
// Vector Sum functions
//
/*                          */
CNVector_t basis::CNVectorSum(CNVector_t one, CNVector_t two){
    CNVector_t result;
    for(int i0=0;i0<numberOfGrid;i0++){
        result.push_back(one[i0]+two[i0]);
    }
    return result;
}

CNVector_t basis::CNVectorSum(CNVector_t one, REVector_t two){

    CNVector_t result;
    for(int i0=0;i0<numberOfGrid;i0++){
        result.push_back(one[i0]+two[i0]);
    }
    return result;
}

CNVector_t basis::CNVectorSum(REVector_t one, CNVector_t two){

    CNVector_t result;
    for(int i0=0;i0<numberOfGrid;i0++){
        result.push_back(one[i0]+two[i0]);
    }
    return result;
}

CNVector_t basis::CNVectorSum(REVector_t one, REVector_t two){//Real + Real -> Complex case

    CNVector_t result;
    for(int i0=0;i0<numberOfGrid;i0++){
        result.push_back(complexNumber(one[i0]+two[i0],0));
    }
    return result;
}

REVector_t basis::REVectorSum(REVector_t one, REVector_t two){
    REVector_t result;
    for(int i0=0;i0<numberOfGrid;i0++){
        result.push_back(one[i0]+two[i0]);
    }
    return result;
}


/*                          */
//
// Extra functions
//
/*                          */
CNVector_t basis::returnWaveFunctionOut(){
    return waveFunctionOut;
}
void basis::setLeftRightWaveFunction(CNVector_t left, CNVector_t right) {
    leftWaveFunction = left;
    rightWaveFunction = right;
}