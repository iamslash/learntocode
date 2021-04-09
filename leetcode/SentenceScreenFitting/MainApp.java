// Copyright (C) 2021 by iamslash

import java.util.*;

//     rows: 3
//     cols: 6
//           
// sentence: a bcd e a bcd e a bcd e ...
//           012345
//                 012345
//                     012345

// 6ms 82.23% 36.3MB 66.45%
// string
// O(N) O(N)
class Solution {
	public int wordsTyping(String[] sentence, int rows, int cols) {
		StringBuilder sb = new StringBuilder();
		for (String word : sentence) {
			sb.append(word);
			sb.append(" ");
		}
		String s = sb.toString();
		int i = 0, n = s.length();
		for (int y = 0; y < rows; ++y) {
			i += cols;
			if (s.charAt(i % n) == ' ') {
				i++;
			} else {
				while (i > 0 && s.charAt((i-1) % n) != ' ') {
					i--;
				}
			}
		}
		return i / n;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
