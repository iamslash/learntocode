import java.util.*;

// 1ms 80.52% 36.3MB 14.61%
// sort, two pointers
// O(NlgN) O(1)
class Solution {
  public int videoStitching(int[][] C, int T) {
    Arrays.sort(C, (a, b) -> {
      if (a[0] == b[0])
        return Integer.compare(a[1], b[1]);
      return Integer.compare(a[0], b[0]);
    });
    int n = C.length, ans = 0;    
    for (int i = 0, s = 0, e = 0; s < T; ans++) {
      while (i < n && C[i][0] <= s) {
        e = Math.max(e, C[i++][1]);
      }
      if (s == e) {
        return -1;
      }
      s = e;
    }
    return ans;
  }
}
