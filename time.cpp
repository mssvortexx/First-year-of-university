// 1) спросить время в секундах
// 2) выделить целые минуты
// 3) выделить целые часы
// 4) выдать ответ

#include <iostream>
using namespace std;

int main()
{    
    setlocale(LC_ALL, ".UTF-8"); //русский язык

    int time;

    cout << "Введите время в секундах: "; 
    cin >> time;

    int minutes = time / 60; 
    int seconds = time % 60;
    int hours = minutes / 60;
    minutes %= 60;

    cout << "Ответ: "<< hours <<" ч.; "<< minutes <<" мин.; "<< seconds <<" сек." << endl;
    return 0;
}