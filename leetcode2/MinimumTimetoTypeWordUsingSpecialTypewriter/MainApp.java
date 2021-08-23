// Copyright (C) 2021 by iamslash

// a b c d e ... a b c d e

// math
// O(N) O(1)
class Solution {
    private int minDist(char from, char to) {
        if (from > to) {
            char tmp = from;
            from = to;
            to = tmp;
        }
        return Math.min(Math.abs(to-from ), Math.abs(from+26-to));
    }
    public int minTimeToType(String word) {
        int ans = 0;
        char from = 'a';
        for (char to : word.toCharArray()) {
            ans += minDist(from, to) + 1; 
            // System.out.printf("from:%c, to:%c, ans: %d\n", from, to, ans);
            from = to;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
