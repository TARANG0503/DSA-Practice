/*
 * Implement a complex number class with constructor, addition of 2 complex numbers & multiplication of two complex numbers
 */
#include "iostream"
using namespace std;
class ComplexNumber{
private:
    int real;
    int imaginary;
public:

    ComplexNumber(int real, int imaginary){
        this->real = real;
        this->imaginary= imaginary;
    }

    void print(){
        cout << real <<" + "<< imaginary <<"i";
    }

    void add(ComplexNumber const &c1){
        real = real + c1.real;
        imaginary = imaginary + c1.imaginary;
    }

    void multiplication(ComplexNumber const &c1){
        int tempReal = (real * c1.real) - (imaginary*c1.imaginary);
        imaginary = (real*c1.imaginary) + (imaginary*c1.real);
        real = tempReal;
    }
};

int main(){
    int real1,real2,img1,img2;
    cin >> real1>>img1>>real2>>img2;
    ComplexNumber c1(real1,img1);
    ComplexNumber c2(real2, img2);
    int choice;
    cout << "Enter your choice 1 for addition & 2 for multiplication: ";
    cin>> choice;
    if(choice==1){
        c1.add(c2);
    }else{
        c1.multiplication(c2);
    }
    c1.print();
    cout << endl;

}