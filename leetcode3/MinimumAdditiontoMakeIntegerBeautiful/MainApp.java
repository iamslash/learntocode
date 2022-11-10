// Copyright (C) 2022 by iamslash

import java.util.*;


// tgt: 6
//   n: 5
// bae: 100
// org: 467
// ans:  33

// 0ms 100.00% 38.9MB 97.46%
// math
// O(N) O(1)
class Solution {
    private long sum(long num) {
        long ans = 0;
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
    public long makeIntegerBeautiful(long num, int tgt) {
        long org = num, base = 1;
        while (sum(num) > tgt) {
            num = num / 10 + 1;
            base *= 10;
        }
        return num * base - org;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
