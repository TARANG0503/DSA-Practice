#include <iostream>
using namespace std;

int countVowels(string str, int ptr)
{
    if (ptr >= str.size())
    {
        return 0;
    }

    if (str[ptr] == 'a' || str[ptr] == 'A' || str[ptr] == 'e' || str[ptr] == 'E' || str[ptr] == 'i' || str[ptr] == 'I' || str[ptr] == 'o' || str[ptr] == 'O' || str[ptr] == 'u' || str[ptr] == 'U')
    {
        return countVowels(str, ptr + 1) + 1;
    }
    else
    {
        return countVowels(str, ptr + 1);
    }
}

int main()
{
    string str;
    getline(cin, str);

    int count = countVowels(str, 0);

    cout << count << endl;

    return 0;
}