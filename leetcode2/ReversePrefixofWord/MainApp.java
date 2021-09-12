// Copyright (C) 2021 by iamslash

import java.util.*;

// a b c d e f d
// d f e d c b a

// 0ms 100.00% 38.7MB 33.33%
// linear traversal
// O(N) O(N)
class Solution {
    public String reversePrefix(String word, char ch) {
        StringBuilder sb = new StringBuilder();
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            char c = word.charAt(i);
            sb.append(c);
            if (c == ch) {
                sb.reverse();
                if (i < n-1) {
                    sb.append(word.substring(i+1));
                }
                return sb.toString();
            }
        }
        return sb.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
