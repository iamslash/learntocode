// Copyright (C) 2022 by iamslash

// recursive dynamic programming
class Solution {
    private int dfs(int[] C, String s, int minJump, int maxJump, int pos) {
        int n = s.length();
        // base
        if (pos == n-1) {
            return 1;
        } else if (pos >= n) {
            return 2;
        }
        // memo
        if (C[pos] > 0) {
            return C[pos];
        }
        // recursion
        int r = 1, beg = pos + minJump, end = pos + maxJump;
        for (int i = beg; i < end; ++i) {
            if (s.charAt(i) == '0' && dfs(C, s, minJump, maxJump, i) == 2) {
                r = 2;
                break;
            }
        }
        return C[pos] = r;
    }
    public boolean canReach(String s, int minJump, int maxJump) {
        int[] C = new int[s.length()];
        C[s.length()-1] = 2;
        return dfs(C, s, minJump, maxJump, 0) == 2;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
