// Copyright (C) 2020 by iamslash

// trie
// 69ms 25.62% 65MB 5.03%
class TrieNode {
	public TrieNode[] next = new TrieNode[26];
	boolean term;
	TrieNode() {
		for (int i = 0; i < 26; ++i)
			next[i] = null;
		term = false;
	}
}

class Trie {
	private TrieNode root;
	
	public Trie() {
		root = new TrieNode();
	}
	public void insert(String s) {
		TrieNode p = root;
		for (int i = 0; i < s.length(); ++i) {
			int j = s.charAt(i) - 'a';
			if (p.next[j] == null)
				p.next[j] = new TrieNode();
			p = p.next[j];
		}
		p.term = true;
	}
    
	public boolean search(String s) {
		TrieNode p = root;
		for (int i = 0; i < s.length(); ++i) {
			int j = s.charAt(i) - 'a';
			if (p.next[j] == null)
				return false;
			p = p.next[j];
		}
		return p.term == true;
	}
    
	public boolean startsWith(String s) {
		TrieNode p = root;
		for (int i = 0; i < s.length(); ++i) {
			int j = s.charAt(i) - 'a';
			if (p.next[j] == null)
				return false;
			p = p.next[j];
		}
		return true;
	}
	private boolean empty(TrieNode u) {
		for (int i = 0; i < 26; ++i) {
			if (u.next[i] != null)
				return false;
		}
		return true;
	}
	private TrieNode _remove(TrieNode u, String s, int i) {
		if (u == null) {
			return null;
		}
		if (i == s.length()) {
			if (u.term)
				u.term = false;
			if (empty(u))
				u = null;
			return u;
		}
		int j = s.charAt(i) - 'a';
		u.next[j] = _remove(u.next[j], s, i+1);
		if (empty(u) && u.term == false)
			u = null;
		return u;
	}
	public void remove(String s) {
		_remove(root, s, 0);
	}
}
