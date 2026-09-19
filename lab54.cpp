#include <iostream>

using namespace std;

int main()
{    
    setlocale(LC_ALL, ".UTF-8");

    char sign;

    cout << "Введите один из следующих 8 символов: ( *  <  !  >  %  ?  =  + ): ";
    cin >> sign;

    switch (sign){    
        case '*':
        cout << "Умножение" << endl;
        break;

        case '<':
        cout << "Меньше" << endl;
        break;

        case '!':
        cout << "Восклицательный знак" << endl;
        break;

        case '>':
        cout << "Больше" << endl;
        break;
    
        case '%':
        cout << "Проценты" << endl;
        break;

        case '?':
        cout << "Вопросительный знак" << endl;
        break;

        case '=':
        cout << "Равно" << endl;
        break;

         case '+':
        cout << "Плюс" << endl;
        break;

        default:
        cout << "Ошибка: введён символ не из предложенного набора" << endl;
        return -1;
    }

    return 0;
}