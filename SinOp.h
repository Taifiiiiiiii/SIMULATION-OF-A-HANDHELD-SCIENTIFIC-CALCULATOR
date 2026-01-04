#pragma once
#include "../Operation.h"
class SinOp : public IOperation {
public:
    bool isTrig() override { return true; } // Báo hiệu đây là Lượng giác
    double execute(double x, double dummy = 0,double z = 0) override;
};