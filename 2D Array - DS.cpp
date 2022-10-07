    int hourglassSum(int arr_rows, int arr_columns, int** arr) {
    int i,j,max,sum;
    max=arr[0][0]+arr[0][1]+arr[0][2]+arr[1][1]+arr[2][0]+arr[2][1]+arr[2][2];
    for(i=0;i<arr_rows-2;i++){
        for(j=0;j<arr_columns-2;j++){
            sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(max<sum)
                max=sum;
        }
    }
    return max;
}