// Copyright (C) 2023 by iamslash


//           i
//   nums: 1 2 3 4 5
// suffix: 5 4 3 2 1
//    ans:-3 

// 5ms 100.00% 43.9MB 20.00%
// prefix sum
// O(N) O(N)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);
        }
        System.out.println();
    }
    public int[] distinctDifferenceArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int[] suffixDistincts = new int[n+1];
        int[] freqs = new int[51];
        suffixDistincts[n-1] = 1;
        freqs[nums[n-1]] = 1;
        for (int i = n - 1; i >= 0; --i) {
            suffixDistincts[i] += suffixDistincts[i+1];
            if (freqs[nums[i]] == 0) {
                suffixDistincts[i] += 1;
            }
            freqs[nums[i]]++;
        }
        // dump(suffixDistincts);
        Arrays.fill(freqs, 0);
        int prefixDistinct = 0;
        for (int i = 0; i < n; ++i) {
            if (freqs[nums[i]] == 0) {
                prefixDistinct += 1;
            }
            // System.out.printf("i: %d, prefixDistinct: %d, suffixDistincsts[i+1]: %d\n", i, prefixDistinct, suffixDistincts[i+1]);
            ans[i] = prefixDistinct - suffixDistincts[i+1];
            freqs[nums[i]]++;
        }
        return ans;
    }
}
