int* rotLeft(int n, int* a, int d, int* result_count) {
    int j=0;
    int arr[n];
    for(int i=d;i<n;i++){
        arr[j++]=a[i];   
    }
    for(int i=0;i<d;i++){
        arr[j++]=a[i];   
    }
    for(int i=0;i<n;i++){
        a[i]=arr[i];   
    }
    *result_count=n;
    return a;
}