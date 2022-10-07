void minimumBribes(int n, int* que) {
    int ans=0,st;
    for(int i=n-1;i>=0;i--){
        if((que[i]-(i+1))>2) {
            printf("Too chaotic\n");
            return;
        }
        if(0>=que[i]-2){
            st=0;
        }
        else{
            st=que[i]-2;
        }
        for(int j=st;j<i;j++)
            if (que[j]>que[i]) 
                ans++;
    }
    printf("%d\n",ans);
}