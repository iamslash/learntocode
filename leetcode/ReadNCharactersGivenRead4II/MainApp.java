// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 37.8MB 13.07%
// brute force
// O(N) O(1)
public class Solution extends Reader4 {
	private char[] buf4 = new char[4];
	private int idx4 = 0;
	private int cnt4 = 0;
	public int read(char[] buf, int n) {
		int nread = 0;
		while (nread < n) {
			// Consume buf4
			if (idx4 == cnt4) {
				cnt4 = read4(buf4);
				idx4 = 0;
				if (cnt4 == 0) {
					break;
				}
			}
			// Update buf
			buf[nread++] = buf4[idx4++];
		}
		return nread;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
