#pragma once
#include <string>
#include "../tinyexpr.h"
class Ode2Op {
    private:
        double evaluate(std::string funcStr, double x, double y, double yp);
    public:
        double solve(std::string funcStr, double x0, double y0, double yp0, double target);
};