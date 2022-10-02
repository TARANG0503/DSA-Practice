#include <stdio.h>  
int main()  
{  
    // Sparse matrix having size 4*5  
    int sparse_matrix[4][5] =  
    {  
        {0 , 0 , 6 , 0 , 9 },  
        {0 , 0 , 4 , 6 , 0 },  
        {0 , 0 , 0 , 0 , 0 },  
        {0 , 1 , 2 , 0 , 0 }  
    };  
   // size of matrix  
    int size = 0;  
    for(int i=0; i<4; i++)  
    {  
        for(int j=0; j<5; j++)  
        {  
            if(sparse_matrix[i][j]!=0)  
            {  
                size++;  
            }  
        }  
    }  
   // Defining final matrix  
    int matrix[3][size];   
     int k=0;  
   // Computing final matrix  
    for(int i=0; i<4; i++)  
    {  
        for(int j=0; j<5; j++)  
        {  
            if(sparse_matrix[i][j]!=0)  
            {  
                matrix[0][k] = i;  
                matrix[1][k] = j;  
                matrix[2][k] = sparse_matrix[i][j];  
                k++;  
            }  
      }  
    }  
   // Displaying the final matrix  
    for(int i=0 ;i<3; i++)  
    {  
        for(int j=0; j<size; j++)  
        {  
            printf("%d ", matrix[i][j]);  
            printf("\t");  
        }  
        printf("\n");  
    }  
    return 0;  
}  
