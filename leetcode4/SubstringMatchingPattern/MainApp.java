// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 100.00% 42.87MB 87.20%
// brute force
// O(N) O(1)
class Solution {
    public boolean hasMatch(String s, String p) {
        int idxStar = p.indexOf('*');
        int idxFirst = s.indexOf(p.substring(0, idxStar));
        int idxSecond = s.indexOf(p.substring(idxStar + 1), idxFirst + idxStar);

        if (idxFirst != -1 && idxSecond != -1) {
            return true;
        }

        return false;
    }
}
