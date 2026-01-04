#include "TanOp.h"
#include "SinOp.h"
#include "CosOp.h"
#include "AbsOp.h"
#include <iostream>
double TanOp::execute(double x, double modeFlag,double z ) {

    SinOp opSin;
    CosOp opCos;
    AbsOp opAbs;

    double sinVal = opSin.execute(x,modeFlag);
    double cosVal = opCos.execute(x,modeFlag);
        if (opAbs.execute(cosVal) < 1e-9) {
            std::cout << "Error" << std::endl;
            return 0;
        }
    return sinVal/cosVal;
}