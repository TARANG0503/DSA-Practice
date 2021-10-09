#include<bits/stdc++.h>
using namespace std;

void NQueens(int n,vector<int> temp,vector<vector<int> >& queens,int j){
       /* cout<<"temp: "<<endl;
         for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        */
        
        if(temp.size()>1){
            for(int i=0;i<temp.size()-1;i++){
               if(abs(temp[temp.size()-1]-temp[i])==0 || abs(j-i-1)==abs(temp[temp.size()-1]-temp[i])){
                  return;
               }

            }
            
        }
        
        if(j==n){
          queens.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            temp.push_back(i);
            //cout<<"j="<<j<<endl;
            NQueens(n,temp,queens,j+1);
            temp.pop_back();
        }
        
        return;
    }
    
vector<vector<string> > solveNQueens(int n) {
         vector<vector<int> > queens;
        vector<vector<string> > Nqueens;
         vector<int> temp;
         NQueens(n,temp,queens,0);
         //cout<<"queens: "<<endl;
         string s(n,'.');
        vector<string> sq;
        for(int i=0;i<queens.size();i++){
            for(int j=0;j<queens[i].size();j++){
                //cout<<queens[i][j]<<" ";
                s[queens[i][j]]='Q';
                sq.push_back(s);
                s[queens[i][j]]='.';
            }
            Nqueens.push_back(sq);
            sq.clear();            
            //cout<<endl;
        }
        
        return Nqueens;
}

int main(){
	
	int n=4;
	vector<vector<string> > result = solveNQueens(n);
	for(int i=0;i<result.size();i++){
		cout<<"[";
		for(int j=0;j<result[0].size();j++){
			cout<<result[i][j]<<",";
		}
		cout<<"]"<<endl;
		
	}
	
	return 0;
}
    
    
