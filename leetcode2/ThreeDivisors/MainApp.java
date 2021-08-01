// Copyright (C) 2021 by iamslash

// 0ms 100.00% 35.7MB 87.50%
// brute force
class Solution {
	public boolean isThree(int n) {
		int divCnt = 2;
		for (int d = 2; d < n; ++d) {
			if (n % d == 0) {
				divCnt++;
			}
			if (divCnt > 3) {
				return false;
			}
		}
		return divCnt == 3;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
