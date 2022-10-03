import java.util.*;
public class SieveOfEratosthenes {


    static boolean[] sieveOfEr(int n)
    {
        boolean isPrime[]=new boolean[n+1];
        Arrays.fill(isPrime,true);
        for(int i=2;i*i<=n;i++)
        { for(int j=2;j<=n;j=j+i)
            {
isPrime[j]=false;
            }
           
        }
        return isPrime;
    }

    public static void main (String args[])
{
    Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();
        boolean iPrime[]=sieveOfEr(n);
        for(int i=2;i<n;i++)
        {
           
            if(iPrime[i]==true)
            {
                System.out.print(i+" ");
            }
        }
        
        
    

        sc.close();
    


}
}
