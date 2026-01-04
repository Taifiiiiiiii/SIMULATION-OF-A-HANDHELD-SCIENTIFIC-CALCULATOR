#include "Ode2Op.h"
#include "AbsOp.h" // <--- Gọi "gà nhà" ra dùng
#include <iostream>

// Hàm evaluate giữ nguyên
double Ode2Op::evaluate(std::string funcStr, double x, double y, double yp) {
    te_variable vars[] = {
        {"x", &x}, {"y", &y}, {"yp", &yp}, {"z", &yp} 
    };
    
    int err;
    te_expr *n = te_compile(funcStr.c_str(), vars, 4, &err);
    
    if (!n) return 0.0; 
    
    double result = te_eval(n);
    te_free(n); 
    return result;
}

double Ode2Op::solve(std::string funcStr, double x0, double y0, double yp0, double target) {
    // 1. Tạo đối tượng tính trị tuyệt đối
    AbsOp absCalc; 

    double h = 0.01; 
    
    if (target < x0) h = -0.01;
    
    double x = x0;
    double y = y0;
    double z = yp0; 

    // 2. Thay std::abs() bằng absCalc.execute()
    // Lưu ý: execute nhận 2 tham số (x, y), ta truyền số 0 vào tham số thứ 2 vì AbsOp không dùng nó.
    
    while ((h > 0 && x < target) || (h < 0 && x > target)) {
        
        // Đoạn này thay std::abs thành absCalc.execute
        double distToTarget = absCalc.execute(target - x, 0);
        double stepSize     = absCalc.execute(h, 0);

        if (distToTarget < stepSize) {
            h = target - x;
        }

        // --- Thuật toán RK4 ---
        double k1 = h * z;
        double l1 = h * evaluate(funcStr, x, y, z);

        double k2 = h * (z + 0.5 * l1);
        double l2 = h * evaluate(funcStr, x + 0.5 * h, y + 0.5 * k1, z + 0.5 * l1);

        double k3 = h * (z + 0.5 * l2);
        double l3 = h * evaluate(funcStr, x + 0.5 * h, y + 0.5 * k2, z + 0.5 * l2);

        double k4 = h * (z + l3);
        double l4 = h * evaluate(funcStr, x + h, y + k3, z + l3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        z += (l1 + 2 * l2 + 2 * l3 + l4) / 6.0;
        x += h;
    }
    
    return y;
}