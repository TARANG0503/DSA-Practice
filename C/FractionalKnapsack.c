# include<stdio.h>
int id[20];
void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n)
      x[i] = u / weight[i];

   //For Fractional Knapsack  
       tp = tp + (x[i] * profit[i]);

   printf("\nThe result vector(RV) is:\nID\tRV\n");
   for (i = 0; i < n; i++)
      printf("%d\t%f\n",id[i], x[i]);

   printf("\nMaximum profit is : %f", tp);

}

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   printf("\nEnter the number of objects : ");
   scanf("%d", &num);

   printf("\nEnter the weights and values(profits) of each object :\n");
   for (i = 0; i < num; i++) {
       id[i]=i+1;
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\nEnter the capacity of knapsack : ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }
   
   
   printf("\nSorted knapsack based on ratio :\nID\tWeight\t\tProfit\t\tRatio\n");
   for (i = 0; i < num; i++) {
      printf("%d\t%f\t%f\t%f\n", id[i], weight[i], profit[i],ratio[i]);
   }

   knapsack(num, weight, profit, capacity);
   return(0);
}
