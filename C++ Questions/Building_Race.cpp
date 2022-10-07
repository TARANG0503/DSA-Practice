/*Problem
Two friends Chef and Chefina are currently on floors A and B respectively. 
They hear an announcement that prizes are being distributed on the ground floor and so decide to reach the ground floor as soon as possible.
Chef can climb down X floors per minute while Chefina can climb down Y floors per minute. 
Determine who will reach the ground floor first. In case both reach the ground floor together, print Both.
*/


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    float A, B, X, Y;
	    float chef_reaches, chefina_reaches;
	    
	    cin>>A>>B>>X>>Y;
	    
	    chef_reaches = A/X;
	    chefina_reaches = B/Y;
	    
	    if(chef_reaches > chefina_reaches)
	    {
	        cout<<"Chefina"<<endl;
	    }
	    else if(chef_reaches == chefina_reaches)
	    {
	        cout<<"Both"<<endl;
	    }
	    else
	    {
	        cout<<"Chef"<<endl;
	    }
	    
	}
	return 0;
}
