#pragma once
#include "../Operation.h"

class AbsOp : public IOperation {
public:
    double execute(double val, double dummy = 0,double z = 0) override;
};