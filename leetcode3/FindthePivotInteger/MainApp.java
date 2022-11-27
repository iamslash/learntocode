// Copyright (C) 2022 by iamslash

import java.util.*;


// Idea: math
//
// x (x + 1) / 2 = (n - x + 1) (n + x) / 2
// x = sqrt((n*n + n) / 2)

// 0ms 100.00% 39.6MB 55.56%
// math
// O(1) O(1)
class Solution {
    public int pivotInteger(int n) {
        int pow = (n * n + n) / 2;
        int ans = (int)Math.sqrt(pow);
        if (ans * ans == pow) {
            return ans;
        }
        return -1;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
