#pragma once
#include "../Operation.h"
class LnOp : public IOperation {
    public:
        double execute(double a, double b = 0,double z = 0) override;
};