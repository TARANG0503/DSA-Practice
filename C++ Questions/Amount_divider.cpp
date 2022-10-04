
#include <iostream>
#include <math.h>
using namespace std;

int main()
{   cout<<"Enter Amount" <<endl;
    int a;
    int sau, pachas, bees, ek;
    cin>>a;
    
    switch(1){ //wriring 1 here because we want to start with case 1
        
        case(1): sau=a/100;
        cout<< "Sau ke" << sau<< "Notes"<<endl;
        
        a=a%100;
        
        case(2): pachas=a/50;
        cout << "Pachas ke" <<  pachas  <<"Notes"<<endl ;
        a=a%50;
        
        case(3): bees=a/20;
        cout<<"Bees ke"  <<  bees  << "notes"<<endl;
        
        a=a%20;
        
        case(4): ek=a/1;
        cout<< "Ek ke" <<  ek  <<"notes"<<endl;
        
        break;
        
        
        
        
        
        
        
        
        
    }
   

    return 0;
}