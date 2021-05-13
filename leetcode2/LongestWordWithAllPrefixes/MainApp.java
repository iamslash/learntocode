// Copyright (C) 2021 by iamslash

import java.util.*;

// words: k
//        ki
//        kir
//        kira
//        kiran
//
// words: a
//        ap
//        app
//        appl
//        apply
//        banana
//
// words: ab
//        abc
//        bc
//        qwe

// sort, hash set
// O(NlgN) O(N)
class Solution {
	public String longestWord(String[] words) {
		Arrays.sort(words, (a, b) -> {
				return a.compareTo(b);
			});
		Set<String> wordSet = new HashSet<>();
		String ans = "";
		wordSet.add("");
		for (String s : words) {
			String prv = s.substring(0, s.length()-1);
      // System.out.println(wordSet);
      // System.out.printf("  prv: %s\n", prv);
			if (wordSet.contains(prv)) {
				wordSet.add(s);
				if (ans.length() < s.length() || s.compareTo(ans) < 0) {
					ans = s;
				}
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
