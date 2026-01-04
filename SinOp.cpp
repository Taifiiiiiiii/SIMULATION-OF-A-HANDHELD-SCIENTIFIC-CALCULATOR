#include "SinOp.h"
#include <cmath> 

double SinOp::execute(double x, double modeFlag,double z ) {
 
    double val_rad = x; // Biến lưu giá trị chuẩn Radian để tính toán

    if (modeFlag == 1.0) {
        const double PI = 3.141592653589793;
        val_rad = x * PI / 180.0;
    }
    double term = val_rad; 
    double sum = term;
    
    for (int i = 1; i <= 10; ++i) {
        term *= (-1)*val_rad*val_rad/((2*i) * (2*i+1));
        sum += term;
    }
    
    return sum;
}