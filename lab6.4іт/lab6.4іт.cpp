#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include<Windows.h>

using namespace std;

int findMinIndex(const double arr[], int size);
double sumBetweenNegatives(const double arr[], int size);
void rearrangeArray(double arr[], int size);

    int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;
    cout << "Введіть розмір масиву n: ";
    cin >> n;

    double* arr = new double[n];

    // Генерація випадкових чисел в межах [-100, 100]
    cout << "Початковий масив: [";
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 201 - 100;
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    // Завдання 1.1: Знаходження номера мінімального елементу
    int minIndex = findMinIndex(arr, n);
    cout << "1.1. Номер мінімального елементу: " << minIndex << endl;

    // Завдання 1.2: Обчислення суми елементів між першим і другим від'ємними
    double sumBetweenNegs = sumBetweenNegatives(arr, n);
    cout << "1.2. Сума елементів між першим і другим від'ємними: " << sumBetweenNegs << endl;

    // Завдання 2: Перестановка елементів масиву
    rearrangeArray(arr, n);

    delete[] arr; // Звільнення виділеної пам'яті

    return 0;
}

int findMinIndex(const double arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

double sumBetweenNegatives(const double arr[], int size) {
    int firstNegIndex = -1;
    int secondNegIndex = -1;

    // Знаходження індексів перших двох від'ємних елементів
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = i;
            }
            else {
                secondNegIndex = i;
                break;
            }
        }
    }

    // Обчислення суми елементів між першим і другим від'ємними
    double sum = 0;
    if (firstNegIndex != -1 && secondNegIndex != -1 && secondNegIndex > firstNegIndex + 1) {
        for (int i = firstNegIndex + 1; i < secondNegIndex; ++i) {
            sum += arr[i];
        }
    }

    return sum;
}

void rearrangeArray(double arr[], int size) {
    int firstPositiveIndex = 0;

    // Знаходження індексу першого додатного елемента
    while (firstPositiveIndex < size && abs(arr[firstPositiveIndex]) <= 1.0) {
        ++firstPositiveIndex;
    }

    // Перестановка елементів
    for (int i = firstPositiveIndex + 1; i < size; ++i) {
        if (abs(arr[i]) <= 1.0) {
            // Обмін елементів місцями
            double temp = arr[firstPositiveIndex];
            arr[firstPositiveIndex] = arr[i];
            arr[i] = temp;
            ++firstPositiveIndex;
        }
    }

    // Виведення модифікованого масиву
    cout << "Модифікований масив: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}


        