#pragma once // là một lệnh cực kỳ quan trọng dùng để chống lỗi "Khai báo lặp lại"

class IOperation {
public:
    virtual double execute(double a, double b = 0,double z = 0) = 0;

    virtual bool isTrig() { return false; }

    virtual ~IOperation() {} // Hàm hủy ảo (Quan trọng để tránh rò rỉ bộ nhớ)
};