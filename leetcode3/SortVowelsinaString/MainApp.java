// Copyright (C) 2023 by iamslash

import java.util.*;

// 62ms 100.00% 50.1MB 16.67% 
// sort
// O(NlgN) O(N)
class Solution {
    public String sortVowels(String s) {
        int n = s.length();
        List<Character> vowelList = new ArrayList<>();
        List<Integer> idxList = new ArrayList<>();
        char[] chrs = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowelList.add(c);
                idxList.add(i);
            }
        }
        // System.out.println(vowelList);
        Collections.sort(vowelList);
        // System.out.println(vowelList);
        for (int i = 0; i < idxList.size(); ++i) {
            chrs[idxList.get(i)] = vowelList.get(i);
        }
        return new String(chrs);
    }
}
