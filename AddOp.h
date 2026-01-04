#pragma once
#include "../Operation.h" // AddOp là con của IOperation  ../ lùi ra thư mục cha để tìm file 
class AddOp : public IOperation { // kế thừa IOperation
public:
    double execute(double a, double b,double z = 0) override;
};