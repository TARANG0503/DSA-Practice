//Leetcode : https://leetcode.com/problems/intersection-of-two-arrays


class Solution {
public:
    vector<int> intersection(vector<int>& vec1, vector<int>& vec2) {
        int n1 = vec1.size() ; 
        int n2 = vec2.size() ; 

        sort(vec1.begin() , vec1.end());
	    sort(vec2.begin() , vec2.end());

        map<int,bool> mp1 ; 
	for (int i = 0; i < n1; ++i)
	{
		mp1[vec1[i]] = true ; 
	}

	map<int,bool> mp2 ; 
	for (int i = 0; i < n2; ++i)
	{
		mp2[vec2[i]] = true ; 
	}


	vector<int> ans ; 
	for(auto & i : mp1){
		if (mp2[i.first] == true)
		{
			ans.push_back(i.first) ; 
		}
	}


    return ans ; 

        
        
    }
};