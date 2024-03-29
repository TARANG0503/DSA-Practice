// Problem - https://atcoder.jp/contests/dp/tasks/dp_f

// Solution

import java.io.*;
import java.util.*;

class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static final int mod = 1_000_000_007;
    static int max = (int)(1e8);

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] readLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    /*--------------------------------------------------------------------------*/
    static int n, m;
    static int[][] memo;
    static StringBuilder sb;
    public static void main(String[] args) {
        FastReader s = new FastReader();
        char[] s1 = s.nextLine().toCharArray();
        char[] s2 = s.nextLine().toCharArray();
        n = s1.length; m = s2.length;
        memo = new int[n+1][m+1];
        sb = new StringBuilder();
        for(int[] x: memo)
            Arrays.fill(x, -1);
        int lcs = find(0, 0, s1, s2);
        print(0, 0, s1, s2);
        out.println(sb);


        out.close();
    }

    public static void print(int i, int j, char[] s1, char[] s2)
    {
        if(i == n || j == m)
            return ;

        int ans = find(i, j, s1, s2);
        if(ans == find(i+1, j, s1, s2))
            print(i+1, j, s1, s2);
        else if(ans == find(i, j+1, s1, s2))
            print(i, j+1, s1, s2);
        else{
            sb.append(s1[i]);
            print(i+1, j+1, s1, s2);
        }
    }

    public static int find(int i, int j, char[] s1, char[] s2)
    {
        if(i == n || j == m)
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];

        if(s1[i] == s2[j])
            return memo[i][j] = 1 + find(i+1, j+1, s1, s2);
        else
            return memo[i][j] = Math.max(find(i+1, j, s1, s2), find(i, j+1, s1, s2));
    }
}
