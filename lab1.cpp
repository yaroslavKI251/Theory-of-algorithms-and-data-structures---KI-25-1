#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double readData(string message);
    double y(double x, int n);

    double xStart = readData("Введіть початок інтервалу: ");
    double xEnd = readData("Введіть кінець інтервалу: ");
    double step = readData("Введіть крок: ");
    int n = readData("Введіть число n: ");

    for (double x = xStart; x <= xEnd; x += step) {
        if (x == 0) {
            cout << "x = " << x << ". y = невизначено (ділення на 0)" << endl;
            continue;
        }
        cout << "x = " << x << ". y = " << y(x, n) << endl;
    }
}

double readData(string message) {
    double num;
    cout << message;
    cin >> num;
    return num;
}

double y(double x, int n) {
    if (x <= 0) {
        double y = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                y += (1.0 / (x - i + (x * j)));
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
