#pragma once
#include "../Operation.h"

class IntegrateOp : public IOperation {
private:
    IOperation* func; // Hàm cần tính tích phân
public:
    IntegrateOp(IOperation* function);
    
    // CẬP NHẬT: Thêm tham số z = 0 vào cuối để khớp với cha
    double execute(double a, double b, double z = 0) override; 
};