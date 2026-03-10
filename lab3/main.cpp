#include <iostream>
#include <cmath>
#include <windows.h>
#include "functions.h"
using namespace std;

double myY(double x) {
    return y(x, 3);
}

int main() {
    SetConsoleCP(65001);   
    SetConsoleOutputCP(65001);

    cout << "Таблиця для функції y:" << endl;
    printTable(-5, 5, 0.5, myY);

    cout << "\nТаблиця для функції sin:" << endl;
    printTable(-5, 5, 0.5, sin);
}