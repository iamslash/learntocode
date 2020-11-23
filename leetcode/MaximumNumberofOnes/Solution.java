// Copyright (C) 2019 by iamslash

import java.util.*;

// 7ms 55.46% 34.3MB 100.00%
// math
// O(NlgN) O(N)
class Solution {
  public int maximumNumberOfOnes(
      int w, int h, int sidelen, int maxone) {
    // set rec
    ArrayList<Integer> rec = new ArrayList<Integer>();
    for (int i = 0; i < sidelen; ++i) {
      for (int j = 0; j < sidelen; ++j) {
        int r = (h - i - 1) / sidelen + 1;
        int c = (w - j - 1) / sidelen + 1;
        rec.add(r * c);
      }
    }

    // sort desc
    Collections.sort(rec, Collections.reverseOrder());

    // loop
    int ans = 0;
    for (int i = 0; i < maxone; ++i) {
      ans += rec.get(i);
    }
    return ans;
  }

  public static void main(String[] args) {
    int[] A = new int[]{5, 4, 3, 2, 1};
    Arrays.sort(A);
  }
}
