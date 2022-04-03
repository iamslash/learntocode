// Copyright (C) 2022 by iamslash

import java.util.*;

// 150
// 275
// 125

// 1ms 90.00% 43.1MB 20.00%
// brute force
// O(N) O(1)
class Solution {
    private int toMin(String time) {
        int hr = Integer.parseInt(time.substring(0, 2));
        int mn = Integer.parseInt(time.substring(3));
        return hr * 60 + mn;
    }
    public int convertTime(String current, String correct) {
        int curMin = toMin(current), corMin = toMin(correct), cnt = 0;
        int diff = Math.abs(curMin - corMin);
        while (diff > 0) {
            if (diff >= 60) {
                diff -= 60;
            } else if (diff >= 15) {
                diff -= 15;
            } else if (diff >= 5) {
                diff -= 5;
            } else {
                diff -= 1;
            }
            cnt++;
        }
        return cnt;
    }
}

// 2ms 60.00% 42.2MB 80.00%
// brute force
// O(1) O(1)
class Solution {
    private int toMin(String time) {
        int hr = Integer.parseInt(time.substring(0, 2));
        int mn = Integer.parseInt(time.substring(3));
        return hr * 60 + mn;
    }
    public int convertTime(String current, String correct) {
        int curMin = toMin(current), corMin = toMin(correct), cnt = 0;
        int diff = Math.abs(curMin - corMin);        
        cnt += diff/ 60;
        diff %= 60;
        cnt += diff/ 15;
        diff %= 15;
        cnt += diff/ 5;
        diff %= 5;
        cnt += diff;
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
