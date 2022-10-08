import java.util.*;

public class FractionalKnapsack {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();// length of the string we want

		int oldCountZeros = 1;
		int oldCountOnes = 1;
		for (int i = 0; i <= n-2; i++) {
			int newCountZeros = oldCountOnes;
			int newCountOnes = oldCountOnes + oldCountZeros;

			oldCountOnes = newCountOnes;
			oldCountZeros = newCountZeros;
		}
		System.out.println(oldCountOnes + oldCountZeros);
	}

}
