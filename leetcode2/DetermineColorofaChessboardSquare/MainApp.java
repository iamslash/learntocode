// Copyright (C) 2021 by iamslash

// 0ms 100.00% 37.3MB 50.00%
// math
// O(1) O(1)
class Solution {
	public boolean squareIsWhite(String coordinates) {
		int x = coordinates.toCharArray()[0]-'a';
		int y = coordinates.toCharArray()[1]-'1';
		return (x + y) % 2 != 0;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
