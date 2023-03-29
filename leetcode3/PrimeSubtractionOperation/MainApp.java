// Copyright (C) 2023 by iamslash

import java.util.*;

//         i
// nums: 4 9 6 10
//       1 2 6 10

// 2 3 3
//     i
//

// 2 3 3
//     i
//

// Idea: greedy
//
// We can do operation just once for the index i.
// Find primes in [1,1000].
// Find max prime which makes nums[i-1] < nums[i].

// greedy
// O(NlgN) O(N)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);
        }
        System.out.println("");
    }
    public boolean primeSubOperation(int[] nums) {
        boolean[] primes = new boolean[1001];
        Arrays.fill(primes, true);
        primes[0] = primes[1] = false;
        for (int x = 2; x * x <= 1000; ++x) {
            if (primes[x]) {
                for (int y = x * x; y <= 1000; y += x) {
                    primes[y] = false;
                }
            }
        }
        for (int i = 0; i < nums.length; ++i) {
            int tgt = nums[i] - 1;
            if (i > 0) {
                tgt -= nums[i-1];
            }
            if (tgt < 0) {
                return false;
            }
            while (tgt > 0 && !primes[tgt]) {
                tgt--;
            }
            nums[i] -= tgt;
            // dump(nums);
            if (i > 0 && nums[i-1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }
}
