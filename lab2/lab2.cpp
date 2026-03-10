#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

int main(){
    SetConsoleCP(65001);   
    SetConsoleOutputCP(65001);

    double readData(string message);
    double y(double x, int n);
    void reset(double** arr, int rows);

    int number = 0, rows = 0, cols = 0, n = readData("Введіть число n: ");
    ifstream infile("C:\\Users\\Liceum\\Documents\\VS_Code_works\\KI-25-1\\semestr2\\TA\\input_lab2.txt");

    if (!infile || !infile.is_open()) {
        cerr << "Could not open the file!";
        return 1;
    }

    infile >> rows >> cols;

    double** scan_arr = new double*[rows]; // виділення дин. памяті на массив
    for (int i = 0; i < rows; i++) {
        scan_arr[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++){ // 1 массив
        for (int j = 0; j < cols; j++) {
            infile >> scan_arr[i][j];
        }
    }

    infile.close();
    
    double** func_arr = new double*[rows]; // 2 массив
    for (int i = 0; i < rows; i++) {
        func_arr[i] = new double[cols];
    }

    ofstream outFile("output.txt");

    for (int i = 0; i < rows; i++) { // y функція по массиву
        for (int j = 0; j < cols; j++) {
            *(func_arr[i] + j) = y(*(scan_arr[i] + j), n);

            printf("y = %f\n", *(func_arr[i] + j));
            outFile << *(func_arr[i] + j) << " ";
        }
    }

    reset(scan_arr, rows); // зв. пам.
    reset(func_arr, rows);

    return 0;
}

double readData(string message) {
    double num;
    cout << message;
    cin >> num;
    return num;
}

void reset(double** arr, int rows) { // звільненя памяті
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

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