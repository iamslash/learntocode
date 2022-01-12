// Copyright (C) 2022 by iamslash

import java.util.*;

// 63ms 36.52% 51.8MB 10.92%
// matrix
// O(N^2) O(N)
class Solution {
    private int getCnt(int n, int y, int x, String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == 'R') {
                x++;
            } else if (c == 'D') {
                y++;
            } else if (c == 'L') {
                x--;
            } else if (c == 'U') {
                y--;
            }
            if (y < 0 || y >= n || x < 0 || x >= n) {
                break;
            }
            cnt++;
        }
        return cnt;
    }
    public int[] executeInstructions(int n, int[] startPos, String s) {
        int len = s.length();
        int[] ans = new int[len];
        for (int i = 0; i < len; ++i) {
            ans[i] = getCnt(n, startPos[0], startPos[1], s.substring(i));
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
