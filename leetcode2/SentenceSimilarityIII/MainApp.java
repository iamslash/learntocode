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

// two pointers
// O(N) O(1)
class Solution {
	private boolean compare(String[] A, String[] B) {
		int s1 = 0, e1 = A.length-1;
		int s2 = 0, e2 = B.length-1;
		while (s1 < e1 && A[s1] == B[s2]) {
			s1++;
			s2++;
		}
		while (s1 < e1 && A[e1] == B[e2]) {
			e1--;
			e2--;
		}
		return s2 > e2;
	}
	public boolean areSentencesSimilar(String a, String b) {
		String[] A = a.split(" ");
		String[] B = b.split(" ");		
		return A.length > B.length ? compare(A, B) : compare(B, A);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
