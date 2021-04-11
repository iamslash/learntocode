// Copyright (C) 2021 by iamslash

import java.util.*;

// k: 2
//
//    b x   x   
// n: 1 2 3 4 5
//    i
//
// k: 5
// n: 0 1 2 3 4 5
//          x 

// 3ms 33.33% 36.1MB 33.33%
// Linked List
// O(N) O(N)
class Solution {
	public int findTheWinner(int n, int k) {
		LinkedList<Integer> numList = new LinkedList<>();
		for (int i = 0; i < n; ++i) {
			numList.add(i+1);
		}
		int idx = 0;
		while (numList.size() > 1) {
			idx = idx + k - 1;
			while (idx >= numList.size()) {
				idx -= numList.size();
			}
			numList.remove(idx);
		}
		return numList.getFirst();
	}
}

// 0ms 100.00% 35.7MB 100.00%
// math
// O(N) O(1)
class Solution {
	public int findTheWinner(int n, int k) {
		int idx = 0;
		for (int i = 1; i <= n; ++i) {
			idx = (idx + k) % i;
		}
		return idx + 1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
