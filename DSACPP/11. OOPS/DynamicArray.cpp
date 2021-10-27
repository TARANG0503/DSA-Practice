/*
 * Dynamic array class implementation
 */
#include "iostream"
using namespace std;

class DArray{
private:
    int *arr;
    int capacity;
    int nextIndex;

    void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
public:
    DArray(){
        arr = new int[5];
        capacity = 5;
        nextIndex =0;
    }

    void add(int const &element){
        if(capacity==nextIndex){
            int *newArr = new int[2*capacity];
            for(int i= 0;i<capacity;i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
            capacity = 2*capacity;
        }
        arr[nextIndex] =element;
        nextIndex++;
    }

    int size() const{
        return nextIndex;
    }

    int get(int index) const{
        if(index<0 || index>=nextIndex){
            return -1;
        }
        return arr[index];
    }

    void show() const{
        cout<< "{ ";
        for(int i=0;i<nextIndex;i++){
            cout<<arr[i]<<", ";
        }
        cout<<"}";
    }

    void addAt(int const &index,int const &element){
        if(index<nextIndex) arr[index] = element;
        else if(index==nextIndex) add(element);
        else cout << "Error occurred wrong index";
    }
};

int main(){
    DArray myarr;
    myarr.add(10);
    myarr.add(2);
    myarr.add(21);
    myarr.add(22);
    myarr.add(222);
    myarr.add(55);
    myarr.add(62);
    myarr.addAt(7,222);
    myarr.show();
    cout << endl<<myarr.size()<<endl;
}