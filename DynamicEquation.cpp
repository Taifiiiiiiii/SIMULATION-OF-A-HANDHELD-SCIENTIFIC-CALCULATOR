#include "DynamicEquation.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Khởi tạo mặc định là Radian (False)
bool DynamicEquation::isDegreeMode = false;

// --- CÁC HÀM WRAPPER ---
double DynamicEquation::my_sin(double x) {
    if (isDegreeMode) x = x * M_PI / 180.0;
    return sin(x);
}

double DynamicEquation::my_cos(double x) {
    if (isDegreeMode) x = x * M_PI / 180.0;
    return cos(x);
}

double DynamicEquation::my_tan(double x) {
    if (isDegreeMode) x = x * M_PI / 180.0;
    return tan(x);
}

// Hàm ngược (asin, acos) thì trả về kết quả cần đổi từ Rad -> Độ
double DynamicEquation::my_asin(double x) {
    double res = asin(x);
    if (isDegreeMode) res = res * 180.0 / M_PI;
    return res;
}

double DynamicEquation::my_acos(double x) {
    double res = acos(x);
    if (isDegreeMode) res = res * 180.0 / M_PI;
    return res;
}

double DynamicEquation::my_atan(double x) {
    double res = atan(x);
    if (isDegreeMode) res = res * 180.0 / M_PI;
    return res;
}

// --- LOGIC CHÍNH ---

DynamicEquation::DynamicEquation(std::string expr) : expression(expr) {}

void DynamicEquation::setDegreeMode(bool enable) {
    isDegreeMode = enable;
}

bool DynamicEquation::getDegreeMode() {
    return isDegreeMode;
}

double DynamicEquation::execute(double x, double y, double z) {
    // 1. Khai báo các biến
     te_variable vars[] = {
        {"x", &x}, {"y", &y}, {"z", &z}, {"yp", &z},
        
        // --- SỬA ĐOẠN NÀY (Thêm (void*) vào trước tên hàm) ---
        {"sin",  (void*)my_sin,  TE_FUNCTION1},
        {"cos",  (void*)my_cos,  TE_FUNCTION1},
        {"tan",  (void*)my_tan,  TE_FUNCTION1},
        {"asin", (void*)my_asin, TE_FUNCTION1},
        {"acos", (void*)my_acos, TE_FUNCTION1},
        {"atan", (void*)my_atan, TE_FUNCTION1}
    };

    // Số lượng phần tử trong mảng vars = 4 biến + 6 hàm = 10
    int num_vars = 10; 

    int err;
    te_expr *n = te_compile(expression.c_str(), vars, num_vars, &err);

    if (!n) return 0.0;
    double res = te_eval(n);
    te_free(n);
    return res;
}