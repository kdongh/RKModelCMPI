//
// Created by DongHoon Kim on 11/16/20.
//

#include "atomicUnit.h"

double eVtoAtomic(double ev){

    return ev / 27.211386245988;
}

double meVtoAtomic(double meV){
    return eVtoAtomic(meV*0.001);
}

double stoAtomic(double s){
    return s / (2.418884326e-17);
}
double fstoAtomic(double fs){
    return stoAtomic(fs)*1E-12;
}


double nmtoAtomic(double nm){
    return nm / 5.29177210903;
}
double atoAtomic(double a){
    return nmtoAtomic(a)/10;
}