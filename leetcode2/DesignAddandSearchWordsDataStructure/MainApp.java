// Copyright (C) 2021 by iamslash

import java.util.*;

// 33ms 99.89% 49.5MB 87.73%
// hash table
// O(N) O(N)
class WordDictionary {
    private Map<Integer, List<String>> dictMap = new HashMap<>();
    public WordDictionary() {
        
    }
    
    public void addWord(String word) {
        int len = word.length();
        dictMap.putIfAbsent(len, new ArrayList<>());
        dictMap.get(len).add(word);
    }
    
    public boolean search(String word) {
        int len = word.length();
        if (dictMap.get(len) == null) {
            return false;
        }
        for (String s : dictMap.get(len)) {
            if (isEqual(s, word)) {
                return true;
            }
        }
        return false;
    }

    private boolean isEqual(String a, String b) {
        for (int i = 0; i < a.length(); ++i) {
            if (b.charAt(i) == '.') {
                continue;
            }
            if (a.charAt(i) != b.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
