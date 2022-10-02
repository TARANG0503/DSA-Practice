class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        // miSums[i] is the minimum sum of gas and cost till the ith.
        vector<int> miSums(n, 0);
        int currSum=0, miSum=0;
        for(int i=0; i<n; i++){
            currSum+=gas[i];
            currSum-=cost[i];
            miSum=min(miSum, currSum);
            miSums[i]=miSum;
        }
        
        if((currSum>=0)&&(miSum>=0)){
            return 0;
        }
        
        int total=currSum;
        currSum=gas[0]-cost[0];
        for(int i=1; i<n; i++){
            // We will check right.
            // All the gas will be from
        }
    }
};
