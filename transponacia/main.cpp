// transponacia
#include <iostream>

using namespace std;

void transposeMatrix(char matrix[][3], int rows, int cols)
{
    int transposed[3][3];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            matrix[i][j] = transposed[i][j];
        }
    }
}

void displayMatrix(char matrix[][3], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    char matrix[3][3] = {{'b', 'a', 'r'}, {'e', 'v', ' '}, {'h', 'a', 'y'}};

    cout << "Original matrix:" << endl;
    displayMatrix(matrix, 3, 3);

    transposeMatrix(matrix, 3, 3);

    cout << "Transposed matrix:" << endl;
    displayMatrix(matrix, 3, 3);

    return 0;
}