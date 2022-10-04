#include<iostream>
using namespace std;

void reachDestination(int src, int dest)
{
    cout << src;
    
    if(src == dest)
    {
        return;
    }

    src++;

    reachDestination(src, dest);
}

int main()
{
    int n;
    cin >> n;

    reachDestination(0, n);

    return 0;
}