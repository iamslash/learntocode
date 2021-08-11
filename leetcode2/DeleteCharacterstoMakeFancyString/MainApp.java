// Copyright (C) 2021 by iamslash

import java.util.*;

//   s: leeetcode
//          i
// cnt: 1
// ans: lee

// 31ms 88.33% 40.4MB 70.22%
// linear traversal
// O(N) O(N)
class Solution {
    public String makeFancyString(String s) {
				int cnt = 1, n = s.length();
				StringBuilder ans = new StringBuilder();
				ans.append(s.charAt(0));
				for (int i = 1; i < n; ++i) {
						char c = s.charAt(i);
						if (s.charAt(i-1) == c) {
								cnt++;
						} else {
								cnt = 1;
						}
						if (cnt < 3) {
								ans.append(c);
						}
				}
				return ans.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
