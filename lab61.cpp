#include <iostream>
#include <cmath>

using namespace std;

float get_number(string prompt);

int main()
{    
    setlocale(LC_ALL, ".UTF-8");

    float x_first = get_number("х начальный элемент");
    float x_last = get_number("х конечный элемент");
    float x_delta = get_number("шаг х");


    return 0;
}

float get_number(string prompt)
{    
    float x;

    cout << "Введите " << prompt << " функции (числом; 5 -13 6.1): ";
    cin >> x;
    return x;
}