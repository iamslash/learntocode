// Copyright (C) 2021 by iamslash

import java.util.*;

// 25ms 92.40% 77.6MB 92.49%
// hash map
// O(N) O(N)
class Solution {
	public String evaluate(String s, List<List<String>> knowledge) {
		Map<String, String> dictMap = new HashMap<>();
		for (List<String> words : knowledge) {
			dictMap.put(words.get(0), words.get(1));			
		}
		StringBuilder ansSb = new StringBuilder();
		StringBuilder wordSb = null;
		for (char c : s.toCharArray()) {
			if (c == '(') {
				wordSb = new StringBuilder();
			} else if (c == ')') {
				String key = wordSb.toString();
				if (dictMap.containsKey(key)) {
					ansSb.append(dictMap.get(key));
				} else {
					ansSb.append('?');
				}
				wordSb = null;
			} else if (wordSb != null) {
				wordSb.append(c);
			} else {
				ansSb.append(c);
			}
		}		
		return ansSb.toString();
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
