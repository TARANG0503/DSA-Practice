package DP;
import java.util.*;
public class EqualSumPartition {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, s = 0; 
        n = in.nextInt(); // number of items
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
        {
		    int temp = in.nextInt();
            arr[i] = temp;
            s += temp;
        }    
        if(s%2 != 0)
            System.out.println("False");
        else
            System.out.println(SubsetSum.isSubsetPossible(arr, n, s/2));
        
        in.close();
    }
}
