// Copyright (C) 2022 by iamslash

import java.util.*;

// 288ms 41.99% 131.3MB 7.64%
// TrieNode
class TrieNode {
    char c;
    TrieNode[] child = new TrieNode[128];
    Map<String, Integer> freqMap = new HashMap<>();
    TrieNode(char c) {
        this.c = c;
    }
}
class Pair {
    String sentence;
    int cnt;
    Pair(String sentence, int cnt) {
        this.sentence = sentence;
        this.cnt = cnt;
    }
}
class AutocompleteSystem {
    TrieNode trie = new TrieNode(' ');
    String prefix = "";
    private void insert(String sentence, int cnt) {
        TrieNode u = trie;
        for (char c : sentence.toCharArray()) {
            if (u.child[c] == null) {
                u.child[c] = new TrieNode(c);
            }
            u = u.child[c];
            u.freqMap.put(sentence, u.freqMap.getOrDefault(sentence, 0) + cnt);
        }
    }
    public AutocompleteSystem(String[] sentences, int[] times) {
        for (int i = 0; i < sentences.length; ++i) {
            insert(sentences[i], times[i]);
        }
    }
    public List<String> input(char c) {
        // Handle '#'
        if (c == '#') {
            insert(prefix, 1);
            prefix = "";
            return new ArrayList<>();
        }
        // Traverse Trie
        prefix += c;
        TrieNode u = trie;
        for (char d : prefix.toCharArray()) {
            if (u.child[d] == null) {
                return new ArrayList<>();
            }
            u = u.child[d];
        }
        // Pick top 3
        Queue<Pair> pq = new PriorityQueue<>((a, b) -> {
                if (a.cnt == b.cnt) {
                    return a.sentence.compareTo(b.sentence);
                }
                return b.cnt - a.cnt;
        });
        for (String key : u.freqMap.keySet()) {
            pq.offer(new Pair(key, u.freqMap.get(key)));
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 3 && !pq.isEmpty(); ++i) {
            ans.add(pq.poll().sentence);
        }
        return ans;
    }
}
