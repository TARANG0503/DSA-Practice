#include<limits.h>
bool isPossibleSolution(vector<int> &stalls, int k,int mid){
    int count=1,diff,lastpos=0;
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-stalls[lastpos]>=mid){
            count++;
            lastpos=i;
            if(count==k){
                return true;
            }
        }
        if(count>=k){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(),stalls.end());
    int maxi=0,mini=INT_MAX;
    for(int i=0;i<stalls.size();i++){
        maxi=max(maxi,stalls[i]);
        mini=min(mini,stalls[i]);
    }
    int s=0,e=maxi-mini,ans=0;
    int mid=s+(e-s)/2;
    while(s<=e){
        mid=s+(e-s)/2;
        if(isPossibleSolution(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
