// Copyright (C) 2021 by iamslash

import java.util.*;

//    k: 2
//             i
// nums: 2 1 3 3
//  deq: 3 3 

// // 12ms 31.44% 41.6MB 32.30%
// // heap, sort
// // O(NlgN) O(K)
// class Solution {
//     public int[] maxSubsequence(int[] nums, int k) {
//         Queue<Integer> pq = new PriorityQueue<>((i, j) -> nums[i] - nums[j]);
//         for (int i = 0; i < nums.length; ++i) {
//             pq.offer(i);
//             // System.out.println(pq);
//             if (pq.size() > k) {
//                 pq.poll();
//             }
//         }
//         return pq.stream()
//             .sorted()
//             .mapToInt(i -> nums[i])
//             .toArray();
//     }
// }

// 7ms 72.27% 39.4MB 55.82%
// heap
// O(NlgK) O(K)
class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        Queue<Integer> pq = new PriorityQueue<>((i, j) -> nums[i] - nums[j]);
        for (int i = 0; i < nums.length; ++i) {
            pq.offer(i);
            // System.out.println(pq);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        int n = pq.size();
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = pq.poll();
        }
        Arrays.sort(ans);
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
