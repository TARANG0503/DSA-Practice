long arrayManipulation(int n, vector<vector<int>> q) {
    vector<int> arr(n+2,0);
    for(long i=0;i<q.size();i++){
        arr[q[i][0]-1]+=q[i][2];
        arr[q[i][1]]+=-q[i][2];
    }
    long m=0,s=0;
    for(long i=0;i<n;i++){
        s+=arr[i];
        if(m<s){
            m=s;
        }
    }
    return m;
}