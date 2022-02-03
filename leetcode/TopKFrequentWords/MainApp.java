// Copyright (C) 2022 by iamslash

import java.util.*;

//     k: 2
// words: i love leetcode i love coding
//        i love leetcode coding
//        2 2    1        1

// 10ms 45.26% 44.6MB 10.72%
// This is about picking most frequent words less than or equal to k.
// hash map, sort
// O(NlgN) O(N)
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> freqMap = new HashMap<>();
        for (String word : words) {
            freqMap.put(word, freqMap.getOrDefault(word, 0) + 1);
        }
        List<Map.Entry<String, Integer>> wordList = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : freqMap.entrySet()) {
            wordList.add(entry);
        }
        Collections.sort(wordList, (a, b) -> {
                if (a.getValue() == b.getValue()) {
                    return a.getKey().compareTo(b.getKey());
                }
                return b.getValue() - a.getValue();
            });
        List<String> ans = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : wordList) {
            ans.add(entry.getKey());
            if (--k <= 0) {
                break;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
