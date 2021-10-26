/*
Send Feedback
You have been given an empty array(ARR) and its size N. The only input taken from the user will be N and you need not worry about the array.
Your task is to populate the array using the integer values in the range 1 to N(both inclusive) in the order - 1,3,.......4,2.
Note:
You need not print the array. You only need to populate it.
*/
#include "iostream"
using namespace std;
int main(){
    int numberOfArray;
    int arr[100];
    cin >> numberOfArray;
    int counter = 0;
    while(counter<numberOfArray){
        cin >> arr[counter];
        counter++;
    }
    for(int i = 0;i<numberOfArray;i++){
        counter = 0;
        int mainCounter = 1;
        bool conditon = true;
        while (counter<arr[i]){
            cout<< mainCounter<< " ";
            if(mainCounter==arr[i] && conditon){
                mainCounter++;
                conditon = false;
            }
            if(conditon){
                mainCounter+=2;
            }else{
                mainCounter-=2;;
            }
            if(mainCounter>arr[i] && conditon){
                mainCounter--;
                conditon= false;
            }
            counter++;
        }
        cout << endl;
    }


}