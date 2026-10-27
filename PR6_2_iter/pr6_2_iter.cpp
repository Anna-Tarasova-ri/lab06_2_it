// Спосіб 1: ітераційні функції
// Завдання: знайти індекс найменшого непарного елемента масиву a із n цілих чисел
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;

// заповнює масив випадковими числами з діапазону [Low(-20); High(50)]
void Create(int* a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виводить масив у вигляді рядка
void Print(int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// повертає індекс найменшого непарного елемента масиву;
// якщо непарних елементів немає – повертає -1
int IndexOfMin(int* a, const int n)
{
    int imin = -1;                                  // індекс найменшого непарного
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0 && (imin == -1 || a[i] < a[imin]))   // a[i] % 2 != 0 коректно й для від'ємних
            imin = i;
    return imin;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned)time(NULL));        // ініціалізація генератора випадкових чисел

    const int n = 20;
    int a[n];
    int Low = -20, High = 50;

    Create(a, n, Low, High);
    Print(a, n);

    int imin = IndexOfMin(a, n);
    if (imin == -1)
        cout << "Непарних елементів немає" << endl;
    else
        cout << "Індекс найменшого непарного елемента: " << imin
        << " (a[" << imin << "] = " << a[imin] << ")" << endl;

    return 0;
}