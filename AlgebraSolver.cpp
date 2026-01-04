#include "AlgebraSolver.h"
#include <iostream>
#include <cmath>
#include <iomanip> // Để in số đẹp

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

void AlgebraSolver::solveLinear(double a, double b) {
    cout << "-> PT: " << a << "x + " << b << " = 0" << endl;
    if (a == 0) {
        if (b == 0) cout << "=> Phuong trinh vo so nghiem." << endl;
        else cout << "=> Phuong trinh vo nghiem." << endl;
    } else {
        cout << "=> Nghiem x = " << -b / a << endl;
    }
}

void AlgebraSolver::solveQuadratic(double a, double b, double c) {
    if (a == 0) { solveLinear(b, c); return; }

    cout << "-> PT: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    double delta = b*b - 4*a*c;
    
    if (delta < 0) {
        cout << "=> Vo nghiem thuc." << endl;
    } else if (delta == 0) {
        cout << "=> Nghiem kep x = " << -b / (2*a) << endl;
    } else {
        cout << "=> x1 = " << (-b + sqrt(delta)) / (2*a) << endl;
        cout << "=> x2 = " << (-b - sqrt(delta)) / (2*a) << endl;
    }
}

void AlgebraSolver::solveCubic(double a, double b, double c, double d) {
    if (a == 0) { solveQuadratic(b, c, d); return; }

    cout << "-> PT: " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0" << endl;

    // Chuẩn hóa về dạng x^3 + Ax^2 + Bx + C = 0
    double A = b/a, B = c/a, C = d/a;
    
    double Q = (3*B - A*A)/9;
    double R = (9*A*B - 27*C - 2*A*A*A)/54;
    double D = Q*Q*Q + R*R; // Discriminant

    if (D > 0) { // 1 nghiệm thực
        double S = cbrt(R + sqrt(D));
        double T = cbrt(R - sqrt(D));
        cout << "=> Nghiem thuc duy nhat x = " << -A/3 + (S + T) << endl;
    } else if (D == 0) { // Nghiệm bội
        double S = cbrt(R);
        cout << "=> x1 = " << -A/3 + 2*S << endl;
        cout << "=> x2 = " << -A/3 - S << endl;
    } else { // 3 nghiệm thực phân biệt (D < 0)
        double theta = acos(R / sqrt(-Q*Q*Q));
        cout << "=> x1 = " << 2*sqrt(-Q)*cos(theta/3) - A/3 << endl;
        cout << "=> x2 = " << 2*sqrt(-Q)*cos((theta + 2*M_PI)/3) - A/3 << endl;
        cout << "=> x3 = " << 2*sqrt(-Q)*cos((theta + 4*M_PI)/3) - A/3 << endl;
    }
}