class Solution {
public:
    bool row[9][9], col[9][9], grid[9][9];
    bool fun(int i, int j, vector< vector<char>>& a) {
        if (i == 9)
            return true;
        if (j == 9) 
            return fun(i + 1, 0, a);
        if (a[i][j] != '.')
            return fun(i, j + 1, a);
        for (int dig = 0; dig <= 8; ++dig) {
            if (row[i][dig] or col[j][dig] or grid[3 * (i / 3) + (j / 3)][dig])
                continue;
            a[i][j] = '0' + dig + 1;
            grid[3 * (i / 3) + (j / 3)][dig] = row[i][dig] = col[j][dig] = true;
            if (fun(i, j + 1, a) == true)
                return true;
            a[i][j] = '.';
            grid[3 * (i / 3) + (j / 3)][dig] = row[i][dig] = col[j][dig] = false;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& a) {
        for (int i = 0; i < 9; ++i) {
            fill(row[i], row[i] + 9, false);
            fill(col[i], col[i] + 9, false);
            fill(grid[i], grid[i] + 9, false);
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (a[i][j] != '.') {
                    int dig = a[i][j] - '0' - 1;
                    grid[3 * (i / 3) + (j / 3)][dig] = row[i][dig] = 
                        col[j][dig] = true;
                }
            }
        }
        fun(0, 0, a);
    }
};
