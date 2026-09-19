#include <iostream>

using namespace std;

bool centre (float x, float y);
bool term1 (float x, float y);
bool term2 (float x, float y);
bool term3 (float x, float y);
bool term4 (float x, float y);

int main ()
{     
    setlocale(LC_ALL, ".UTF-8");

    float x, y;

    cout << "Область N4. Введите значения x и y (числами; 5 -13 3.3) через пробел: ";
    cin >> x >> y;

    if (centre (x,y) && (term1(x,y) || term2(x,y) || term3(x,y) || term4(x,y)))
    {    
        cout << "Точка принадлежит области N4" << endl;
        return 0;
    }

     cout << "Точка не принадлежит области N4" << endl;
     return -1;
}

bool centre (float x, float y)
{    
    return ((x <= -2.0) || (x >= 2.0)) && ((y <= -2.0) || (y >= 2.0)) && (x*x + y*y >= 4.0);
}

bool term1 (float x, float y)
{    
    return (x <= 4.0) && (y <= 4.0);
}

bool term2 (float x, float y)
{    
    return (x >= -4.0) && (y <= 4.0) && (x*x + y*y <= 16);
}

bool term3 (float x, float y)
{    
    return (x >= -4.0) && (y >= -4.0) && (x + y <= -4.0);
}

bool term4 (float x, float y)
{    
    return (x <= 4.0) && (y >= -4.0) && (x*x + y*y <= 16);
}