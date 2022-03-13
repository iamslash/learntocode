// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 1
//  key: 9
// nums: 3 4 9 1 3 9 5
//           

// 85ms 33.33% 43MB 100.00%
// hash set
// O(N) O(N)
class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        Set<Integer> idxSet = new LinkedHashSet<>();
        List<Integer> idxList = new ArrayList<>(); 
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                idxList.add(i);
            }
        }
        for (int idx : idxList) {
            int fr = Math.max(0, idx - k);
            int to = Math.min(n-1, idx + k);
            for (int i = fr; i <= to; ++i) {
                idxSet.add(i);
            }
        }
        return new ArrayList<>(idxSet);
    }
}

// [222,151,842,244,103,736,219,432,565,216,36,198,10,367,778,111,307,460,92,622,750,36,559,983,782,432,312,111,676,179,44,86,766,371,746,905,850,170,892,80,449,932,295,875,259,556,730,441,153,869]
// 153
// 19

// 162ms 33.33% 86.6MB 33.33%
// sort, hash set
// O(NlgN) O(N)
class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        Set<Integer> idxSet = new HashSet<>();
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != key) {
                continue;
            }
            for (int j = 0; j <= k; ++j) {
                if (i + j < n) {
                    idxSet.add(i+j);
                }
                if (i - j >= 0) {
                    idxSet.add(i-j);
                }
            }
        }
        List<Integer> ans = new ArrayList<>(idxSet);
        Collections.sort(ans);
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
