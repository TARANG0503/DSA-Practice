int minimumSwaps(vector<int> arr) {
    int count=0,ans=0;
    int n=arr.size();
    vector<int> vis;
    vis.resize(1000000,0);
    int i,f=0;
    for(i=0;i<n;i++){
        if(arr[i]!=n-i){
            f=1;
            break;
        }
    }
    if(f==0){
        return (n/2);
    }
    for(i=0;i<n;i++){
        if(arr[i]==i+1){
            vis[i+1]=1;
        }
        else{
            break;
        }
    }
    int k;
    cout << i << endl;
    for(int j=i;j<n-1;j++){
        while(vis[j+1]!=1){
            vis[j+1]=1;
            cout << j+1 << "->";
            k=arr[j];
            if(vis[k]==1){
                break;
            }
            else{
                count++;
            }
            j=k-1;
        }
        cout<<endl;
        ans+=count;
        count=0;
    }
    return ans;
}
