#pragma once 
#include "../Operation.h"

class SqrtNOp: public IOperation{
    public:
        double execute(double a, double n,double z = 0);
};