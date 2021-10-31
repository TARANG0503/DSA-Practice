#include<iostream>
using namespace std;

int calculateFactorial(int);
int main() {
  int number,factorial;

  cin>>number;
  factorial=calculateFactorial(number);
  cout<<factorial;
  return 0;
}

int calculateFactorial(int number) {
 if (number==0) {
  return 1;
 } else {
  return (number*(calculateFactorial(number-1)));
 }
}