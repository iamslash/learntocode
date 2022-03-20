// Copyright (C) 2022 by iamslash

import java.util.*;

// 4ms 79.16% 44.3MB 54.18%
// sort
// O(NlgN) O(1)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        return nums[n-k];
    }
}

// 1ms 99.52% 42.4MB 79.11%
// quick select
// O(NlgN) O(lgN)
class Solution {
  private void swap(int[] nums, int i, int j) {
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;        
  }
  private int partition(int[] nums, int left, int right, int pivotIdx) {
      int pivotVal = nums[pivotIdx];
      swap(nums, pivotIdx, right);
      int newPivotIdx = left;
      for (int i = left; i <= right; ++i) {
          if (nums[i] < pivotVal) {
              swap(nums, newPivotIdx, i);
              newPivotIdx++;
          }
      }
      swap(nums, newPivotIdx, right);
      return newPivotIdx;        
  }
  private int quickSelect(int[] nums, int left, int right, int kthIdx) {
      if (left == right) {
          return nums[left];
      }
      Random rand = new Random();
      int pivotIdx = left + rand.nextInt(right - left);
      pivotIdx = partition(nums, left, right, pivotIdx);
      if (kthIdx == pivotIdx) {
          return nums[kthIdx];
      } else if (kthIdx < pivotIdx) {
          return quickSelect(nums, left, pivotIdx-1, kthIdx);
      }
      return quickSelect(nums, pivotIdx + 1, right, kthIdx);
  }
  public int findKthLargest(int[] nums, int k) {
      int n = nums.length;
      return quickSelect(nums, 0, n-1, n-k);
  }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
