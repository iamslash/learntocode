// Copyright (C) 2022 by iamslash

import java.util.*;

// 6ms 28.57% 42.2MB 14.29%
// hash map
// O(N) O(N)
class Solution {
    public String oddString(String[] words) {
        Map<Integer, List<String>> wordMap = new HashMap<>();
        for (String word : words) {
            List<Integer> diffList = new ArrayList<>();
            for (int i = 1; i < word.length(); ++i) {
                diffList.add(word.charAt(i) - word.charAt(i-1));
            }
            wordMap.computeIfAbsent(diffList.hashCode(), a -> new ArrayList<>()).add(word);
        }
        // System.out.println(wordMap);
        for (Map.Entry<Integer, List<String>> entry : wordMap.entrySet()) {
            if (entry.getValue().size() == 1) {
                return entry.getValue().get(0);
            }
        }
        return "";
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
