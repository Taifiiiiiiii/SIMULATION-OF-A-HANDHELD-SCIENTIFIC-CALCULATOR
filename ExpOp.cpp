#include "ExpOp.h"
double ExpOp ::execute(double x, double b,double z ) {
    if(x < 0) return 1/(execute(-x,0));

    double term = 1;
    double sum = 1;

    int reduction = 0;
    while (x > 1.0) {
        x /= 2.0;
        reduction++;
    }
    for(int i = 1; i <= 25; i++) {
        term *= x/i;
        sum += term;
    }
    for(int i = 1;i <= reduction;++i) {
        sum *= sum;
    }
    return sum;

}