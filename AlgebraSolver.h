#pragma once
class AlgebraSolver {
public:
    // Giải ax + b = 0
    void solveLinear(double a, double b);

    // Giải ax^2 + bx + c = 0
    void solveQuadratic(double a, double b, double c);

    // Giải ax^3 + bx^2 + cx + d = 0
    void solveCubic(double a, double b, double c, double d);
};