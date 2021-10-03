#include <iostream>
using namespace std;

// function for bubble sort
void bubbleSort(int array[], int size) {

  // running a loop to access each array element
  for (int step = 0; step < (size-1); ++step) {
      
    // running a loop to compare the array elements
    for (int i = 0; i < size - (step-1); ++i) {

      // after the comparison between two consecutive array elements
      // modify > to < for descending order sorting
      if (array[i] > array[i + 1]) {

        // if elements are not in order
        // swap
        int tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
      }
    }
  }
}

// function to print the array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

// main function
int main() {
  int data[] = {-15, 5, 20, -2, 104, -98, 50};
  
  // evaluate length of the array
  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
  cout << "Sorted Array in Ascending Order:\n";  
  printArray(data, size);
}
