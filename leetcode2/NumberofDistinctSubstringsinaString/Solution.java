// Copyright (C) 2020 by iamslash

import java.util.*;

// 628ms 100.00% 39.4%MB 100.00%
// hash set
// O(N^2) O(N)
class Solution {
	public int countDistinct(String s) {
		int ans = 0, n = s.length();
		for (int j = 1; j <= n; ++j) {
			Set<String> wordSet = new HashSet<>();
			for (int i = 0; i + j <= n; ++i) {
				wordSet.add(s.substring(i, i+j));
			}
			ans += wordSet.size();
		}
		return ans;
	}
}

// 65ms 100.00% 75.6MB 100.00%
// trie
// O(N^2) O(N)
class Node {
	Node[] children = new Node[26];
}
class Solution {
	public int countDistinct(String s) {
		Node root = new Node();
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			Node u = root;
			for (int j = i; j < s.length(); j++) {
				int idx = s.charAt(j) - 'a';
				if (u.children[idx] == null) {
					u.children[idx] = new Node();
					ans++;
				}
				u = u.children[idx];
			}
		}
		return ans;
	}
}
