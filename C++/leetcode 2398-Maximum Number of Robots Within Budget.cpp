class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        int n = ct.size();
        //Two Pointer
        int l = 0, r = 0;
        int ans = 0;
        long long sum = rc[0];
        multiset<int> ms;
        ms.insert(ct[0]);
        while(r<n){
            if(*ms.rbegin() + (r-l+1)*sum > budget){
                auto it = ms.find(ct[l]);
                ms.erase(it);
                sum -= rc[l];
                l++;
                r++;
                if(r<n){
                    ms.insert(ct[r]);
                    sum += rc[r];
                }
            }
            else{
                ans = max(ans, r-l+1);
                r++;
                if(r<n){
                    ms.insert(ct[r]);
                    sum += rc[r];
                }
            }
        }
        return ans;
    }
};
