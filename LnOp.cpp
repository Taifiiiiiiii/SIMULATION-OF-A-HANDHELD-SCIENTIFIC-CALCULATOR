#include "LnOp.h"
#include <iostream>
double LnOp :: execute(double x, double b,double z ) {
    if (x <= 0) {
        std::cerr << "Error" << std::endl;
        return -9999999;
    }
    double u = (x-1)/(x+1);
    double term = u; 
    double sum = term;

    for(int i = 1; i< 50 ; ++i) {
        term *= u*u;
        sum += term/(2*i+1);
    }
    return 2*sum;
}