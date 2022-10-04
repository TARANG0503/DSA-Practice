#include<iostream>
using namespace std;

int main(){

    int series[1003],j=1;
    for(int i=1;i<=1666;i++){
        if(((i)%3==0)||(i-3)%10==0){
            continue;
        }
        else{
            series[j]=i;
            j++;
        }
    }

    int testcase,inp;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>inp;
        cout<<series[inp]<<"\n";
    }

    return 0;
}

