//package stackQuestion;
import java.io.*;
//import java.util.Arrays;
import java.util.Stack;

public class LargestAreaHistogram {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		String ip[] = str.split(" ");
		int arr[] = new int[ip.length];
		for(int i=0;i<ip.length;i++) {
			arr[i] = Integer.parseInt(ip[i]);
		}
		int area = 0;
		//area = largestAreaHistogramBruteForce(arr);
		area = largestAreaHistogramUsingStack(arr);
		System.out.println(area);
		br.close();
	}
	
	
	public static int largestAreaHistogramUsingStack(int arr[]) {
		int nser[] = new int[arr.length];
		int nsel[] = new int[arr.length];
		Stack<Integer> st = new Stack<Integer>();
		
		// operations for next smaller element to the right
		st.push(0);
		for(int i=1;i<arr.length;i++) {
			while(!st.empty() && arr[i]<arr[st.peek()]) {
				int val = st.pop();
				nser[val] = i;
			}
			st.push(i);
		}
		
		while(!st.empty()) {
			int index = st.pop();
			nser[index] = arr.length;
		}
		
		// operations for next smaller element to the left
		st.push(arr.length-1);
		for(int i=arr.length-2;i>=0;i--) {
			while(!st.empty() && arr[i]<arr[st.peek()]) {
				int val = st.pop();
				nsel[val] = i;
			}
			st.push(i);
		}
		
		while(!st.empty()) {
			int index = st.pop();
			nsel[index] = -1;
		}
		int max = Integer.MIN_VALUE;
		for(int i=0;i<arr.length;i++) {
			int value = (nser[i] - nsel[i] - 1) * arr[i];
			if(value > max) {
				max = value;
			}
		}
		
		return max;
	}
	
	public static int largestAreaHistogramBruteForce(int arr[]) {
		int max = 0;
		for(int i=0;i<arr.length;i++) {
			int val = arr[i];
			for(int j=1;j<=val;j++) {
				int area = 0;
				int left = i-1;
				int right = i+1;
				int leftArea = 0;
				int rightArea = 0;
				while(left>=0 && j<=arr[left]) {
					leftArea += j;
					left--;
				}
				while(right<arr.length && j<=arr[right]) {
					rightArea += j;
					right++;
				}
				
				area = leftArea + rightArea + j;
				if(area > max) {
					max = area;
				}
			}
		}
		return max;
	}

}
