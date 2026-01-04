#pragma once
#include <string>
#include "../tinyexpr.h"
#include "../Operation.h"

class DynamicEquation : public IOperation {
private:
    std::string expression;

    static bool isDegreeMode;

    static double my_sin(double x);
    static double my_cos(double x);
    static double my_tan(double x);
    static double my_acos(double x);
    static double my_asin(double x);
    static double my_atan(double x);

public:
    DynamicEquation(std::string expr);
    
    static void setDegreeMode(bool enable);
    static bool getDegreeMode();

    // 3. Thêm từ khóa override cho chắc chắn
    double execute(double x, double y, double z = 0) override;
};