// Copyright (C) 2022 by iamslash

import java.util.*;

// 134ms 80.95% 59.5MB 68.55%
// trie
class TrieNode {
    TrieNode[] child = new TrieNode[128];
    Map<String, Integer> freqMap = new HashMap<>();
}
class AutocompleteSystem {
    TrieNode trie = new TrieNode();
    String prefix = "";
    private void insert(String sentence, int freq) {
        TrieNode u = trie;
        for (char c : sentence.toCharArray()) {
            if (u.child[c] == null) {
                u.child[c] = new TrieNode();    
            }
            u = u.child[c];
            u.freqMap.put(sentence, u.freqMap.getOrDefault(sentence, 0) + freq);
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
        prefix += c;
        // Traverse trie and get freqs
        TrieNode u = trie;
        for (char d : prefix.toCharArray()) {
            if (u.child[d] == null) {
                return new ArrayList<>();
            }
            u = u.child[d];
        }
        // Sort
        Queue<Map.Entry<String, Integer>> pq = new PriorityQueue<>((a, b) -> {
            if (a.getValue() == b.getValue()) {
                return b.getKey().compareTo(a.getKey());
            }
            return a.getValue() - b.getValue();
        });
        for (Map.Entry<String, Integer> item : u.freqMap.entrySet()) {
            pq.offer(item);
            if (pq.size() > 3) {
                pq.poll();
            }
        }
        List<String> ans = new ArrayList<>();
        while (!pq.isEmpty()) {
            ans.add(pq.poll().getKey());
        }
        Collections.reverse(ans);
        return ans;
    }
}
