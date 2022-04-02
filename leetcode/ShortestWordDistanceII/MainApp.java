// Copyright (C) 2022 by iamslash

import java.util.*;

// 31ms 80.01% 49.2MB 82.47%
// hash map, two pointers
// shortest: O(N) O(N)
class WordDistance {

    private Map<String, List<Integer>> str2distsMap = new HashMap<>();

    public WordDistance(String[] wordsDict) {
        for (int i = 0; i < wordsDict.length; ++i) {
            str2distsMap.putIfAbsent(wordsDict[i], new ArrayList<>());
            str2distsMap.get(wordsDict[i]).add(i);
        }
        System.out.println(str2distsMap);
    }
    
    public int shortest(String word1, String word2) {
        List<Integer> idxs1 = str2distsMap.get(word1);
        List<Integer> idxs2 = str2distsMap.get(word2);
        int i = 0, j = 0;
        int m = idxs1.size(), n = idxs2.size(); 
        int minDist = 30000;
        while(i < m && j < n) {
            int idx1 = idxs1.get(i), idx2 = idxs2.get(j);
            minDist = Math.min(minDist, Math.abs(idx1 - idx2));
            if (idx1 < idx2) {
                i++;
            } else {
                j++;
            }
        }
        return minDist;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
