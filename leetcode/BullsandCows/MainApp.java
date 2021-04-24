// Copyright (C) 2021 by iamslash

import java.util.*;

// 10ms 24.63% 38.9MB 69.38%
// hash map
// O(N) O(1)
class Solution {
	public String getHint(String secret, String guess) {
		int cntBulls = 0, cntCows = 0, n = secret.length();
		int[] secretWrongs = new int[10];
		int[] guessWrongs = new int[10];
		for (int i = 0; i < n; ++i) {
			char c = secret.charAt(i);
			char d = guess.charAt(i);
			if (c == d) {
				cntBulls++;
			} else {
				secretWrongs[c - '0']++;
				guessWrongs[d - '0']++;
			}
		}
		for (int i = 0; i < 10; ++i) {
			cntCows += Math.min(secretWrongs[i], guessWrongs[i]);
		}		
		return String.format("%dA%dB", cntBulls, cntCows);
	}
}

//                 i
//   secret: 1 1 2 3
//    guess: 0 1 1 1
//   wrongs:-1-1 1 1 0 0 0 0 0 0
// cntBulls: 1 
//  cntCows: 1

// 10ms 24.63% 38.8MB 79.88%
// hash map
// O(N) O(1)
class Solution {
	public String getHint(String secret, String guess) {
		int cntBulls = 0, cntCows = 0, n = secret.length();
		int[] wrongs = new int[10];
		for (int i = 0; i < n; ++i) {
			char c = secret.charAt(i);
			char d = guess.charAt(i);
			if (c == d) {
				cntBulls++;
			} else {
				if (wrongs[c-'0']++ < 0) {
					cntCows++;
				}
				if (wrongs[d-'0']-- > 0) {
					cntCows++;
				}
			}
		}		
		return String.format("%dA%dB", cntBulls, cntCows);
	}
}

// 1ms 100.00% 37.7MB 95.24%
// hash map
// O(N) O(1)
class Solution {
	public String getHint(String secret, String guess) {
		int cntBulls = 0, cntCows = 0, n = secret.length();
		int[] wrongs = new int[10];
		for (int i = 0; i < n; ++i) {
			char c = secret.charAt(i);
			char d = guess.charAt(i);
			if (c == d) {
				cntBulls++;
			} else {
				if (wrongs[c-'0']++ < 0) {
					cntCows++;
				}
				if (wrongs[d-'0']-- > 0) {
					cntCows++;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(cntBulls)
				.append('A')
				.append(cntCows)
				.append('B');
		return sb.toString();
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
