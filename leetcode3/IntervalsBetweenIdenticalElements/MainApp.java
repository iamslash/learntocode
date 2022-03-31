// Copyright (C) 2022 by iamslash

import java.util.*;

// Time Limit Exceeded
// hash map
// O(N) O(N)
class Solution {
    public long[] getDistances(int[] arr) {
        int n = arr.length;
        Map<Integer, List<Integer>> val2idxsMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            val2idxsMap.putIfAbsent(arr[i], new ArrayList<>());
            val2idxsMap.get(arr[i]).add(i);
        }
        long[] ans = new long[n];
        for (int i = 0; i < n; ++i) {
            long sum = 0;
            for (int idx : val2idxsMap.get(arr[i])) {
                if (idx != i) {
                    sum += Math.abs(i - idx);
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
