// Copyright (C) 2021 by iamslash

import java.util.*;

// A: 1 2 3 4
//      s
// B: 1 4
//    e
//
// A:   1 2 3 4
//      s
// B:   3 4
//     e
//
// A: 1 2 3 4
//           s
// B: 1 2 3 4 
//          e

// 1ms 97.51% 37.1MB 86.31%
// two pointers
// O(N) O(1)
class Solution {
	private boolean compare(String[] A, String[] B) {
		int s1 = 0, e1 = A.length-1;
		int s2 = 0, e2 = B.length-1;
		while (s1 < A.length && s2 < B.length && A[s1].equals(B[s2])) {
			s1++;
			s2++;
		}
		while (e1 >= 0 && e2 >= 0 && A[e1].equals(B[e2])) {
			e1--;
			e2--;
		}
    // System.out.printf("s1:%d, e1:%d, s2:%d, e2:%d\n,", s1, e1, s2, e2);
		return s2 > e2;
	}
	public boolean areSentencesSimilar(String a, String b) {
		String[] A = a.split(" ");
		String[] B = b.split(" ");
    // System.out.printf("A:%d, B:%d\n,", A.length, B.length);
		return A.length > B.length ? compare(A, B) : compare(B, A);
	}
}

public class MainApp {
  public static void main(String[] args) {
		Solution sln = new Solution();
		// true
		System.out.println(sln.areSentencesSimilar("Ogn WtWj HneS","Ogn WtWj HneS"));
		// true
		System.out.println(sln.areSentencesSimilar("Ogn WtWj HneS","Ogn"));
  }
}
