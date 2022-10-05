/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int row = 0 , column = 0;;

    vector<vector<int>> matrix(5 , vector<int>(5));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>matrix[i][j];

            if(matrix[i][j] == 1){


                row = j;
                column = i;

            }
        }
        
    }

    cout<<(abs(2-row) + abs(2-column))<<endl;

    return 0;
}