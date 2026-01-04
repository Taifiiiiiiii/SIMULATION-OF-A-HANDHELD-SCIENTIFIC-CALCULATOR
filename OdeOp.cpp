 // Thêm chữ Operations/ vào trước
#include "OdeOp.h"
#include <cmath> // Để dùng std::abs

double OdeOp::solve(IOperation* func, double x0, double y0, double x_target) {
    double h = 0.01; // Bước nhảy mặc định
    double x = x0;
    double y = y0;

    // Xác định chiều (đi tới hay đi lùi)
    // Nếu đích nhỏ hơn x0 (vd: từ 1 về 0) thì h phải âm
    if (x_target < x0) {
        h = -0.01; 
    }

    // Vòng lặp: Chạy chừng nào chưa vượt qua đích
    // (h > 0 && x < target) HOẶC (h < 0 && x > target)
    while ((h > 0 && x < x_target) || (h < 0 && x > x_target)) {
        
        // QUAN TRỌNG: Xử lý bước cuối cùng
        // Nếu bước tiếp theo (x + h) bị lố qua đích -> Rút ngắn h lại cho vừa khít
        if (std::abs(x + h - x0) > std::abs(x_target - x0)) {
            h = x_target - x;
        }

        // Logic RK4 (Giữ nguyên của bạn - Chuẩn rồi)
        double k1 = h * func->execute(x, y);
        double k2 = h * func->execute(x + 0.5 * h, y + 0.5 * k1);
        double k3 = h * func->execute(x + 0.5 * h, y + 0.5 * k2);
        double k4 = h * func->execute(x + h, y + k3);

        y += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        x += h;

        // Nếu h đã được rút ngắn bằng khoảng cách cuối -> Đã đến đích -> Break
        if (x == x_target) break;
    }

    return y;
}