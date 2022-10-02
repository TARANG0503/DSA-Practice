#include <iostream>
using namespace std;

int main()
{

    int n;
    cin>>n;
    
    int row=1;

    while(row <= n){
        int col=1;

        while (col<=row){
            char ch= ('A'+row-1); // pattern 1 
            //char ch= ('A'+row+col-2); // pattern 2 
            cout<<ch<<" ";
            col= col+1;
        }

        cout<<endl;
        row= row+1;
    }
}