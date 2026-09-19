#include <iostream>
#include <cmath>

using namespace std;

float get_number(string prompt);

int main()
{    
    setlocale(LC_ALL, ".UTF-8");

    float x_first = get_number("х начальный элемент");
    float x = x_first;
    float x_last = get_number("х конечный элемент");
    float x_delta = get_number("шаг х");

    do
    {
        if (x == 2)
        {    
            cout << "F(" << x << ") не существует (деление на 0)";
        }
        else
        {    
            cout << "F(" << x << ") = " << 2.5 * pow(x, 3) + (3.2 / (x - 2)) + pow(sin(x), 3) << endl;
        }
        
        x += x_delta;
    } while (x <= x_last + x_delta / 2.0);
    
    return 0;
}

float get_number(string prompt)
{    
    float x;

    cout << "Введите " << prompt << " функции (числом; 5 -13 6.1): ";
    cin >> x;
    return x;
}