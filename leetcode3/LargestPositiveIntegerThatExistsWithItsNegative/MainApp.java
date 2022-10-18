// Copyright (C) 2022 by iamslash

import java.util.*;

// 7ms 88.18% 49.4MB 76.03%
// two pointers
// O(N) O(1)
class Solution {
    public int findMaxK(int[] nums) {
        boolean[] exist = new boolean[2001];
        for (int num : nums) {
            exist[num + 1000] = true;
        }
        int a = -1000, b = 1000;
        while (a < b) {
            int i = a + 1000;
            int j = b + 1000;
            if (exist[i] && exist[j]) {
                return j - 1000;
            }
            a++;
            b--;
        }
        return -1;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
