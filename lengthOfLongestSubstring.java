import java.util.*;
class LongestSubstring {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); //System.in is a standard input stream
        System.out.print("Enter a string: ");
        String str = sc.nextLine();
        System.out.println(lengthOfLongestSubstring(str));
    }
    public static int lengthOfLongestSubstring(String s) {
        List<String> m = new ArrayList();
        int answer = 0;
        for (char i : s.toCharArray()) {
            if (m.contains(String.valueOf(i))) {
                final int ix = m.indexOf(String.valueOf(i));
                final List<String> tmp = m.subList(ix+1, m.size());
                if (answer < m.size()) {
                    answer = m.size();
                }
                tmp.add(String.valueOf(i));
                m = tmp;
            } else {
                m.add(String.valueOf(i));
            }
        }
        if (m.size() > answer) {
            answer = m.size();
        }
        return answer;
    }
}