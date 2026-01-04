#include "SqrtNOp.h"
#include <cmath> // Cần hàm pow để tính lũy thừa phụ trợ
#include <iostream>

double SqrtNOp::execute(double a, double n,double z ) {
    // 1. Kiểm tra điều kiện
    if (n == 0) return 0; // Không có căn bậc 0
    if (n < 0) return 0;  // Tạm thời chưa xử lý căn bậc âm
    
    // Nếu n chẵn (2, 4, 6...) thì a không được âm
    // Hàm fmod là chia lấy dư cho số thực
    if (a < 0 && std::fmod(n, 2.0) == 0) return 0; 

    // 2. Thuật toán Newton-Raphson tổng quát
    double x = a / n; // Giá trị đoán ban đầu (Guess)
    if (x == 0) x = 1; // Tránh chia cho 0 ở bước đầu

    for (int i = 0; i < 20; ++i) { // Lặp 20 lần là siêu chính xác
        // Công thức: x_moi = ((n-1)*x_cu + a / x_cu^(n-1)) / n
        double tu_so = (n - 1.0) * x + a / std::pow(x, n - 1.0);
        double x_new = tu_so / n;

        // Nếu thay đổi quá nhỏ thì dừng sớm (Tối ưu)
        if (std::abs(x_new - x) < 1e-7) return x_new;
        
        x = x_new;
    }

    return x;
}