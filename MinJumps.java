import java.util.ArrayList;

public class MinJumps {

  public static class Solution {

    public int jump(ArrayList<Integer> a) {
      if (null == a || a.size() < 1) {
        return -1;
      }
      if (a.size() == 1) {
        return 0;
      }
      int cur = -1;
      for (int i = 0; i < a.size() - 1; i++) {
        if (i + a.get(i) + 1 >= a.size()) {
          cur = i;
          break;
        }
      }

      if (cur == -1) {
        return cur;
      }
      if (cur == 0) {
        return 1;
      }
      int maxDist = a.get(0);
      int prevMax = a.get(0);
      int jumps = 1;
      for (int i = 0; i < cur; i++) {
        if (i + a.get(i) > maxDist) {
          maxDist = i + a.get(i);
        }
        if (prevMax == i) {
          prevMax = maxDist;
          jumps++;
          if (maxDist >= cur) {
            return jumps + 1;
          }
        }

        if (maxDist == 0) {
          return -1;
        }

      }
      if (maxDist < cur) {
        return -1;
      }

      return jumps + 1;
    }
  }
}
