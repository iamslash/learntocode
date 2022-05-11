// Copyright (C) 2022 by iamslash

import java.util.*;

// servers: 2 3 3
//          1 0 0 
//   tasks: 1 2 3 2 1 2
//              i

// Idea: double heaps
//
// weight means not capacity but proiority.
// Use 2 heaps for free servers, used servers.
// The element is [weight, index, availTimeStamp].
// Simulate it.

// 286ms 81.21% 75.4MB 82.22%
// double heap
// O((M+N)*lgN) O(M+N)
class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length, m = tasks.length;
        // [weight, index, availTs]
        Queue<int[]> freeQueue = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        // [weight, index, availTs]
        Queue<int[]> usedQueue = new PriorityQueue<>((a, b) -> a[2] == b[2] ? a[0] == b[0] ? a[1] - b[1] : a[0] - b[0] : a[2] - b[2]);
        for (int i = 0; i < n; ++i) {
            freeQueue.add(new int[]{servers[i], i, 0});
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int dur = tasks[i];
            // restore free servers
            while (!usedQueue.isEmpty() && usedQueue.peek()[2] <= i) {
                freeQueue.add(usedQueue.poll());
            }
            if (freeQueue.isEmpty()) {
                int[] usedServer = usedQueue.poll();
                ans[i] = usedServer[1];
                usedServer[2] += dur;
                usedQueue.add(usedServer);
            } else {
                int[] freeServer = freeQueue.poll();
                ans[i] = freeServer[1];
                freeServer[2] = i + dur;
                usedQueue.add(freeServer);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
