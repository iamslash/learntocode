// Copyright (C) 2022 by iamslash

import java.util.*;

// nums1: 1 2 3 4
// nums2: 2 10 20 19
//    pq: 1 8 15
//   prv: 17
//   cnt:  1
//     k:  0
//     x:  2

// heap
// O(NlgN) O(N)
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        pq.add(0);
        int n = nums1.length;
        for (int i = 0; i < n; ++i) {
            int diff = Math.abs(nums1[i] - nums2[i]);
            if (diff > 0) {
                pq.add(diff);
            }
        }
        int k = k1 + k2;
        int prv = 0, cnt = 0;
        while (k > 0 && !pq.isEmpty()) {
            int top = pq.poll();
            long x = (prv - top) * cnt;
            if (x <= k) {
                prv = top;
                cnt++;
                k -= x;
            } else {
                int a = k / cnt;
                int b = k % cnt;
                int c = prv - a;
                for (int i = 0; i < cnt - b; ++i) {
                    pq.add(c);
                }
                for (int i = 0; i < b; ++i) {
                    pq.add(c - 1);
                }
                pq.add(top);
                k = 0;
            }
        }
        long ans = 0;
        for (long diff : pq) {
            ans += (long) diff * diff;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
