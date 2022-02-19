// Copyright (C) 2022 by iamslash

import java.util.*;

// 30ms 29.51% 54MB 12.71%
// BFS
// O(26^W) O(N)
//  W: length of beginWord
//  N: count of wordList
class Solution {
    private List<String> getNextWords(String word, Set<String> dictSet) {
        List<String> ans = new ArrayList<>();
        char[] chars = word.toCharArray();
        for (int i = 0; i < chars.length; ++i) {
            char org = chars[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                chars[i] = c;
                if (dictSet.contains(new String(chars))) {
                    ans.add(new String(chars));
                }
            }
            chars[i] = org;            
        }
        return ans;
    }
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> ans = new ArrayList<>();
        Set<String> seen = new HashSet<>();
        Queue<List<String>> q = new ArrayDeque<>();
        Set<String> pool = new HashSet<>(wordList);
        boolean found = false;
        q.add(Arrays.asList(beginWord));
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                List<String> u = q.poll();
                List<String> nextWords = getNextWords(u.get(u.size()-1), pool);
                for (String nextWord: nextWords) {
                    List<String> v = new ArrayList<>(u);
                    v.add(nextWord);
                    if (nextWord.equals(endWord)) {
                        found = true;
                        ans.add(v);
                    }
                    seen.add(nextWord);
                    q.offer(v);
                }
            }
            if (found) {
                break;
            }
            for (String word : seen) {
                pool.remove(word);
            }
            seen.clear();
        }        
        return ans;
    }
}
