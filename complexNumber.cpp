//
// Created by DongHoon Kim on 11/20/20.
//

#include "complexNumber.h"
#include <iostream>
complexNumber::complexNumber(double real,double imag){
    complexNumber::real = real;
    complexNumber::imag = imag;
}
/*                          */
//
// + operators
//
/*                          */

const complexNumber complexNumber::operator+(complexNumber &p) {
    //buffreal = real + p.real;
    //buffimag = imag + p.imag;
    //return complexNumber(buffreal,buffimag);
    std::cout<<"address operator call"<<std::endl;
    return complexNumber(real + p.real,imag + p.imag);
}
/*
const complexNumber complexNumber::operator + (complexNumber p){
    std::cout<<"direct operator call"<<std::endl;
    return complexNumber(real + p.real,imag + p.imag);
}
*/
const complexNumber complexNumber::operator+(double num) {
    //buffreal = real + num;
    //buffimag = imag;
    //return complexNumber(buffreal,buffimag);
    return complexNumber(real + num,imag);
}
const complexNumber operator + (double num, complexNumber p){
    p.real += num;
    return p;
}

/*                          */
//
// - operators
//
/*                          */
const complexNumber complexNumber::operator - (complexNumber& p){
    //buffreal = real - p.real;
    //buffimag = imag - p.imag;
    //return complexNumber(buffreal,buffimag);
    return complexNumber(real - p.real,imag - p.imag);
}
const complexNumber complexNumber::operator - (double num){
    //buffreal = real - num;
    //buffimag = imag;
    //return complexNumber(buffreal,buffimag);
    return complexNumber(real - num,imag);
}
const complexNumber operator - (double num, complexNumber p){
    p.real -= num;
    return p;
}

/*                          */
//
// * operators
//
/*                          */
const complexNumber complexNumber::operator * (complexNumber& p){
    //buffreal = real*p.real - imag*p.imag;
    //buffimag = real*p.imag + imag*p.real;
    //return complexNumber(buffreal,buffimag);
    return complexNumber(real*p.real - imag*p.imag,real*p.imag + imag*p.real);
}
const complexNumber complexNumber::operator * (double num){
    //buffreal = real * num;
    //buffimag = imag * num;
    //return complexNumber(buffreal,buffimag);
    return complexNumber(real * num,imag * num);
}
const complexNumber operator*(double num, complexNumber p){
    p.real = p.real * num;
    p.imag = p.imag * num;
    return p;
}

/*                          */
//
// / operators
//
/*                          */
const complexNumber complexNumber::operator / (complexNumber& p){
    //buffreal = (real*p.real+imag*p.imag)/(p.real*p.real+p.imag*p.imag);
    //buffimag = (imag*p.real-real*p.imag)/(p.real*p.real+p.imag*p.imag);
    //return complexNumber(buffreal,buffimag);
    return complexNumber((real*p.real+imag*p.imag)/(p.real*p.real+p.imag*p.imag),(imag*p.real-real*p.imag)/(p.real*p.real+p.imag*p.imag));
}
const complexNumber complexNumber::operator / (double num){
    //buffreal = real / num;
    //buffimag = imag / num;
    //return complexNumber(buffreal,buffimag);
    return complexNumber(real / num,imag / num);
}
const complexNumber operator / (double num, complexNumber p){
    //buffreal = (num*p.real)/(p.real*p.real+p.imag*p.imag);
    //buffimag = (-num*p.imag)/(p.real*p.real+p.imag*p.imag);
    return complexNumber((num*p.real)/(p.real*p.real+p.imag*p.imag),(-num*p.imag)/(p.real*p.real+p.imag*p.imag));
}

/*                          */
//
// extra operators
//
/*                          */

complexNumber complexNumber::conjugate(complexNumber CNIn) {
    return complexNumber(CNIn.realN(),-CNIn.imagN());
}
complexNumber complexNumber::conjugate() {
    return complexNumber(real,-imag);
}

double complexNumber::absValue(complexNumber CNIn) {
    return sqrt(CNIn.realN()*CNIn.realN()*CNIn.imagN()*CNIn.imagN());
}
double complexNumber::absValue() {
    return sqrt(real*real+imag*imag);
}

void complexNumber::setValue(double realIN, double imagIN){
    real = realIN;
    imag = imagIN;
}