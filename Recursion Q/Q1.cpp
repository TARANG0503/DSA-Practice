#include <iostream>
using namespace std;

void printSpirally(int **arr, int rowStart, int rowEnd, int colStart, int colEnd, int count, int totalElements)
{
    if (count >= totalElements)
    {
        return;
    }

    for (int i = colStart; i <= colEnd && count < totalElements; i++)
    {
        cout << arr[rowStart][i] << " ";
        count++;
    }
    rowStart++;

    for (int i = rowStart; i <= rowEnd && count < totalElements; i++)
    {
        cout << arr[i][colEnd] << " ";
        count++;
    }
    colEnd--;

    for (int i = colEnd; i >= colStart && count < totalElements; i--)
    {
        cout << arr[rowEnd][i] << " ";
        count++;
    }
    rowEnd--;

    for (int i = rowEnd; i >= rowStart && count < totalElements; i--)
    {
        cout << arr[i][colStart] << " ";
        count++;
    }
    colStart++;

    printSpirally(arr, rowStart, rowEnd, colStart, colEnd, count, totalElements);
}

int main()
{
    int row, col;
    cin >> row >> col;

    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    int rowStart = 0;
    int rowEnd = row - 1;
    int colStart = 0;
    int colEnd = col - 1;

    int count = 0;
    int totalElements = row * col;

    printSpirally(arr, rowStart, rowEnd, colStart, colEnd, count, totalElements);

    return 0;
}