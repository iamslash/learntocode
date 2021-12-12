// Copyright (C) 2021 by iamslash

// 0ms 100.00% 36.7MB 100.00%
// O(N) O(1)
class Solution {
    private int getColorCode(char c) {
        if (c == 'R') {
            return 1;
        }
        if (c == 'G') {
            return 2;
        }
        return 4;
    }
    public int countPoints(String rings) {
        char[] colorBms = new char[10];
        int n = rings.length();
        for (int i = 0; i < 2*n; i += 2) {
            char col = rings.charAt(i);
            int rod = rings.charAt(i+1) - '0';
            int colorCode = getColorCode(col);
            colorBms[rod] |= colorCode;
        }
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            if (colorBms[i] == 7) {
                ans++;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
