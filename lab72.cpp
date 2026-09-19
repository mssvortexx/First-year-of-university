#include <iostream>

using namespace std;
const int FLOOR = 5;
int NUM = 9;
    
void print (int x, int NUM);

int main()
{    
    for(int i = 1; i <= FLOOR; i++)
    {    
        print(i, NUM);
        NUM--;
    }

}

void print (int x, int NUM)
{    
    for (int i = 0; i < x; i++)
    {    
        cout << NUM;
    }
    cout << endl;
}