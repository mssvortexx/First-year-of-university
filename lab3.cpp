// 1) спросить + сохранить координаты
// 2) посчитать длины сторон + диагональ
// 3) посчитать полупериметры половин
// 4) посчитать площади половин
// 5) сложить площади
// 6) выдать ответ

#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

const int PAIRS = 4;
const int ELMS = 2;

float process(float x1, float x2, float y1, float y2);
float count_p(float a1, float a2, float a3);
float figure_area(float p, float a1, float a2, float a3);

int main()
{     
    setlocale(LC_ALL, ".UTF-8"); // русский язык

    float x[PAIRS]; // все значения х
    float y[PAIRS]; // все значения у
    float lines[PAIRS]; // все длины сторон четырехугольника


    for(int i = 0; i < PAIRS; i++) // цикл, что бы сохранить все значения х, у
    {   
        char input_x, input_y;

        do
        {
            cout << "Введите x"<< i + 1 << " и y"<< i + 1 << " через пробел (числами; -2 7.7): ";
            cin >> input_x >> input_y;
        } while (!isdigit(input_x) || !isdigit(input_y));
        
        x[i] = input_x - '0';
        y[i] = input_y - '0';
    }

    for(int i = 0; i < PAIRS; i++) // считаем длины сторон по теореме пифагора
    {    
        lines[i] = process(x[i], x[(i + 1) % 4], y[i], y[(i + 1) % 4]);
    }

    float diagonal = process(x[0], x[2], y[0], y[2]); // диальналь отдельно, ~ для треугольников (*можно вписать в цикл??)
    
    float p1 = count_p(lines[0], lines[1], diagonal); // расчёт полупериметров (*мб улучшить??)
    float p2 = count_p(lines[2], lines[3], diagonal);

    float S1 = figure_area(p1, lines[0], lines[1], diagonal); // расчёт площадей (*опять повторяется)
    float S2 = figure_area(p2, lines[2], lines[3], diagonal);

    cout << "Площадь четырёхугольника = "<< S1 + S2 << endl;
    return 0;
}

float process(float x1, float x2, float y1, float y2) // стороны по теореме пифагора
{    
    return sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float count_p(float a1, float a2, float a3) // функция для полупериметра
{    
    return (a1 + a2 + a3) / 2.0;
}

float figure_area(float p, float a1, float a2, float a3) // функция для площади по герону
{    
    return sqrt (p * (p - a1) * (p - a2) * (p - a3));
}
