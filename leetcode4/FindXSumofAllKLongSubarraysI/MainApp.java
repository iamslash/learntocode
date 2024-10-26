// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 6
//    x: 2
//       i
// nums: 1 1 2 2 3 4 2 3
//       . . . . . .
//         . . . . . .
//           . . . . . .
//  ans: 

// 34ms 7.69% 45.4MB 49.27%
// sliding window, sort
// O(NlgN) O(N)
class Solution {

    private int sum(int[][] freqs, int x) {
        Arrays.sort(freqs, (a, b) -> a[1] == b[1] ? b[0] - a[0] : b[1] - a[1]);
        int sum = 0;
        for (int i = 0; i < x; ++i) {
            sum += freqs[i][0] * freqs[i][1];
        }
        Arrays.sort(freqs, (a, b) -> a[0] - b[0]);
        return sum;
    }
    
    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[][] freqs = new int[51][2];
        int[] ans = new int [n - k + 1];

        for (int i = 0; i < freqs.length; ++i) {
            freqs[i][0] = i;
        }

        for (int i = 0; i < k; ++i) {
            freqs[nums[i]][1]++;
        }
        ans[0] = sum(freqs, x);

        for (int i = 1, j = k; j < n; ++i, ++j) {
            // Shrink
            freqs[nums[i - 1]][1]--;

            // Expand
            freqs[nums[j]][1]++;

            // Update
            ans[i] = sum(freqs, x);
        }

        return ans;
    }
}


// 2ms 100.00% 44.8MB 92.10%
// sliding window
// O(N) O(N)
class Solution {

    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];

        for (int i = 0; i < n - k + 1; ++i) {
            ans[i] = sum(nums, k, x, i);
        }

        return ans;
    }

    private int sum(int[] nums, int k, int x, int pos) {
        int[] freqs = new int[51];
        int maxFreq = 0, xSum = 0, allSum = 0;

        for (int i = pos; i < pos + k; ++i) {
            freqs[nums[i]]++;
            allSum += nums[i];
            maxFreq = Math.max(maxFreq, freqs[nums[i]]); 
        }

        int cnt = 0;
        for (int freq = maxFreq; freq > 0; --freq) {
            for (int num = 50; num > 0; --num) {
                if (freqs[num] == freq) {
                    xSum += num * freqs[num];
                    cnt++;
                }

                if (cnt == x) {
                    return xSum;
                }
            }
        }
        if (cnt < x) {
            return allSum;
        }

        return xSum;
    }

}
