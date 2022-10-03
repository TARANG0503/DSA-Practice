class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
       int n = position.size();
        int l =1, r = 0,ans;
        sort(position.begin(),position.end());
        for(int i=0;i<n;i++)
        {
            r = max(position[i],r);
        }
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            // cout<<mid<<" ";
            int dist=0,cnt=1;
            for(int i=0;i<n-1;i++)
            {
                dist += (position[i+1]-position[i]);
                if(dist>=mid)
                {
                    cnt++;
                    dist=0;
                }
            }
            if(cnt<m)
            {
                r= mid-1;
            }
            else{
                l= mid+1;
                ans = mid;
            }
        }
        return ans;
    }
};