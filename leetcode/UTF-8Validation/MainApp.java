// Copyright (C) 2021 by iamslash

import java.util.*;

// i
// 0 1 2 3

// 1ms 98.52% 39.9MB 32.91%
// linear traversal
// O(N) O(1)
class Solution {
	public boolean validUtf8(int[] D) {
		int i = 0, n = D.length;		
		while (i < n) {
			if ((i+4 <= n) &&
					(D[i]>>3) == 0x1E &&
					(D[i+1]>>6) == 0x02 &&
					(D[i+2]>>6) == 0x02 &&
					(D[i+3]>>6) == 0x02) {
				i += 4;
			} else if ((i+3 <= n) &&
								 (D[i] >> 4) == 0x0E &&
								 (D[i+1] >> 6) == 0x02 &&
								 (D[i+2] >> 6) == 0x02) {
				i += 3;
			} else if ((i+2 <= n) &&
								 (D[i] >> 5) == 0x06 &&
								 (D[i+1] >> 6) == 0x02) {
				i += 2;
			} else if ((D[i] >> 7) == 0x00) {
				i++;
			} else {
				return false;
			}
		}
		return true;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
