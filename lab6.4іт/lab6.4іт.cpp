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
    cout << "������ ����� ������ n: ";
    cin >> n;

    double* arr = new double[n];

    // ��������� ���������� ����� � ����� [-100, 100]
    cout << "���������� �����: [";
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 201 - 100;
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    // �������� 1.1: ����������� ������ ���������� ��������
    int minIndex = findMinIndex(arr, n);
    cout << "1.1. ����� ���������� ��������: " << minIndex << endl;

    // �������� 1.2: ���������� ���� �������� �� ������ � ������ ��'������
    double sumBetweenNegs = sumBetweenNegatives(arr, n);
    cout << "1.2. ���� �������� �� ������ � ������ ��'������: " << sumBetweenNegs << endl;

    // �������� 2: ������������ �������� ������
    rearrangeArray(arr, n);

    delete[] arr; // ��������� ������� ���'��

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

    // ����������� ������� ������ ���� ��'����� ��������
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

    // ���������� ���� �������� �� ������ � ������ ��'������
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

    // ����������� ������� ������� ��������� ��������
    while (firstPositiveIndex < size && abs(arr[firstPositiveIndex]) <= 1.0) {
        ++firstPositiveIndex;
    }

    // ������������ ��������
    for (int i = firstPositiveIndex + 1; i < size; ++i) {
        if (abs(arr[i]) <= 1.0) {
            // ���� �������� ������
            double temp = arr[firstPositiveIndex];
            arr[firstPositiveIndex] = arr[i];
            arr[i] = temp;
            ++firstPositiveIndex;
        }
    }

    // ��������� �������������� ������
    cout << "������������� �����: [";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}


        