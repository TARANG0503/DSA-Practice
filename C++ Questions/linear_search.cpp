#include <iostream>
#include <math.h>
using namespace std;

bool search(int arr[], int size, int key)
{

    for (int i = 0; i < size; i++)
    {

        if (arr[i] == key)
        {
            return 1;
        }

        
    }
    return 0;
}

int main()
{
    int arr[] = {4, 9, -3, 5, 3, -5, 10, -1, -7};
    int key;

    cout << "Enter the key to be find:- " << endl;
    cin>> key;

    bool check = search(arr, 15, -key);

    if (check==1)
    {
        cout << "Key is present" << endl;
    }
    else
    {
        cout << "Key is not present" << endl;
    }
}