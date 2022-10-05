//Hacktoberfest2022


/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
		int n = t.size();

		for(int i = n-2; i >= 0; i--){
			for(int j = 0; j < t[i].size(); j++){
				t[i][j] = t[i][j] + min(t[i+1][j] , t[i+1][j+1]);
			}
		}

		return t[0][0];
	}
};



/*
Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
*/
