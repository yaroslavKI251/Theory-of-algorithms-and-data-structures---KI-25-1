#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void insertSort(int arr[], int size) {
    cout << endl << endl << "Метод Вставки" << endl;

    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        
        // cout << i << ": [";
        // for (int k = 0; k < size; k++) cout << arr[k] << " ";
        // cout << "]\n";
    }
}

void bubbleSort(int arr[], int size) {
    cout << endl << "Метод Бульбашки" << endl;
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        // cout << i + 1 << ": [";
        // for (int k = 0; k < size; k++) cout << arr[k] << " ";
        // cout << "]\n";

        if (!swapped) break;
    }
}

void selectSort(int arr[], int size) {
    cout << endl << "Метод Вибору" << endl;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) { minIndex = j; }
        }

        if (minIndex != i) { 
            int temp = arr[i]; 
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        // cout << i + 1 << ": [";
        // for (int k = 0; k < size; k++) cout << arr[k] << " ";
        // cout << "]\n";
    }
}

void shakerSort(int arr[], int size) {
    cout << endl << "Метод Шейкера" << endl;

    int left = 0, right = size - 1, count = 1;

    while (left < right) {
        bool swapped = false;

        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = true;
            }
        }
        left++;

        if (!swapped) break;
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    unsigned int start_time = clock();

    SetConsoleCP(65001);   
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned int>(time(NULL)));

    #define N 27
    #define SIZE 270000

    // int* arr        = new int[SIZE];
    // int* arr_bubble = new int[SIZE];
    // int* arr_select = new int[SIZE];
    int* arr_shake  = new int[SIZE];

    for (int i = 0; i < SIZE; i++) {
        // arr[i]        = rand() % 1081 - 540;
        // arr_bubble[i] = rand() % 1081 - 540;
        // arr_select[i] = rand() % 1081 - 540;
        arr_shake[i]  = rand() % 1081 - 540;
    }

    // printArr(arr, SIZE);
    // printArr(arr_bubble, SIZE);
    // printArr(arr_select, SIZE);
    printArr(arr_shake, SIZE);

    // insertSort(arr, SIZE);
    // bubbleSort(arr_bubble, SIZE);
    // selectSort(arr_select, SIZE);
    shakerSort(arr_shake, SIZE);

    unsigned int end_time = clock(); 
    cout << "\nЧас: " << end_time - start_time << " мс" << endl;

    // delete[] arr;
    // delete[] arr_bubble;
    // delete[] arr_select;
    delete[] arr_shake;

    return 0;
}