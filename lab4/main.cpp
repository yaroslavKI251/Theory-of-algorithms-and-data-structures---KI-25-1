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
        
        cout << i << ": ["; // проміжні результати
        for (int i = 0; i < size; i++) { 
            cout << arr[i] << " ";
        }
        cout << "]";    
        cout << endl;
    }

}

void bubbleSort(int arr[], int size) {
    cout << endl << "Метод Бульбашки" << endl;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        cout << i + 1 << ": ["; // проміжні результати
        for (int i = 0; i < size; i++) { 
            cout << arr[i] << " ";
        }
        cout << "]";    
        cout << endl;
    }
}

void selectSort(int arr[], int size) {
    cout << endl << "Метод Вибору" << endl;
    for (int i = 0; i < size - 1; i++) {
        int minIndex  = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) { minIndex = j; }
        }

        if (minIndex != i) { 
            int temp = arr[i]; 
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        cout << i + 1 << ": ["; // проміжні результати
        for (int i = 0; i < size; i++) { 
            cout << arr[i] << " ";
        }
        cout << "]";    
        cout << endl;
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    SetConsoleCP(65001);   
    SetConsoleOutputCP(65001);
    srand(static_cast<unsigned int>(time(NULL)));

    #define N 27
    #define SIZE (10*N)%51
    int arr[SIZE], arr_bubble[SIZE], arr_select[SIZE];

    for (int i = 0; i < SIZE; i++) { // запис
        arr[i] = rand() % 1081 - 540;
        arr_bubble[i] = rand() % 1081 - 540;
        arr_select[i] = rand() % 1081 - 540;
    }

    printArr(arr, SIZE);
    printArr(arr_bubble, SIZE);
    printArr(arr_select, SIZE);

    insertSort(arr, SIZE);
    bubbleSort(arr_bubble, SIZE);
    selectSort(arr_select, SIZE);
}