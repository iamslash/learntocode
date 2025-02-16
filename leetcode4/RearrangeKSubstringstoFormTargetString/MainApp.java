// Copyright (C) 2025 by iamslash

import java.util.*;

// 65ms 71.02% 49.90MB 71.02%
// hash map
// O(N) O(N)
class Solution {
    public boolean isPossibleToRearrange(String s, String t, int k) {
        Map<String, Integer> srcMap = new HashMap<>();
        int n = s.length(), substrLen = n / k;

        for (int i = 0; i < n; i += substrLen) {
            String srcStr = s.substring(i, i + substrLen);
            srcMap.put(srcStr, srcMap.getOrDefault(srcStr, 0) + 1);
        }

        for (int i = 0; i < n; i += substrLen) {
            String dstStr = t.substring(i, i + substrLen);
            if (!srcMap.containsKey(dstStr)) {
                return false;
            }
            srcMap.put(dstStr, srcMap.get(dstStr) - 1);
            if (srcMap.get(dstStr) == 0) {
                srcMap.remove(dstStr);
            }
        }

        return true;
    }
}
