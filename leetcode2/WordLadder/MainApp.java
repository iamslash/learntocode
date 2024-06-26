// Copyright (C) 2024 by iamslash

import java.util.*;

// 107ms 37.17% 46.8MB 51.16%
// BFS
// O(N) O(N)
class Pair {
    String word;
    int dist;
    public Pair(String word, int dist) {
        this.word = word;
        this.dist = dist;
    }
}
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String, Integer> visitMap = new HashMap<>();
        for (String word : wordList) {
            visitMap.put(word, 0);
        }
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(beginWord, 1));

        while (!q.isEmpty()) {
            Pair item = q.poll();
            String uWord = item.word;
            int uDist = item.dist;
            if (uWord.equals(endWord)) {
                return uDist;
            }
            for (int i = 0; i < uWord.length(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (uWord.charAt(i) == c) {
                        continue;
                    }

                    char[] uWordArr = uWord.toCharArray();
                    uWordArr[i] = c;
                    String vWord = String.valueOf(uWordArr);
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
