#include <iostream>

using namespace std;

bool term1 (float x, float y);
bool term2 (float x, float y);
bool term3 (float x, float y);
bool term4 (float x, float y);

int main ()
{     
    setlocale(LC_ALL, ".UTF-8");

    float x, y;

    cout << "Область N6. Введите значения x и y (числами; 5 -13 3.3) через пробел: ";
    cin >> x >> y;

    if (term1(x,y) || term2(x,y) || term3(x,y) || term4(x,y))
    {    
        cout << "Точка принадлежит области N6" << endl;
        return 0;
    }

     cout << "Точка не принадлежит области N6" << endl;
     return -1;
}

bool term1 (float x, float y)
{    
    return ((x <= 2.0) && (x >= 1.0)) && ((y <= 2.0) && (y >= 1.0));
}

bool term2 (float x, float y)
{    
    return ((x >= -2.0) && (x <= -1.0)) && ((y <= 2.0) && (y >= 1.0));
}

bool term3 (float x, float y)
{    
    return ((x >= -1.0) && (x <= 0.0)) && ((y >= -1.0) && (y <= 0.0)) && (x + y >= -1.0);
}

bool term4 (float x, float y)
{    
    return ((x >= 0.0) && (x <= 1.0)) && ((y >= -1.0) && (y <= 0.0)) && ((x + y >= -1.0) && (x - y <= 1));
}