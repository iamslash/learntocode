// Copyright (C) 2022 by iamslash

import java.util.*;

//
// arr: 2 1 3 1 2 3 3
//        i

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

// 378ms 11.36% 227.6MB 25.27%
// partial sum, back and forth
// O(N) O(N)
class Solution {
    public long[] getDistances(int[] arr) {
        int n = arr.length;
        long[] ans = new long[n];
        // traverse from left to right
        Map<Integer, Long> sumMap = new HashMap<>();
        Map<Integer, Integer> cntMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int num = arr[i];
            if (!sumMap.containsKey(num)) {
                sumMap.put(num, 0l);
                cntMap.put(num, 0);
            }
            ans[i] += i * (long)cntMap.get(num) - sumMap.get(num);
            sumMap.put(num, sumMap.get(num) + i);
            cntMap.put(num, cntMap.get(num) + 1);
        }
        // traverse from right to left
        sumMap.clear();
        cntMap.clear();
        for (int i = n-1; i >= 0; --i) {
            int num = arr[i];
            if (!sumMap.containsKey(num)) {
                sumMap.put(num, 0l);
                cntMap.put(num, 0);
            }
            ans[i] += (n-i-1) * (long)cntMap.get(num) - sumMap.get(num);
            sumMap.put(num, sumMap.get(num) + (n-i-1));
            cntMap.put(num, cntMap.get(num) + 1);
        }
        return ans;
    }
}

// 72ms 86.08% 204.2MB 46.15%
// partial sum, back and forth
// O(N) O(N)
class Solution {
    private void sum(int[] arr, int beg, int inc, long[] ans) {
        int n = arr.length;
        long[] cnts = new long[100_001], sums = new long[100_001];
        for (int i = beg, j = 0; 0 <= i && i < n; i += inc, ++j) {
            int num = arr[i];
            ans[i] += cnts[num] * j - sums[num];
            cnts[num]++;
            sums[num] += j;
        }
    }
    public long[] getDistances(int[] arr) {
        int n = arr.length;
        long[] ans = new long[n];
        sum(arr, 0, 1, ans);
        sum(arr, n-1, -1, ans);
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
