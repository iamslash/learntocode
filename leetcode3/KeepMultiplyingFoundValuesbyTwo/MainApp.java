// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 87.13% 42.1MB 90.81%
// hash set
// O(N) O(N)
class Solution {
    public int findFinalValue(int[] nums, int original) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }
        while (original <= 1000) {
            if (!numSet.contains(original)) {
                break;
            }
            original *= 2;
        }
        return original;
    }
}

// 1ms 96.99% 44.8MB 48.52%
// recursion
// O(N^2) O(N)
class Solution {
    public int findFinalValue(int[] nums, int original) {
        for (int num : nums) {
            if (num == original) {
                return findFinalValue(nums, original*2);
            }
        }
        return original;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
