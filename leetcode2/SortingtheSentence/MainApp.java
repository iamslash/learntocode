// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 100.00% 37.3MB 100.00%
// split, join
// O(N) O(N)
class Solution {
	public String sortSentence(String s) {
		String[] words = s.split(" ");
		String[] ans = new String[words.length];
		for (String word : words) {
			int i = word.charAt(word.length()-1)-'1';
			ans[i] = word.substring(0, word.length()-1);
		}
		return String.join(" ", ans);
	}
}

public class MainApp {
  public static void main(String[] args) {
		
  }
}
