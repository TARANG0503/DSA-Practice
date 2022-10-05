#include <iostream>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return a;
    }

    int pow = power(a, b / 2);

    if (b % 2 == 0)
    {
        return pow * pow;
    }
    else
    {
        return a * pow * pow;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = power(a, b);

    cout << ans;
}