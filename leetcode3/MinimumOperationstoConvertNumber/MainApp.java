// Copyright (C) 2022 by iamslash

import java.util.*;

// 320ms 50.23% 113.8MB 66.82%
// bfs
// O(3^N) O(3^N)
class Solution {
    public int minimumOperations(int[] nums, int start, int goal) {
        int step = 0;
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(start);
        Set<Integer> visit = new HashSet<>();
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int x = q.poll();
                if (x == goal) {
                    return step;
                }
                if (x < 0 || x > 1000 || visit.contains(x)) {
                    continue;
                }
                visit.add(x);
                for (int num : nums) {
                    q.offer(x + num);
                    q.offer(x - num);
                    q.offer(x ^ num);
                }
            }
            step++;
        }
        return -1;
    }
}

// 18ms 100.00% 41.2MB 96.77%
// bfs
// O(3^N) O(N)
class Solution {
    private void offerAbsent(boolean[] visit, Queue<Integer> q, int x) {
        if (x >= 0 && x <= 1000 && !visit[x]) {
            q.offer(x);
            visit[x] = true;
        }
    }
    public int minimumOperations(int[] nums, int start, int goal) {
        int step = 1;
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(start);
        boolean[] visit = new boolean[1001];
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int x = q.poll();
                for (int num : nums) {
                    int plusNum = x + num;
                    int minusNum = x - num;
                    int xorNum = x ^ num;
                    if (plusNum == goal ||
                        minusNum == goal ||
                        xorNum == goal) {
                        return step;
                    }
                    offerAbsent(visit, q, plusNum);
                    offerAbsent(visit, q, minusNum);
                    offerAbsent(visit, q, xorNum);
                }
            }
            step++;
        }
        return -1;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
