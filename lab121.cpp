#include <iostream>
#include <random>

using namespace std;

const int ARR = 4;
const int MAX = 7;

int randomizer (int x, int y);
void print_array (int quantities[ARR], int my_array[][MAX]);
void sum_fun (int n, int quantitie, int my_array[][MAX], int sum[]);
void print_sum (int sum[]);

int main()
{    
    setlocale (LC_ALL, ".UTF-8");

    int k;
    
    int my_array[ARR][MAX];
    int quantities[ARR];
    int sum[ARR];

    cout << "Введите число: ";
    cin >> k;

    for (int i = 0; i < ARR; i++)
    {    
        quantities[i] = randomizer(1, 7); // (начальная точка, максимум, нужное количество) // размер массива
        for (int j = 0; j < quantities[i]; j++)
        {    
            my_array[i][j] = randomizer(k, k*3);
        }
        sum_fun (i, quantities[i], my_array, sum);
    }

    print_array (quantities, my_array);

    char letter;
    cout << "Нужна сумма элементов кратных трем в каждом массиве? [y/n]: ";
    cin >> letter;

    switch (letter){
        case 'n':
        return 0;

        case 'y':
        print_sum(sum);
        return 0;
    }
}

int randomizer (int x, int y)
{    
    random_device seed;
    mt19937 gen(seed());
    uniform_int_distribution<int> dist(x, y);
    int generated_num = dist(gen);
    return generated_num;
}
    
void print_array (int quantities[ARR], int my_array[][MAX])
{    
    for (int i = 0; i < ARR; i++)
    {    
        cout << "Array" << i << ": ";

        for (int j = 0; j < quantities[i]; j++)
        {    
            cout << my_array[i][j] << " ";
        }
        cout << endl;
    }
}

void print_sum (int sum[])
{    
    for (int i = 0; i < ARR; i++)
    {    
        cout << "Sum of Array" << i << ": " << sum[i] << endl;
    }
}

void sum_fun (int n, int quantitie, int my_array[][MAX], int sum[])
{    
    sum[n] = 0;
    for (int i = 0; i < quantitie; i++)
    {    
        if (my_array[n][i] % 3 == 0)
        {    
            sum[n] += my_array[n][i];
        }
    }
}