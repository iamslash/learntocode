// Copyright (C) 2022 by iamslash

import java.util.*;

// 8ms 50.00% 44.2MB 50.00%
// hash map
// O(N) O(N)
class Solution {
    public String decodeMessage(String key, String message) {
        Map<Character, Character> cypherMap = new HashMap<>();
        char encCh = 'a';
        for (char c : key.toCharArray()) {
            if (c >= 'a' && c <= 'z' &&
                !cypherMap.containsKey(c)) {
                cypherMap.put(c, encCh++);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char c : message.toCharArray()) {
            if (cypherMap.containsKey(c)) {
                sb.append(cypherMap.get(c));
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
