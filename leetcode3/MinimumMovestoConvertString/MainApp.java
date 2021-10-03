// Copyright (C) 2021 by iamslash

//    i
// s: X X O X

// 0ms 100.00% 37MB 80.00%
// sliding window
// O(N) O(1)
class Solution {
    public int minimumMoves(String s) {
        int n = s.length(), cnt = 0, i = 0;
        while (i < n) {
            while (i < n && s.charAt(i) == 'O') {
                ++i;
            }
            if (i < n) {
                cnt++;
                i += 3;
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
