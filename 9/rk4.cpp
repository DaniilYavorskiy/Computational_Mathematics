#include <iostream>
#include <cmath>

using namespace std;

// dy^2/d^2x = f(x,y,v)
//double f(double x, double y, double v) {
//	return v-y/x;
//    //return (y+v+x*x)/x;
//}

double rungeKutta4(double x, double& y, double& v, double h) {

    double k1 = h * v;
    double l1 = h * f(x, y, v);
    double k2 = h * (v + 0.5 * l1);
    double l2 = h * f(x + 0.5 * h, y + 0.5 * k1, v + 0.5 * l1);
    double k3 = h * (v + 0.5 * l2);
    double l3 = h * f(x + 0.5 * h, y + 0.5 * k2, v + 0.5 * l2);
    double k4 = h * (v + l3);
    double l4 = h * f(x + h, y + k3, v + l3);
    y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    v += (l1 + 2 * l2 + 2 * l3 + l4) / 6;
}

//int main() {
//	setlocale(LC_ALL, "Russian");
//    
//    double x;        // Initial x
//    double y;        // Initial y
//    double v;		// Initial y'
//    
//    double h;         // Step size
//    int numSteps;
//    
//    cout << "Введите x0: ";
//    cin >> x;
//    cout << "Введите y0: ";
//    cin >> y;
//    cout << "Введите y`: ";
//    cin >> v;
//    cout << "Введите количество шагов: ";
//    cin >> numSteps;
//    cout << "Введите размер шага h: ";
//    cin >> h;
//    
//    cout << "Начальные условия: y(" << x << ") = " << y << endl;
//    for (int i = 0; i < numSteps; ++i) {
//        rungeKutta4(x, y, v, h);
//        x += h;
//        cout << "Шаг " << i + 1 << ": y(" << x << ") = " << y << ", y'(" << x << ") = " << v << endl;
//    }
//
//	system("pause");
//    return 0;
//}
