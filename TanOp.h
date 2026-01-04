#pragma once
#include "../Operation.h"
class TanOp:public IOperation{
    public: 
        bool isTrig() override { return true;}
        double execute(double a, double dummy = 0,double z = 0) override;

};