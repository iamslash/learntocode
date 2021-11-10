// Copyright (C) 2021 by iamslash

import java.util.*;


//       .
//       a
//       ab b
//       aba ba a
//           i
// word: a b a
//  cnt: 1 1 4
//  sum: 1 2 6

// 12ms 64.45% 39.5MB 92.23%
// brute force
// O(N) O(1)
class Solution {
    private boolean isVowel(char c) {
        return "aeiou".indexOf(c) >= 0;
    }
    public long countVowels(String word) {
        int n = word.length();
        long sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += isVowel(word.charAt(i)) ? i+1 : 0;
            sum += cnt;
        }
        return sum;
    }
}

// 8ms 91.40% 40MB 56.23%
// brute force
// O(N) O(1)
class Solution {
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    public long countVowels(String word) {
        int n = word.length();
        long sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += isVowel(word.charAt(i)) ? i+1 : 0;
            sum += cnt;
        }
        return sum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
