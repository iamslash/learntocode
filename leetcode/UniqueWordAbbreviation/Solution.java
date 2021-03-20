// Copyright (C) 2021 by iamslash

import java.util.*;

// 192ms 5.22% 48.7MB 64.98%
// hash set
// isUnique: O(1) O(1)
class ValidWordAbbr {

	private Map<String, String> wordMap = new HashMap<>();

	private String abbr(String s) {
		if (s.length() <= 2) {
			return s;
		}
		int n = s.length();
		return String.format("%c%d%c",
												 s.charAt(0),
												 n - 2,
												 s.charAt(n-1));
	}

	public ValidWordAbbr(String[] dict) {
		for (String word : dict) {
			String s = abbr(word);
			if (wordMap.containsKey(s)) {
				if (!wordMap.get(s).equals(word)) {
					wordMap.put(s, "");
				}
			} else {
				wordMap.put(s, word);
			}
		}						 
	}
    
	public boolean isUnique(String word) {
		String s = abbr(word);
    return !wordMap.containsKey(s) ||
				wordMap.get(s).equals(word);
	}
}
