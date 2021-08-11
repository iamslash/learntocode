// Copyright (C) 2021 by iamslash

import java.util.*;

//     s: i love leetcode
//        i
// words: i love leetcode apples

// s should be prefix of concatenated words !!!

// 1ms 94.58% 38.9MB 89.83%
// linear traversal
// O(N) O(1)
class Solution {
    public boolean isPrefixString(String s, String[] words) {
				int n = s.length(), i = 0;
				String cumWord = "";
				for (String word : words) {
						if (cumWord.length() < n) {
								cumWord += word;
						} else {
								break;
						}
				}
				return cumWord.equals(s);
    }
}

public class MainApp {
  public static void main(String[] args) {
			
  }
}
