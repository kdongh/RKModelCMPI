//
// Created by DongHoon Kim on 11/20/20.
//

#ifndef RK_MPI_COMPLEXNUMBER_H
#define RK_MPI_COMPLEXNUMBER_H

#include <iostream>

class complexNumber {
private:
    double real, imag;
    double buffreal, buffimag;

public:
    complexNumber(double real=0,double imag=0);

    const complexNumber operator + (complexNumber& p);
    const complexNumber operator + (double num);
    friend const complexNumber operator+(double num, complexNumber p);

    const complexNumber operator - (complexNumber& p);
    const complexNumber operator - (double num);
    friend const complexNumber operator-(double num, complexNumber p);

    const complexNumber operator * (complexNumber& p);
    const complexNumber operator * (double num);
    friend const complexNumber operator*(double num, complexNumber p);

    const complexNumber operator / (complexNumber& p);
    const complexNumber operator / (double num);
    friend const complexNumber operator / (double num, complexNumber p);

    complexNumber conjugate(complexNumber CNIn);
    complexNumber conjugate();

    double absValue(complexNumber CNin);
    double absValue();

    void print(){
        if(imag>0){
            std::cout<<real<<" + i"<<imag<<std::endl;
        } else{
            std::cout<<real<<" - i"<<-imag<<std::endl;
        }
    }

    double realN(){
        return real;
    }
    double imagN(){
        return imag;
    }
};


#endif //RK_MPI_COMPLEXNUMBER_H
