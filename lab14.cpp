#include <iostream>
#include <random>

using namespace std;

const int ARR = 3;
const int MAX_ROW = 5;
const int MAX_COL = 6;
float matrix[ARR][MAX_ROW][MAX_COL];
int count[ARR];

int get_number (string prompt, int x, int y);
float randomizer (int x, int y);
void matrix_fill (int n, int x, int y, int row, int col, float matrix[ARR][MAX_ROW][MAX_COL]);
void print_matrix (int row, int col, int n);
void count_matrix (int row, int col, float matrix[ARR][MAX_ROW][MAX_COL], int n, int count[ARR]);
void print_name (int n);



int main()
{    
    setlocale(LC_ALL, ".UTF-8");

    int row = get_number("Введите количество строк (от 2 до 5): ", 2, 5);
    int col = get_number("Введите количество столбцов (от 2 до 6): ", 2, 6);

    float k;
    cout << "Введите число k (1.5 <= k <= 4.5) для диапазона значений элементов матрицы: ";
    cin >> k;

    for (int i = 0; i < ARR; i++)
    {    
        matrix_fill(i, -k, 2.0*k, row, col, matrix);
    }

    for (int i = 0; i < ARR; i++)
    {    
        print_matrix(row, col, i);
        count_matrix(row, col, matrix, i, count);
    }

    print_name(ARR);
    return 0;

}

int get_number (string prompt, int x, int y)
{    
    int value;
    do
    {    
        cout << prompt;
        cin >> value;
    } while (value < x || value > y);
    return value;
}

float randomizer (int x, int y)
{    
    random_device seed;
    mt19937 gen(seed());
    uniform_real_distribution<float> dist(x, y);
    float generated_num = dist(gen);
    return generated_num;
}

void matrix_fill (int n, int x, int y, int row, int col, float matrix[ARR][MAX_ROW][MAX_COL])
{    
    for (int i = 0; i < row; i++)
    {    
        for (int j = 0; j < col; j++)
        {    
            matrix[n][i][j] = randomizer(x, y);
        }
    }
}

void print_matrix (int row, int col, int n)
{    
    cout << "Матрица " << n + 1 << " : " << endl;
    for (int i = 0; i < row; i++)
    {    
       
        for (int j = 0; j < col; j++)
        {    
            cout << matrix[n][i][j] << " ";
        }
        cout << endl;
    }
}

void count_matrix (int row, int col, float matrix[ARR][MAX_ROW][MAX_COL], int n, int count[ARR])
{
    count[n] = 0;
    for (int i = 0; i < row; i += 2)
    {    
        for (int j = 0; j < col; j++)
        {    
            if (matrix[n][i][j] < 0)
            {    
                count[n]++;
            }
        }
    }
}

void print_name (int ARR)
{   
    cout << "Имеет(ют) четное количество отрицательных элементов в нечетных строках:" << endl;
    for (int i = 0; i < ARR; i++)
    {     
        if (count[i] > 0 && count[i] % 2 == 0)
        {    
            cout << "Матрица " << i + 1 << " ";
        }
    }
}