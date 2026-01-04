#include "DivOp.h"
#include <iostream>
double DivOp :: execute(double a, double b,double z ){
    if(b == 0) {
        std::cerr << "Error" << std::endl;
    }
    return a/b;
}