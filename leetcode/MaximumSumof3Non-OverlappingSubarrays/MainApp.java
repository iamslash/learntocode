// Copyright (C) 2021 by iamslash

//         k: 2
//         n: 8
//                    ___
//      nums:   1 2 1 2  6  7  5  1
//                    i    
//        ps: 0 1 3 4 6 12 19 24 25
//       ans: 0 0 0
//  leftIdxs:   0 0 0 0  3  4  4  4 
// rightIdxs:   4 4 4 4  4  5  6  0
//    maxSum: 0

// 6ms 34.73% 53.3MB 7.07%
// partial sum, hash map
// O(N) O(N)
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length, maxSum = 0;
        int[] ps = new int[n+1], ans = new int[3];
        int[] leftIdxs = new int[n], rightIdxs = new int[n];
        // fill ps
        for (int i = 0; i < n; ++i) {
            ps[i+1] = ps[i] + nums[i];
        }
        // fill leftIdxs
        for (int i = k, sum = ps[k] - ps[0]; i < n; ++i) {
            if (ps[i+1] - ps[i+1-k] > sum) {
                leftIdxs[i] = i+1-k;
                sum = ps[i+1] - ps[i+1-k];
            } else {
                leftIdxs[i] = leftIdxs[i-1];
            }
        }
        // fill rightIdxs
        rightIdxs[n-k] = n-k;
        for (int i = n-k-1, sum = ps[n] - ps[n-k]; i >= 0; --i) {
            if (ps[i+k] - ps[i] >= sum) {
                rightIdxs[i] = i;
                sum = ps[i+k] - ps[i]; 
            } else {
                rightIdxs[i] = rightIdxs[i+1];
            }
        }
        // get answer
        for (int i = k; i <= n-2*k; ++i) {
            int l = leftIdxs[i-1], r = rightIdxs[i+k];
            int sum = (ps[i+k] - ps[i]) + (ps[l+k] - ps[l]) + (ps[r+k] - ps[r]);
            if (sum > maxSum) {
                maxSum = sum;
                ans[0] = l; ans[1] = i; ans[2] = r;
            }
        }
        return ans;
                                                          
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
