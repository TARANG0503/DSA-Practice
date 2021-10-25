#include <iostream>
#define LEN 8 // number of vertex
#define maxVal 10 ;// maximum weight of edge + 1
using namespace std;

void PRINT(int[][LEN]);
int find_min(int[][LEN], int*, int*);
int niarr(int*, int, int);

int main()
{
    int graph[LEN][LEN] = { {0, 1, 2, 0, 0, 7, 0, 0},
                            {1, 0, 4, 5, 0, 0, 0, 0},
                            {2, 4, 0, 0, 5, 0, 0, 0},
                            {0, 5, 0, 0, 6, 0, 0, 8},
                            {0, 0, 5, 6, 0, 3, 2, 0},
                            {7, 0, 0, 0, 3, 0, 9, 0},
                            {0, 0, 0, 0, 2, 9, 0, 2},
                            {0, 0, 0, 8, 0, 0, 2, 0},
                      };
    PRINT(graph);
    int arr[LEN], arrptr=0;
    int min = maxVal;
    for(int i=0; i<LEN; i++)
    {
        for(int j=i+1; j<LEN; j++)
        {
            if(graph[i][j]!=0 && graph[i][j] < min)
            {
                min = graph[i][j];
                arr[0] = i;
                arr[1] = j;
            }
        }
    }
    arrptr += 2;
    // Step 1 find minimum cost edge
    cout<<"\n\nVertex: ";
    for(int i=0; i<arrptr; i++)
    cout<<" "<<arr[i];
    // Step 2 find minimum cost edge adjacent to new minimum cost edge, repeat until all vertex get connected
    for(int i=2; i<LEN; i++)
    {
        min += find_min(graph, arr, &arrptr);
        cout<<"\nVertex: ";
        for(int i=0; i<arrptr+1; i++)
            cout<<" "<<arr[i];
        arrptr++;
    }
    cout<<"\nWeight of minimum spanning tree: "<<min<<"\n";
    return 0;
}

int find_min(int graph[][LEN], int *arr, int *arrptr)
{
    int min = maxVal;
    for(int i=0; i<*arrptr; i++)
    {
        for(int j=0; j<LEN; j++)
        {
            int t = graph[arr[i]][j];
            if(t!=0 && niarr(arr, *arrptr, j) && t < min)
            {
                min = t;
                arr[*arrptr] = j;
            }
        }
    }
    return min;
}

int niarr(int *arr, int l, int t)
{
    for(int i=0; i<l; i++)
    {
        if(arr[i]==t)
            return 0;
    }
    return 1;
}

void PRINT(int graph[][LEN])
{
    printf("Graph: \n   |");
    for(int i=0; i<LEN; i++)
    printf("  %d", i);
    printf("\n --|");
    for(int i=0; i<LEN; i++)
    printf(" --");
    for(int i=0; i<LEN; i++)
    {
        printf("\n %d | ", i);
        for(int j=0; j<LEN; j++)
        printf("%2i ",graph[i][j]);
    }
}


