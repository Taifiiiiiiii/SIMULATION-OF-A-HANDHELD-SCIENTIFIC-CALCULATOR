#pragma once
#include "../Operation.h"

class PowOp : public IOperation {
    public:
        double execute(double base, double exponent,double z = 0) override;
};