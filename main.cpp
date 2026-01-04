#include <iostream>
#include <string>
#include <cstdlib>
#include "Operations/DynamicEquation.h" 
#include "Operations/AlgebraSolver.h"   
#include "Operations/OdeOp.h"
#include "Operations/Ode2Op.h"
#include "Operations/IntegrateOp.h"

using namespace std;


int main() {
    AlgebraSolver algebra;
    OdeOp ode1;
    Ode2Op ode2;
    int choice;

    while (true) {
        string status = DynamicEquation::getDegreeMode() ? "DEG (Do)" : "RAD (Radian)";
        
        cout << "\n========== SIEU MAY TINH C++ [Che do: " << status << "] ==========\n";
        cout << "1. Tinh toan Co ban (+, -, *, /, ^, sin, cos...)\n";
        cout << "2. Giai Phuong Trinh Dai So (Bac 1, 2, 3)\n";
        cout << "3. Giai PT Vi Phan Bac 1 (y' = ...)\n";
        cout << "4. Giai PT Vi Phan Bac 2 (y'' = ...)\n";
        cout << "5. Tinh Tich Phan\n";
        cout << "6. DOI CHE DO DO / RADIAN\n"; 
        cout << "0. Thoat\n";
        cout << ">> Lua chon cua ban: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 0) break;

        switch (choice) {
            case 1: { 
                string expr;
                cout << "\n--- MAY TINH KHOA HOC ---\n";
                cout << "Nhap bieu thuc: ";
                getline(cin, expr);
                
                DynamicEquation calculator(expr);
                double result = calculator.execute(0, 0);
                if (result != result) { 
                    cout << "=> LOI: Phep tinh khong xac dinh (NaN)!" << endl;
                }
                else if (result > 1e300 || result < -1e300) {
                    cout << "=> LOI: Ket qua qua lon hoac chia cho 0 (Inf)!" << endl;
                }
                else {
                    cout << "=> Ket qua = " << result << endl;
                }
                break;
            }
            case 2: {
                int bac;
                cout << "\n--- GIAI PHUONG TRINH DAI SO ---\n";
                cout << "Chon bac (1, 2, 3): "; cin >> bac;
                if (bac == 1) {
                    double a, b; cout << "Nhap a, b: "; cin >> a >> b;
                    algebra.solveLinear(a, b);
                } else if (bac == 2) {
                    double a, b, c; cout << "Nhap a, b, c: "; cin >> a >> b >> c;
                    algebra.solveQuadratic(a, b, c);
                } else if (bac == 3) {
                    double a, b, c, d; cout << "Nhap a, b, c, d: "; cin >> a >> b >> c >> d;
                    algebra.solveCubic(a, b, c, d);
                }
                break;
            }
            case 3: {
                string func;
                cout << "\n--- ODE BAC 1 (y' = f(x,y)) ---\n";
                cout << "Nhap f(x,y): "; getline(cin, func);
                DynamicEquation eq(func);
                double x0, y0, target;
                cout << "Nhap x0, y0, target: "; cin >> x0 >> y0 >> target;
                cout << "=> Ket qua y(" << target << ") = " << ode1.solve(&eq, x0, y0, target) << endl;
                break;
            }
            case 4: {
                string func;
                cout << "\n--- ODE BAC 2 (y'' = f(x,y,yp)) ---\n";
                cout << "Nhap f(x,y,yp): "; getline(cin, func);
                double x0, y0, yp0, target;
                cout << "Nhap x0, y0, y'0, target: "; cin >> x0 >> y0 >> yp0 >> target;
                cout << "=> Ket qua y(" << target << ") = " << ode2.solve(func, x0, y0, yp0, target) << endl;
                break;
            }
            case 5: {
                string func;
                cout << "\n--- TINH TICH PHAN ---\n";
                cout << "Nhap ham f(x): "; getline(cin, func);
                double a, b;
                cout << "Nhap can tu a den b: "; cin >> a >> b;
                DynamicEquation eq(func);
                IntegrateOp integ(&eq);
                cout << "=> Ket qua = " << integ.execute(a, b) << endl;
                break;
            }
            case 6: {
                bool current = DynamicEquation::getDegreeMode();
                DynamicEquation::setDegreeMode(!current);
                cout << "=> DA CHUYEN SANG CHE DO: " << (!current ? "DEG (Do)" : "RAD (Radian)") << endl;
                break;
            }
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
        cout << "\nAn Enter de tiep tuc...";
        cin.ignore(); cin.get();
    }
    return 0;
}