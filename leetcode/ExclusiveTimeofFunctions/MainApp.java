// Copyright (C) 2021 by iamslash

import java.util.*;

// logs: 0:s:0 1:s:2 2:s:3 2:e:4 1:e:5 0:e:6
// stck: 
//  ans: 3 2 2
//       

// 10ms 72.01% 39.9MB 52.59%
// stack
// O(N) O(N)
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<int[]> stck = new Stack<>();
        int[] ans = new int[n];
        for (String log : logs) {
            String[] items = log.split(":");
            int functionId = Integer.parseInt(items[0]);
            String event = items[1];
            int ts = Integer.parseInt(items[2]);
            if ("start".equals(event)) {
                stck.push(new int[]{functionId, ts});
            } else {
                int[] item = stck.pop();
                int duration = ts - item[1] + 1;
                ans[item[0]] += duration;
                if (!stck.isEmpty()) {
                    ans[stck.peek()[0]] -= duration;
                }
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
