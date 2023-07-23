// Copyright (C) 2023 by iamslash

import java.util.*;

// 6ms 100.00% 43.1MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> numList = new ArrayList<>();
        for (int num : nums) {
            Deque<Integer> deq = new ArrayDeque<>();
            while (num > 0) {
                deq.offerLast(num % 10);
                num /= 10;
            }
            while (!deq.isEmpty()) {
                numList.add(deq.pollLast());
            }
        }
        int[] ans = new int[numList.size()];
        int i = 0;
        for (int num : numList) {
            ans[i++] = num;
        }
        return ans;
    }
}
