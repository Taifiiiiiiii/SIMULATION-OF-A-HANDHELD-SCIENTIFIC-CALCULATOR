#pragma once
#include "../Operation.h"

class OdeOp{
    public:
        double solve(IOperation* func, double x0, double y0, double x_target);
};