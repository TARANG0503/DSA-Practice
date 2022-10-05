class Solution {
public:
     void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size();j++)
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }

        for(auto x: rows) 
            for(int j = 0; j < matrix[0].size();j++) 
                    matrix[x][j] = 0;

        for(auto x: cols) 
            for(int i = 0; i < matrix.size(); i++) 
                matrix[i][x] = 0;
  
    }
};