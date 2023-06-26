// Copyright (C) 2023 by iamslash

import java.util.*;

// 13ms 65.59% 61MB 78.49%
// deque
// O(N) O(N)
class Solution {
    public int[] timeTaken(int[] arrivals, int[] states) {
        int n = arrivals.length;
        int[] ans = new int[n];
        Deque<Integer> inDeq = new ArrayDeque<>();
        Deque<Integer> outDeq = new ArrayDeque<>();
        boolean doorEntered = false;
        int i = 0, time = 0;
        while (i < n || !inDeq.isEmpty() || !outDeq.isEmpty()) {
            // Fill answer
            if (i == n || time < arrivals[i]) {
                // Consume deque or increase time
                if (!inDeq.isEmpty() || !outDeq.isEmpty()) {
                    if (!inDeq.isEmpty() && (outDeq.isEmpty() || doorEntered)) {
                        ans[inDeq.pollFirst()] = time++;
                        doorEntered = true;
                    } else {
                        ans[outDeq.pollFirst()] = time++;
                        doorEntered = false;
                    }
                } else {
                    if (time + 1 <= arrivals[i]) {
                        doorEntered = false;
                    }
                    time = arrivals[i];
                }
            }
            // Fill same time users to deque
            while (i < n && time == arrivals[i]) {
                if (states[i] == 0) {
                    inDeq.offerLast(i);
                } else {
                    outDeq.offerLast(i);
                }
                i++;
            }
        }
        return ans;
    }
}
