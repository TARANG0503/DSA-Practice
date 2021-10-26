/*
Code : Diamond of stars
Print the following pattern for the given number of rows.
Note: N is always odd.
Pattern for N = 5
  *
 ***
*****
 ***
  *

 */
#include
"iostream"
using namespace std;
int main(){
int numberOfLines;
cout << "Enter the number of lines: ";
cin >> numberOfLines;
bool passedMiddle = false;
int counter = 1; // Number of stars in a line
int numberOfSpace = (numberOfLines+1) / 2; // Calculating number of space
for (int i =0;i<numberOfLines;i++){
for (int space = 1;space<numberOfSpace;space++){
cout << " ";
}
for (int star = 0; star<counter;star++){
cout << "*";
}

if (i==((numberOfLines+1)/2) -1){
passedMiddle = true;
}
if (passedMiddle){
numberOfSpace++;
counter-=2;
} else{
numberOfSpace--;
counter+=2;
}
cout << endl;
}

}