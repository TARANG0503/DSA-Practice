/*
Linear Search Implementation
*/

#include "iostream"
using namespace std;

int main(){
    int arr[100];
    int size;
    int number;
    bool found = false;
    cout << "Enter the size: ";
    cin >> size;//Taking the size of array manually
    cout << "Enter the number you want to find: ";
    cin >> number;
    int counter = 0;
    while(counter < size){
        cout << "Enter the element at " << counter << " index: ";
        cin >> arr[counter]; // taking array input
        counter++;
    }
    counter = 0;
    while(counter<size){ // searching one by one
        if(arr[counter] == number){
            found = true;
            break;
        }
        counter++;
    }
    if(found){
        cout << "The element you looking for is at " << counter << " index.";
    } else{
        cout << "not in the array";
    }
    cout << endl;
}