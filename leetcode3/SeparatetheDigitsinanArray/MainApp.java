// Copyright (C) 2023 by iamslash

import java.util.*;

// 7ms 47.24% 44.4MB 43.26%
// deque, list
// O(N) O(N)
class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> digitList = new ArrayList<>();
        for (int num : nums) {
            Deque<Integer> deq = new ArrayDeque<>();
            while (num > 0) {
                deq.offerLast(num % 10);
                num /= 10;
            }
            while (!deq.isEmpty()) {
                digitList.add(deq.pollLast());
            }
        }
        int[] ans = new int[digitList.size()];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = digitList.get(i);
        }
        return ans;
    }
}
