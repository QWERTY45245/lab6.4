#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

int findMinIndexRec(const double arr[], int size, int currentIndex = 1, int minIndex = 0);
double sumBetweenNegativesRec(const double arr[], int size, int currentIndex = 0, int firstNegIndex = -1, int secondNegIndex = -1);
void rearrangeArrayRec(double arr[], int size, int currentIndex = 0, int firstPositiveIndex = 0);

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
    int minIndex = findMinIndexRec(arr, n);
    cout << "1.1. Номер мінімального елементу: " << minIndex << endl;

    // Завдання 1.2: Обчислення суми елементів між першим і другим від'ємними
    double sumBetweenNegs = sumBetweenNegativesRec(arr, n);
    cout << "1.2. Сума елементів між першим і другим від'ємними: " << sumBetweenNegs << endl;

    // Завдання 2: Перестановка елементів масиву
    rearrangeArrayRec(arr, n);

    delete[] arr; // Звільнення виділеної пам'яті

    return 0;
}

int findMinIndexRec(const double arr[], int size, int currentIndex, int minIndex) {
    if (currentIndex < size) {
        if (arr[currentIndex] < arr[minIndex]) {
            minIndex = currentIndex;
        }
        return findMinIndexRec(arr, size, currentIndex + 1, minIndex);
    }
    return minIndex;
}

double sumBetweenNegativesRec(const double arr[], int size, int currentIndex, int firstNegIndex, int secondNegIndex) {
    if (currentIndex < size) {
        if (arr[currentIndex] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = currentIndex;
            }
            else {
                secondNegIndex = currentIndex;
                return sumBetweenNegativesRec(arr, size, currentIndex + 1, firstNegIndex, secondNegIndex);
            }
        }
        return sumBetweenNegativesRec(arr, size, currentIndex + 1, firstNegIndex, secondNegIndex);
    }

    double sum = 0;
    if (firstNegIndex != -1 && secondNegIndex != -1 && secondNegIndex > firstNegIndex + 1) {
        for (int i = firstNegIndex + 1; i < secondNegIndex; ++i) {
            sum += arr[i];
        }
    }

    return sum;
}

void rearrangeArrayRec(double arr[], int size, int currentIndex, int firstPositiveIndex) {
    if (currentIndex < size) {
        if (abs(arr[currentIndex]) <= 1.0) {
            double temp = arr[firstPositiveIndex];
            arr[firstPositiveIndex] = arr[currentIndex];
            arr[currentIndex] = temp;
            ++firstPositiveIndex;
        }

        rearrangeArrayRec(arr, size, currentIndex + 1, firstPositiveIndex);
    }
    else {
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
}
