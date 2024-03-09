// Copyright (C) 2024 by iamslash

import java.util.*;

//       24 12  8 6
// nums:  1  2  3 4
//                i
// lprd:  1  1  2 6 
// rprd:  24 12 4 1  

// 2ms 73.78% 54.7MB 23.91%
// prefix product
// O(N) O(N)
class Solution {
    public int[] productExceptSelf(int[] nums) {
>        int n = nums.length;
        int[] leftProds = new int[n];
        int[] rightProds = new int[n];
        int[] ans = new int[n];
        leftProds[0] = 1;
        rightProds[n - 1] = 1;

        for (int i = 1; i < n; ++i) {
            leftProds[i] = leftProds[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            rightProds[i] = rightProds[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = leftProds[i] * rightProds[i];
        }
        
        return ans;
    }
}

//       24 12  8 6
// nums:  1  2  3 4
//        i
//  ans: 24 12  8 6
// cprd:  1  2  6 24
// cprd: 24 24 12 4

// 2ms 73.78% 53.3MB 59.55%
// prefix product
// O(N) O(1)
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, 1);

        // cumulative product
        int cumPrd = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] *= cumPrd;
            cumPrd *= nums[i];
        }

        cumPrd = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= cumPrd;
            cumPrd *= nums[i];
        }

        return ans;
    }
}
