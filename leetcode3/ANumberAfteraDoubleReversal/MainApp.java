// Copyright (C) 2021 by iamslash

import java.util.*;

// num: 526
//      625
//      526
//
// num: 1800

// 0ms 100.00% 37.5MB 49.35%
// math
// O(N) O(1)
class Solution {
    public boolean isSameAfterReversals(int num) {
        int quo = num / 10;
        int rem = num % 10;
        if (quo > 0 && rem == 0) {
            return false;
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
