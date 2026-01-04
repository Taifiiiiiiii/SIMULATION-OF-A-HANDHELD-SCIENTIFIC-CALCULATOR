#pragma once
#include "../Operation.h" 

class SqrtOp : public IOperation {
public:
    double execute(double a, double dummy = 0,double z = 0) override;
};