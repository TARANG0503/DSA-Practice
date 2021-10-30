import java.io.*;
import java.util.*;

class DFD {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");

            int n = Integer.parseInt(S[0]);
            int k = Integer.parseInt(S[1]);

            Solution ob = new Solution();
            System.out.println(ob.safePos(n, k));

        }
    }
}

class Solution {
    static int safePos(int n, int k) {

        if (n == 1)
            return 1;
        else
            /*
             * The position returned by safePos(n - 1, k) is adjusted because the recursive
             * call safePos(n - 1, k) considers the original position k%n + 1 as position 1
             */
            return (safePos(n - 1, k) + k - 1) % n + 1;
    }

    // Driver Program to test above function
    public static void main(String[] args) {
        int n = 14;
        int k = 2;
        System.out.println("The chosen place is " + safePos(n, k));
    }
}