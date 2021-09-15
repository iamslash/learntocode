// Copyright (C) 2021 by iamslash

//      k: 2
// digit1: 0
// digit2: 2
//
//             0
//             2
//           0 0
//           0 2
//           2 0
//           2 2

//      k: 3
// digit1: 4
// digit2: 2
//
//         2
//         4
//       2 2
//       2 4
//       4 2
//       4 4

// 1ms 100.00% 35.5MB 95.70%
// DFS
// O(2^L) O(L)
// L: length of num
class Solution {
    private int dfs(int k, int digit1, int digit2, long num) {
        // base
        if (num > Integer.MAX_VALUE) {
            return -1;
        }
        if (num > k && num % k == 0) {
            return (int)num;
        }
        // recursion
        int x1 = (num + digit1 == 0) ? -1 : dfs(k, digit1, digit2, num * 10 + digit1);
        int x2 = (num + digit2 == 0) ? -1 : dfs(k, digit1, digit2, num * 10 + digit2);
        if (x1 > 1 && x2 > 1) {
            return Math.min(x1, x2);
        }
        return Math.max(x1, x2);
    }
    public int findInteger(int k, int digit1, int digit2) {
        return dfs(k, digit1, digit2, 0);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
