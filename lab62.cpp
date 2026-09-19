#include <iostream>
#include <cmath>

using namespace std;

int main()
{    
    setlocale(LC_ALL, ".UTF-8");

    float x_input;
    cout << "Введите аргумент функции х (числом; 5 -13 6.1): ";
    cin >> x_input;

    float x = x_input;

    float function = pow(x, 2) * 2.4 + pow(sin(x), 3);

    int n = 1;
    float num = 0;

    do
    {    
        num += 1.0 / n;
        n++;

    } while(num < function);

    cout << "Наименьший n: " << n - 1 << endl;

    return 0;
}