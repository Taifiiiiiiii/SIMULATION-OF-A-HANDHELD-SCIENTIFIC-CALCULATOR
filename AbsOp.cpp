#include "AbsOp.h"

double AbsOp::execute(double val, double dummy,double z ) {
    return (val < 0) ? -val : val;
}