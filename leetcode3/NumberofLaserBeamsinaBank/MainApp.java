// Copyright (C) 2021 by iamslash

import java.util.*;

// 27ms 37.86% 53.5MB 18.81%
// math
// O(N) O(1)
class Solution {
    private int beamCnt(String s) {
        int cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                cnt++;
            }
        }
        return cnt;
    }
    public int numberOfBeams(String[] bank) {
        int n = bank.length, prvCnt = 0;
        int ans = 0;
        for (String s : bank) {
            int curCnt = beamCnt(s);
            ans += prvCnt * curCnt;
            if (curCnt > 0) {
                prvCnt = curCnt;
            }
        }
        return ans;
    }
}

// 8ms 99.96% 39.9MB 84.57%
// math
// O(N) O(1)
class Solution {
    public int numberOfBeams(String[] bank) {
        int prv = 0, ans = 0;
        for (String s : bank) {
            int cur = 0;
            for (char c : s.toCharArray()) {
                cur += (c - '0');
            }
            ans += prv * cur;
            if (cur > 0) {
                prv = cur;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
