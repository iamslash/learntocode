// Copyright (C) 2022 by iamslash

import java.util.*;

// x-1, x, x+2
// sum: 3*x
// num should be divided by 3

// 1ms 88.42% 42.4MB 46.04%
// math
// O(lgN) O(1)
class Solution {
    public long[] sumOfThree(long num) {
        if (num % 3 != 0) {
            return new long[0];
        }
        long x = num / 3;
        return new long[]{x-1, x, x+1};
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
