#include <iostream>
using namespace std;

int updatedNumber(int a, int b, int l, int r)
{
    int x = l - 1;
    while ((1 << x) <= a && x < r)
    {
        if ((1 << x) & a)
        {
            b = (1 << x) | b;
        }
        x++;
    }
    return b;
}

int updatedNumberOptimised(int a, int b, int l, int r)
{
    int maskLength = r - l + 1;
    int mask = (1 << maskLength) - 1;
    mask = (mask << l - 1) & a;
    b = mask | b;
    return b;
}

int main()
{
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    // cout << updatedNumber(a,b,l,r); //logn time
    cout << updatedNumberOptimised(a, b, l, r); //constant time
    return 0;
}