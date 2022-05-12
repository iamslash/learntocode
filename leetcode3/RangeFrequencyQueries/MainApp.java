// Copyright (C) 2022 by iamslash

import java.util.*;

// Time Limit Exceeded
class RangeFreqQuery {
    Map<Integer, List<Integer>> num2idxsMap = new HashMap<>();
    public RangeFreqQuery(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            num2idxsMap.putIfAbsent(arr[i], new ArrayList<>());
            num2idxsMap.get(arr[i]).add(i);
        }
    }
    
    public int query(int left, int right, int value) {
        if (!num2idxsMap.containsKey(value)) {
            return 0;
        }
        int cnt = 0;
        List<Integer> idxs = num2idxsMap.get(value);
        for (int idx : idxs) {
            if (left <= idx && idx <= right) {
                cnt++;
            }
        }
        return cnt;
    }
}

// sorted map
// query: O(lgN) O(N)
class RangeFreqQuery {
    // {num, {idx, size of map}}
    Map<Integer, TreeMap<Integer, Integer>> numMap = new HashMap<>();
    public RangeFreqQuery(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            numMap.putIfAbsent(arr[i], new TreeMap<>());
            numMap.get(arr[i]).put(i, numMap.get(arr[i]).size());
        }
    }
    
    public int query(int left, int right, int value) {
        if (!numMap.containsKey(value)) {
            return 0;
        }
        int cnt = 0;
        TreeMap<Integer, Integer> psMap = numMap.get(value);
        Integer a = psMap.ceilingKey(left), b = psMap.floorKey(right);
        if (a == null || b == null) {
            return 0;
        }
        return psMap.get(b) - psMap.get(a) + 1;
    }
}

// Idea: binary search
//   l
// 1 3 5 7 9    (r-1) - l + 1
//        r
//   l
// 1 3 5 7 9    r     - l + 1
//         r

// 289ms 43.92% 200.6MB 46.73%
// binary search
// query: O(lgN) O(N)
class RangeFreqQuery {
    Map<Integer, List<Integer>> num2idxsMap = new HashMap<>();
    public RangeFreqQuery(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            num2idxsMap.putIfAbsent(arr[i], new ArrayList<>());
            num2idxsMap.get(arr[i]).add(i);
        }
    }
    
    public int query(int left, int right, int value) {
        if (!num2idxsMap.containsKey(value)) {
            return 0;
        }
        List<Integer> idxs = num2idxsMap.get(value);
        int l = Collections.binarySearch(idxs, left);
        l = (l < 0) ? ~l : l;
        int r = Collections.binarySearch(idxs, right);
        r = (r < 0) ? ~r - 1 : r; 
        return r - l + 1;
    }
}
