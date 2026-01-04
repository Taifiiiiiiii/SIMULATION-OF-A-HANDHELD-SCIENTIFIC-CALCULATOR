#include "PowOp.h"
#include "AbsOp.h"
#include "LnOp.h"
#include "ExpOp.h"
#include <iostream>

double PowOp::execute(double base, double exponent,double z ) {
    LnOp opLn;
    ExpOp opExp;
    AbsOp opAbs;

    if(opAbs.execute(base) < 1e-9) return 0;
    if(opAbs.execute(base - 1) < 1e-9) return 1;
    if(exponent == 0) return 1;

    if(base < 0){
        long long exponentInt = (long long)exponent; // dùng long long để tránh bị tràn số
        if(opAbs.execute(exponent - exponentInt) < 1e-9) {
            //(-a)^b = (-1)^b.(a)^b
            // tính toán trên cơ số dương (-base)
            double res = opExp.execute(exponent*opLn.execute(-base,0),0);
            
            return(exponentInt % 2 == 0) ? res : -res;
        } else {
            std::cerr << "[Error] Negative base with non-integer exponent!" << std::endl;
            return 0;
        }
    }

    // 5. CƠ SỐ DƯƠNG (Bình thường)
    double ln_a = opLn.execute(base);
    return opExp.execute(exponent*ln_a,0);
}
