// Copyright (C) 2023 by iamslash

import java.util.*;

//                  i
//   words: 1 2 p p p
// numList: 1 2
//     ans: 2 1

// 3ms 100.00% 43.7MB 66.67%
// linked list
// O(N) O(N)
class Solution {
    public List<Integer> lastVisitedIntegers(List<String> words) {
        int k = 0;
        List<Integer> ans = new ArrayList<>();
        List<Integer> numList = new ArrayList<>();
        for (String word : words) {
            if (word.equals("prev")) {
                k++;
                int n = numList.size(), num = - 1;
                if (n - k >= 0) {
                    num = numList.get(n - k);
                }
                ans.add(num);
            } else {
                numList.add(Integer.valueOf(word));
                k = 0;
            }
        }
        return ans;
    }
}
