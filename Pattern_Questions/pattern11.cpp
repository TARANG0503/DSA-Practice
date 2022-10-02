#include <iostream>
using namespace std;    

int main(){
    int n;
    cin>> n;
    int row =1;
    while( row <= n){

      // Print karo space 1st triangle 
        int space = n - row;

        while( space){
            cout<< " ";
            space = space -1;


        }
      // Print 2nd Trianle 
       int j= 1;
       while( j <= row){
        cout<< j<< " ";
        j = j+1;
       }



      // Print 3rd Triangle
      int start = row -1;
      while ( start){

        cout<< start<<" ";
        start = start -1;

      }




      cout<< endl;
      row = row +1 ;

    }
}