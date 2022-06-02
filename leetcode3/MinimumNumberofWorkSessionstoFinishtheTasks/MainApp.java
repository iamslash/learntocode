// Copyright (C) 2022 by iamslash

import java.util.*;

// sessionTime: 8    
//       tasks: 3 1 3 1 1
//              1 1 1 3 3  
//                1   1
//              3   3   1
//       tasks: 3 1 3 1
//              1 1 3 3
//                1   1
//              3   3

// sessionTime: 5
//       tasks: 3 1 3 1 1
//              1 1 1 3 3
//                1   1
//              3   3   1
//                      i
//      prvSum: 5
//         cnt: 2

// 99ms 44.05% 41.5MB 79.00%
// back tracking
class Solution {
    private boolean canWork(int[] tasks, int curr, int[] remain) {
        // base
        if (curr == tasks.length) {
            return true;
        }
        // recursion
        for (int i = 0; i < remain.length; ++i) {
            // pruning
            if (i > curr) {
                continue;
            }
            if (remain[i] >= tasks[curr]) {
                remain[i] -= tasks[curr];
                if (canWork(tasks, curr + 1, remain)) {
                    return true;
                }
                remain[i] += tasks[curr];
            }
        }
        return false;
    }
    public int minSessions(int[] tasks, int sessionTime) {
        for (int len = 1; len < tasks.length; len++) {
            int[] remain = new int[len];
            for (int i = 0; i < len; ++i) {
                remain[i] = sessionTime;
            }
            if (canWork(tasks, 0, remain)) {
                return len;
            }
        }
        return tasks.length;
    }
}

// 1ms 100.00% 41.8MB 67.10%
// back tracking
// difficult
class Solution {
    int ans;
    int maxTime;
    int[] sessions;
    int[] tasks;
    public int minSessions(int[] tasks, int sessionTime) {
        this.ans = tasks.length;
        this.maxTime = sessionTime;
        this.sessions = new int[tasks.length];
        this.tasks = tasks;
        Arrays.sort(this.tasks);
        dfs(tasks.length - 1, 0);
        return ans;
    }    
    private void dfs(int beg, int sessionCount) {
        // base
        if (beg < 0) {
            ans = Math.min(ans, sessionCount);
            return;
        }
        if (sessionCount >= ans) {
            return;
        }
        // recursion
        for (int i = 0; i < sessionCount; i++) {
            if (i > 0 && sessions[i] == sessions[i-1]) {
                continue;
            }
            if (sessions[i] + tasks[beg] <= maxTime) {
                sessions[i] += tasks[beg];
                dfs(beg - 1, sessionCount);
                sessions[i] -= tasks[beg];
            }   
        }
        sessions[sessionCount] += tasks[beg];
        dfs (beg - 1, sessionCount + 1);
        sessions[sessionCount] -= tasks[beg];
    }
}
