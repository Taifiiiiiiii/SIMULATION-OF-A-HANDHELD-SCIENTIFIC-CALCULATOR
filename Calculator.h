#pragma once
#include "Operation.h"
#include <cmath>

class Calculator {
private:
    bool isDegreeMode; 

public:
    Calculator() { isDegreeMode = true; } 

    void setDegreeMode(bool enable) {  
        isDegreeMode = enable;
    }
    double calculate(IOperation* op, double val, double val2 = 0) {
        double contextParam = val2;
        if (op->isTrig()) {
            contextParam = isDegreeMode ? 1.0 : 0.0;
        }
        return op->execute(val, contextParam); 
    }
};