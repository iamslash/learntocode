// Copyright (C) 2024 by iamslash

import java.util.*;

// Time Limit Exceeded
// brute force
// O(N^2) O(1)
class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        List<Integer> ans = new ArrayList<>();
        int sLen = s.length(), aLen = a.length(), bLen = b.length();
        for (int i = 0; i < sLen - aLen + 1; ++i) {
            if (s.substring(i, i + aLen).equals(a)) {
                int fr = Math.max(0, i - k), to = Math.min(sLen - bLen + 1, i + k + 1);
                for (int j = fr; j < to; ++j) {
                    if (s.substring(j, j + bLen).equals(b)) {
                        ans.add(i);
                        break;
                    }
                }
            }
        }
        return ans;
    }
}

// 437ms 15.67% 48.8MB 6.97%
// sort
// O(NlgN) O(N)
class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        List<Integer> ans = new ArrayList<>();
        List<Integer> aIdxs = new ArrayList<>();
        List<Integer> bIdxs = new ArrayList<>();
        int sLen = s.length(), aLen = a.length(), bLen = b.length();

        for (int i = 0; i <= sLen - aLen; ++i) {
            if (s.substring(i, i + aLen).equals(a)) {
                aIdxs.add(i);
            }
        }

        for (int i = 0; i <= sLen - bLen; ++i) {
            if (s.substring(i, i + bLen).equals(b)) {
                bIdxs.add(i);
            }
        }

        for (int i : aIdxs) {
            for (int j : bIdxs) {
                if (Math.abs(i - j) <= k) {
                    ans.add(i);
                    break;
                }
            }
        }

        ans.sort(null);

        return ans;
    }
}
