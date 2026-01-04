#pragma once
#include "../Operation.h"

class DivOp : public IOperation {
    public:
        double execute(double a, double b,double z = 0) override;
        
};