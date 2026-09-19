#include <iostream>

using namespace std;

int main()
{    
    setlocale(LC_ALL, ".UTF-8");

    char letter;

    cout << "Введите один из следующих 5 букв: P, U, R, L, M: ";
    cin >> letter;

    switch (letter){    
        case 'P':
        cout << "Portugal" << endl;
        break;

        case 'U':
        cout << "Uruguay" << endl;
        break;

        case 'R':
        cout << "Russia" << endl;
        break;

        case 'L':
        cout << "Lithuania" << endl;
        break;
    
        case 'M':
        cout << "Mexico" << endl;
        break;

        default:
        cout << "Ошибка: введёна буква не из предложенного набора" << endl;
        return -1;
    }

    return 0;
}