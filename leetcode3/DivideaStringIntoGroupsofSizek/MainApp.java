// Copyright (C) 2022 by iamslash

import java.util.*;

// k: 3
// s: abcdefghi
//

// 19ms 20.00% 40.6MB 20.00%
// brute force
// O(N) O(N)
class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = (s.length() / k) + (s.length() % k > 0 ? 1 : 0) ;
        String[] ans = new String[n];
        for (int i = 0; i < n; ++i) {
            if (i < n-1) {
                ans[i] = s.substring(i*k, i*k + k);
            } else {
                ans[i] = s.substring(i*k);
            }
        }
        if (ans[n-1].length() < k) {
            ans[n-1] = String.format("%" + -k + "s", ans[n-1])
                .replace(' ', fill);  
        }
        return ans;
    }
}

// 10ms 20.00% 40.3MB 20.00%
// brute force
// O(N) O(N)
class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = (s.length() / k) + (s.length() % k > 0 ? 1 : 0) ;
        String[] ans = new String[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = s.substring(i*k, Math.min(i*k + k, s.length()));
        }
        while (ans[n-1].length() < k) {
            ans[n-1] += fill;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
