#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int row=1;
    while(row<=n)
    {
        int col=1;
        while(col<=row)
        {
            cout<<row<<" "; // agar star ki jagah row ka number print karna hain
            col=col+1;
        }
        cout<< endl;
        row = row+1;
    }
}