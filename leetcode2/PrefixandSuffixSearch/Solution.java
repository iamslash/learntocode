// Copyright (C) 2020 by iamslash

import java.util.*;

// Time Limit Exceeded
// linear traversal
// wordFilter: O(1) O(1)
//          f: O(NL)O(1)
class WordFilter {
	String[] dictArr;
	public WordFilter(String[] W) {
		dictArr = W;
	}
	public int f(String prefix, String suffix) {
		for (int i = dictArr.length-1; i >= 0; --i) {
			if (dictArr[i].startsWith(prefix) &&
					dictArr[i].endsWith(suffix)) {
				return i;
			}
		}
		return -1;
	}
}

// WordFilter for "abc"
// #c 0
// a#c 0
// a# 0
// # 0
// ab# 0
// #bc 0
// abc#c 0
// ab#bc 0
// a#abc 0
// ab#c 0
// abc# 0
// #abc 0
// a#bc 0
// abc#bc 0
// abc#abc 0
// ab#abc 0

// 236ms 54.43% 71.4MB 75.78%
// hash map
// wordFilter: O(NW^2) O(NW)
//          f: O(1)    O(NW)
class WordFilter {
	private Map<String, Integer> dictMap = new HashMap<>();
	public WordFilter(String[] W) {
		for (int k = 0; k < W.length; ++k) {
			String w = W[k];
			for (int i = 0; i <= w.length(); ++i) {
				for (int j = 0; j <= w.length(); ++j) {
					String key = w.substring(0, i) + "#" +
							w.substring(w.length()-j);
					dictMap.put(key, k);
				}
			}
		}
	}
    
	public int f(String prefix, String suffix) {
		String key = prefix + "#" + suffix;
		if (dictMap.containsKey(key)) {
			return dictMap.get(key);
		}
		return -1;
	}
}

// Time Limit Exceeded
// double hash map
// wordFilter: O(NW) O(NW)
//          f: O(N)  O(NW)
class WordFilter {
	private Map<String, List<Integer>> prefixMap = new HashMap<>();
	private Map<String, List<Integer>> suffixMap = new HashMap<>();
	public WordFilter(String[] W) {
		for (int k = 0; k < W.length; ++k) {
			for (int i = 0; i <= W[k].length(); i++) {
				String ps = W[k].substring(0, i);
				prefixMap.putIfAbsent(ps, new ArrayList<>());
				prefixMap.get(ps).add(k);
				String ss = W[k].substring(W[k].length()-i);
				suffixMap.putIfAbsent(ss, new ArrayList<>());
				suffixMap.get(ss).add(k);
			}
		}
	}
    
	public int f(String prefix, String suffix) {
		if (!prefixMap.containsKey(prefix) ||
				!suffixMap.containsKey(suffix)) {
			return -1;
		}
		List<Integer> prefixList = prefixMap.get(prefix);
		List<Integer> suffixList = suffixMap.get(suffix);
		int i = prefixList.size() - 1;
		int j = suffixList.size() - 1;
		while (i >= 0 && j >= 0) {
			int prefixIdx = prefixList.get(i);
			int suffixIdx = suffixList.get(j);
			if (prefixIdx == suffixIdx) {
				return prefixIdx;
			} else if (prefixIdx < suffixIdx) {
				suffixIdx--;
			} else {
				prefixIdx--;
			}				
		}
		return -1;
	}
}

