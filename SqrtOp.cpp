#include "SqrtOp.h"
#include <cmath>

double SqrtOp::execute(double a, double dummy,double z ) {
    if (a < 0) return 0; // Không tính căn số âm
    if (a == 0) return 0;

    double t = a / 2.0; // Giá trị dự đoán ban đầu (Guess)
    // Công thức: t_moi = (t_cu + a/t_cu) / 2
    for (int i = 0; i < 10; ++i) {
        t = (t + a / t) / 2.0;
    }
    
    return t;
}