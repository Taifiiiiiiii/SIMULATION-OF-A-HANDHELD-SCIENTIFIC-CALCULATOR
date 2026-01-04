#include "CosOp.h"
#include <cmath> 

double CosOp::execute(double x, double modeFlag,double) {

    double val_rad = x; 

    // Nếu modeFlag = 1.0 (Độ) -> Đổi sang Radian
    if (modeFlag == 1.0) {
        const double PI = 3.141592653589793;
        val_rad = x * PI / 180.0; 
    }
  

    double term = 1.0; 
    double sum = term;
    
    for (int i = 1; i <= 10; ++i) {      
        term *= (-1)*val_rad*val_rad/((2*i-1)*(2*i));
        sum += term;
    }
    
    return sum;
}