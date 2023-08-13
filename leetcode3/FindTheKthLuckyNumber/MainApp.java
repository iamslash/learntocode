// Copyright (C) 2023 by iamslash

import java.util.*;

// Time Limit Exceeded
// Input: 50099
//
// bfs
// O(N) O(N)
class Solution {
    public String kthLuckyNumber(int k) {
        Queue<Long> q = new LinkedList<>();
        q.offer(0L);
        int step = 0;
        while (!q.isEmpty()) {
            long num = q.poll();
            if (step == k) {
                return String.valueOf(num);
            }
            q.offer(num * 10L + 4);
            q.offer(num * 10L + 7);
            step++;
        }
        return "";
    }
}

// bfs
// O(N) O(N)
class Solution {
    public String kthLuckyNumber(int k) {
        
    }
}
