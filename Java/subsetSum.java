import java.util.*;
public class subsetSum {
	
	public static void display(int[] arr,int[] check)
	{
		for(int i=0;i<arr.length;i++) {
			if(check[i]!=-1) {
				System.out.print(arr[i]+" ");
			}
		}
		System.out.println("BREAK");
	}
	
	public static int issafe(int act,int balance,int k) {
		if(act<k&&balance!=0) {
			return 1;
		}else {
			return 0;
		}
	}
	
	public static void solve(int act,int bal,int[] arr,int[] check,int k,int i) {
		if(act==k) {
			display(arr,check);
		}
		else {
			if(issafe(act,bal,k)==1) {
				check[i]=1;
				solve(act+arr[i],bal-arr[i],arr,check,k,i+1);
				check[i]=-1;
				solve(act,bal-arr[i],arr,check,k,i+1);
			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n;
		System.out.println("Hello");
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		int act[]=new int[n];
		int check[]=new int[n];
		int k=sc.nextInt();
		int balance=0;
		for(int i=0;i<act.length;i++) {
			act[i]=sc.nextInt();
			check[i]=-1;
			balance=balance+act[i];
		}
		solve(0,balance,act,check,k,0);
		sc.close();
	}

}
