#include <iostream>
#include <random>

using namespace std;

const int MAX = 10;
float my_array[MAX];

int count = 0;

float randomizer (float x, float y);
void print (float size, float my_array[MAX], int count, float sum_array);
float sum(float size, float my_array[MAX], float max_value, int &count);
float maxval (float my_array[MAX], int size);

int main()
{    
    setlocale(LC_ALL, ".UTF-8");

    float p;

    do 
    {    
        cout << "Введите число >= 2: ";
    cin >> p;
    } while(p < 2);
    
    float raw_size = randomizer(1.0, 10.0);
    int size = static_cast<int>(raw_size + 0.5);

    for (int i = 0; i < size; i++)
    {    
        my_array[i] = randomizer(0.5*p, 3.5*p);
    }

    float max_value = maxval(my_array, size);
    float sum_array = sum(size, my_array, max_value, count);
    print(size, my_array, count, sum_array);
    return 0;
    
}

float randomizer (float x, float y)
{    
    random_device seed;
    mt19937 gen(seed());
    uniform_real_distribution<float> dist(x, y);
    float generated_num = dist(gen);
    return generated_num;
}

float sum(float size, float my_array[MAX], float max_value, int &count)
{   
    float sum = 0;
    for (int i = 0; i < size; i++)
    { 
        if (my_array[i] < max_value / 2.0)
        {    
            sum += my_array[i];
            count++;
        }
        
    }
    return sum;
}

void print (float size, float my_array[MAX], int count, float sum_array)
    {    
        cout << "Массив: " << endl;
    for (int i = 0; i < size; i++)
    {    
        cout << my_array[i] << endl;
    }

    if (count != 0)
    {    
        cout << "Среднее арифметическое: " << sum_array / count << endl;
    }
    }

float maxval (float my_array[MAX], int size)
{    
    float max_value = my_array[0];

    for (int i = 0; i < size; i++)
    {    
        if (my_array[i] >= max_value)
        {    
            max_value = my_array[i];
        }
    }
    return max_value;
}
    