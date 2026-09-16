

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int MAX = 9; // максимальный размер матрицы 9 * 9
float matrix[MAX][MAX];

int get_number (string prompt);
int find_leader (int i, int cols, int rows, float matrix[MAX][MAX]);
void leader_swapper (float matrix[MAX][MAX], int cols, int leader_row, int target_row);
int leader_position (int i, int cols, float matrix[MAX][MAX]);
void calculus (int leader_row, int rows,int leader_col, int col, float matrix[MAX][MAX]);
void write_matrix (int rows, int cols, float matrix[MAX][MAX]);

int main()
{    
    setlocale(LC_ALL, ".UTF-8");

    int const rows = get_number("Количество строк матрицы (введите число; 5; максимум 9): ");
    int const cols = get_number("Количество столбцов матрицы (введите число; 5; максимум 9): ");

    for (int i = 0; i < rows; i++) // заполнение матрицы
    {    
        cout << "Введите элементы матрицы " << i + 1 << " строки (числами; 5 13 -9.9 ...) через пробел: ";
        for (int j = 0; j < cols; j++)
        {    
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {    
        int leader_row = find_leader(i, cols, rows, matrix);
            if (leader_row == -1) // проверка на нулевую матрицу
            {    
                break;
            }

        int target_row = i;
        leader_swapper(matrix, cols, leader_row, target_row);
        leader_row = i;

        int leader_col = leader_position(i, cols, matrix);

        calculus(leader_row, rows, leader_col, cols, matrix);
    }

    write_matrix (rows, cols, matrix);
    return 0;
    
}

int get_number (string prompt) // запрашивание положительного числа до 9
{    
    char input;
    int output;
    do
    {    
        cout << prompt;
        cin >> input;
        output = input - '0';

    } while(!isdigit(input) || output < 1 || output > 9);

    return output;
}

int find_leader (int num, int cols, int rows, float matrix[MAX][MAX]) // нахождение строки лидеа
{

    for (int i = 0; i < cols; i++)
    {    
        for (int j = num; j < rows; j++)
        {    
            if (matrix[j][i] != 0)
            {    
                return j; // нашли лидера
            }
        }
    }
    return -1;
}

void leader_swapper (float matrix[MAX][MAX], int cols, int leader_row, int target_row) // замена строки на строку лидера
{    
    for (int i = 0; i < cols; i++)
    {    
        float temp = matrix [target_row][i];
        matrix [target_row][i] = matrix[leader_row][i];
        matrix[leader_row][i] = temp;
    }
}

int leader_position (int i, int cols, float matrix[MAX][MAX])
{   
    int number;
    for (int j = 0 ; j < cols; j++)
        { 
            if (matrix[i][j] != 0)
            {    
                number = j;
                return number;
            }
        }
        return -1;
}

void calculus (int leader_row, int rows,int leader_col, int cols, float matrix[MAX][MAX])
{    
    for (int i = leader_row + 1; i < rows; i++)
    {    
        float multiplier = (-(matrix[i][leader_col] / matrix[leader_row][leader_col]));
        for (int j = leader_col; j < cols; j++)
        {    
            matrix[i][j] += matrix[leader_row][j] * multiplier;
        }
    }
}

void write_matrix (int rows, int cols, float matrix[MAX][MAX])
    {    
        cout << "Преобразованная матрица: " << endl;
        for (int i = 0; i < rows; i++)
        {    
            for(int j = 0; j < cols; j++)
            {     
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
