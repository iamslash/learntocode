// Copyright (C) 2022 by iamslash

import java.util.*;

// 87ms 58.55% 40.6MB 82.07%
// BFS
// O(N) O(N)
class Pair {
    String word;
    Integer dist;
    public Pair(String word, int dist) {
        this.word = word;
        this.dist = dist;
    }
}
class Solution {
    public int ladderLength(String beg, String end, List<String> wordList) {
        Map<String, Integer> visitMap = new HashMap<>();
        for (String word : wordList) {
            visitMap.put(word, 0);
        }
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(beg, 1));
        while (!q.isEmpty()) {
            Pair pair = q.poll();
            String uWord = pair.word;
            int uDist = pair.dist;
            if (uWord.equals(end)) {
                return uDist;
            }
            for (int i = 0; i < uWord.length(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    // Continue when same character
                    if (uWord.charAt(i) == c) {
                        continue;
                    }
                    char[] uWordArr = uWord.toCharArray();
                    uWordArr[i] = c;
                    String vWord = String.valueOf(uWordArr);
                    // Continue when not in wordList or cycle
                    if (!visitMap.containsKey(vWord) ||
                        visitMap.get(vWord) > 0) {
                        continue;
                    }
                    int vDist = uDist + 1;
                    visitMap.put(vWord, vDist);
                    q.offer(new Pair(vWord, vDist));
                }
            }
        }
        return 0;
    }
}
