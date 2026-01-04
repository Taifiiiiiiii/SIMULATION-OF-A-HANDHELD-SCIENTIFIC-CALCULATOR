#include "IntegrateOp.h"

IntegrateOp::IntegrateOp(IOperation* function) {
    this->func = function;
}

// CẬP NHẬT: Thêm tham số z vào đây (dù không dùng cũng phải có)
double IntegrateOp::execute(double a, double b, double z) {
    double n = 1000; // Số bước chia (Simpson)
    double h = (b - a) / n;
    
    // Lưu ý: func->execute vẫn nhận 2 tham số (x, y), tham số z ta truyền 0
    double sum = func->execute(a, 0) + func->execute(b, 0);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * func->execute(x, 0);
        else
            sum += 4 * func->execute(x, 0);
    }

    return sum * h / 3.0;
}