// Copyright (C) 2022 by iamslash

import java.util.*;

// beans: 4 1 6 5
//        1 4 5 6

// beans: 2 10 3  2
//        2  2 3 10
//        
//        

// 49ms 48.49% 111.3MB 51.51%
// sort
// O(NlgN) O(1)
class Solution {
    public long minimumRemoval(int[] beans) {
        long n = beans.length, ans = Long.MAX_VALUE, sum = 0;
        for (int bean : beans) {
            sum += bean;
        }
        Arrays.sort(beans);
        for (int i = 0; i < n; ++i) {
            ans = Math.min(ans, sum - (n - i) * beans[i]);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
