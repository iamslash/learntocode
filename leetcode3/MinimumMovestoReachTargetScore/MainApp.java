// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 38.9MB 13.81%
// math
// O(lgN) O(1)
class Solution {
    public int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        while (target > 1) {
            if (maxDoubles == 0) {
                cnt += target - 1;
                break;  
            } else if (target % 2 == 0) {
                target /= 2;
                maxDoubles--;
            } else {
                target -= 1;
            }
            cnt++;
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
