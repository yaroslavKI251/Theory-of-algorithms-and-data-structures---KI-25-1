#include <iostream>
#include "functions.h"
using namespace std;

double y(double x, int n) {
    if (x <= 0) {
        double y = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double denom = x - i + (x * j); // перевірка на 0, на випадок якщо в x попаде 0
                if (denom == 0) continue;
                y += (1.0 / denom);
            }
        }
        return y;
    } else {
        double y = 1.0;
        for (int i = 1; i <= n; i++) {
            y = y * ((1.0/x) - (1.0/i));
        }
        return y;
    }
}

void printTable(double start, double end, double step, FuncType f) {
    for (double x = start; x < end; x += step) {
        cout << "x = " << x << " | y = " << f(x) << endl;
    }
    
}