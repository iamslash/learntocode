// Copyright (C) 2021 by iamslash
import java.util.*;

// nums: 5 -1 6 9 10

// 2ms 100.00% 46.9MB 97.6%
// back and fowarth
// O(N) O(N)
class Solution {
    public int binarySearchableNumbers(int[] nums) {
        if (nums.length == 1) {
            return 1;
        }
        int minNum = 100_001, maxNum =-100_001, n = nums.length, ans = 0;
        boolean[] valids = new boolean[n];
        // forward
        for (int i = 0; i < n; ++i) {
            if (nums[i] > maxNum) {
                valids[i] = true;
            }
            maxNum = Math.max(maxNum, nums[i]);
        }
        // backward
        for (int i = n-1; i >= 0; --i) {
            if (valids[i] && nums[i] < minNum) {
                ans++;
            }
            minNum = Math.min(minNum, nums[i]);
        }
        return ans;
    }
}

//                  i
//   nums: 3 -1 2 6 7 8 9
//   stck: 6
// maxNum: 6

// 6ms 35.07% 48MB 66.42%
// monotonic increasing stack
// O(N) O(N)
class Solution {
    public int binarySearchableNumbers(int[] nums) {
        Deque<Integer> deq = new ArrayDeque<>();
        int maxNum = -100_001;
        for (int num : nums) {
            // remove big ones
            while (!deq.isEmpty() && deq.peekLast() > num) {
                deq.removeLast();
            }
            // add new one
            if (num > maxNum) {
                deq.addLast(num);
            }
            maxNum = Math.max(maxNum, num);
        }
        return deq.size();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
