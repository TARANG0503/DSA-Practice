



#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    vector<int> vect;
    while (num!=0)
    {
        int temp;
        temp=num%10;
        vect.push_back(temp);
        num=num/10;
    }


    sort(vect.begin(),vect.end());

    cout << (vect[0]*10 + vect[2])+(vect[1]*10 + vect[3]);
    
}