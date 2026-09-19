#include <iostream>

using namespace std;

int main ()
{    
    setlocale(LC_ALL, ".UTF-8");

    float number;
    float answer = 0;

    cout << "Выедите количество слогаемых: ";
    cin >> number;

    for (int i = 1; i <= number; i++)
    {    
        answer += i + (number / (3.5 * i * i));
    }

    cout << "Ответ: " << answer << endl;
    return 0;
}