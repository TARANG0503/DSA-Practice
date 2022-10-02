class Solution {
public:
    bool isPres(int row, int col, int xMv, int yMv, int& n, vector<vector<bool>>& isTkn){
        while((row>=0)&&(row<n)&&(col>=0)&&(col<n)){
            if(isTkn[row][col]){
                return true;
            }
            row+=xMv; 
            col+=yMv;
        }
        
        return false;
    }
    int recFn(int row, int& n, vector<vector<bool>>& isTkn){
        if(row==n){
            return 1;
        }
        
        int res=0;
        for(int col=0; col<n; col++){
            // Checking top.
            if(isPres(row, col, -1, 0, n, isTkn)){
                continue;
            }
            
            // Checking top-left.
            if(isPres(row, col, -1, -1, n, isTkn)){
                continue;
            }
            
            // Checking top-right.
            if(isPres(row, col, -1, 1, n, isTkn)){
                continue;
            }
            
            isTkn[row][col]=true;
            res+=recFn(row+1, n, isTkn);
            isTkn[row][col]=false;
        }
        
        return res;
    }
    int totalNQueens(int n) {
        vector<vector<bool>> isTkn(n, vector<bool>(n, false));
        return recFn(0, n, isTkn);
    }
};
