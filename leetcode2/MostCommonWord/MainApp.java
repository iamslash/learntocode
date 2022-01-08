// Copyright (C) 2021 by iamslash

import java.util.*;

// 47ms 5.30% 41.7MB 10.43%
// hash map, hash set
// O(N) O(N)
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> banSet = new HashSet<>(Arrays.asList(banned));
        Map<String, Integer> wordMap = new HashMap<>();
        String[] words = paragraph.replaceAll("\\W+", " ")
            .toLowerCase()
            .split("\\s+");
        for (String word : words) {
            if (!banSet.contains(word)) {
                wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
            }
        }
        return Collections.max(wordMap.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
