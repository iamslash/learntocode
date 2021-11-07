// Copyright (C) 2021 by iamslash

import java.util.*;

//           i
// word: cuaieuouac
//                j

// 10MS 83.33% 7.5MB 100.00%
// sliding window
// O(N) O(1)
class Solution {
    public int countVowelSubstrings(String word) {
        Set<Character> vowelSet = Set.of('a', 'e', 'i', 'o', 'u');
        Set<Character> curSet = new HashSet<>();
        int n = word.length(), substrCnt = 0;
        char[] wordArr = word.toCharArray();
        for (int i = 0; i < n; ++i, curSet.clear()) {
            int j = i;
            while (j < n && vowelSet.contains(wordArr[j])) {
                curSet.add(wordArr[j++]);
                if (curSet.size() == 5) {
                    ++substrCnt;
                }
            }
        }
        return substrCnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
