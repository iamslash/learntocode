// Copyright (C) 2021 by iamslash

import java.util.*;

// 133ms 59.02% 49.6MB 18.08%
// Trie
class TrieNode {
	char ch;
	Map<Character, TrieNode> nextMap = new HashMap<>();
	Map<String, Integer> cntMap = new HashMap<>();
	public TrieNode(Character c) {
		this.ch = c;
	}
}
class Pair {
	String word;
	Integer cnt;
	public Pair(String s, int t) {
		this.word = s;
		this.cnt = t;
	}
}
class AutocompleteSystem {
	private TrieNode root;
	private String prefix;
	private void insert(String word, int cnt) {
		TrieNode u = root;
		for (char c : word.toCharArray()) {
			Character ch = c;
			if (!u.nextMap.containsKey(ch)) {
				u.nextMap.put(c, new TrieNode(ch));
			}
			u = u.nextMap.get(ch);
			u.cntMap.put(word, u.cntMap.getOrDefault(word, 0) + cnt);
		}
	}
	public AutocompleteSystem(String[] sentences, int[] times) {
		root = new TrieNode(' ');
		prefix = "";
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
		TrieNode u = root;
		for (char d : prefix.toCharArray()) {
			if (!u.nextMap.containsKey(d)) {
				return new ArrayList<>();
			}
			u = u.nextMap.get(d);
		}
		// Pick top 3
		PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
				if (a.cnt == b.cnt) {
					return a.word.compareTo(b.word);
				}
				return b.cnt - a.cnt;
		});
		for (String key : u.cntMap.keySet()) {
			pq.offer(new Pair(key, u.cntMap.get(key)));
		}
		List<String> ans = new ArrayList<>();
		for (int i = 0; i < 3 && !pq.isEmpty(); ++i) {
			ans.add(pq.poll().word);
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
