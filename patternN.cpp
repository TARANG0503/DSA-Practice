#include<iostream>
using namespace std;
int main(){
	int m;
	cout<<"Enter the size: ";
	cin>>m;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(j==0 || j==m-1 || j==i){
				cout<<'#';
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}
