// Copyright (C) 2021 by iamslash

import java.util.*;

// 67ms 100.00% 55.6MB 100.00%
// trie
//                 insert: O(N)
//      countWordsEqualTo: O(N)
// countWordsStartingWith: O(N)
//                  erase: O(N)
class Trie {
	private TrieNode root = new TrieNode();

	class TrieNode {
		public TrieNode[] next = new TrieNode[26];
		public int termCnt = 0;
    public int fromCnt = 0;
	}

	public Trie() {
		
	}
    
	public void insert(String word) {
		TrieNode u = root;
		for (char c : word.toCharArray()) {
			int idx = c - 'a';
			if (u.next[idx] == null) {
				u.next[idx] = new TrieNode();
			}
			u = u.next[idx];
      u.fromCnt++;
		}
		u.termCnt++;
	}
    
	public int countWordsEqualTo(String word) {
		TrieNode u = root;
		for (char c : word.toCharArray()) {
			int idx = c - 'a';
			if (u.next[idx] == null) {
				return 0;
			}
			u = u.next[idx];      
		}
		return u.termCnt;
	}
    
	public int countWordsStartingWith(String prefix) {
		TrieNode u = root;
		for (char c : prefix.toCharArray()) {
      // System.out.printf("%c ", c);
			int idx = c - 'a';
			if (u.next[idx] == null) {
				return 0;
			}
			u = u.next[idx];
		}
    return u.fromCnt;
	}
    
	public void erase(String word) {
		TrieNode u = root;
		for (char c : word.toCharArray()) {
			int idx = c - 'a';
			u = u.next[idx];      
      u.fromCnt--;
		}
		u.termCnt--;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
