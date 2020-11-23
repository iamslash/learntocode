// Copyright (C) 2020 by iamslash

//                        i
//       A: 1 0 2 3 0 4 5 0
//       A:   0 0 2 3 0 0 4
// cntZero: 3               

//            i
//       A: 0 1 7 6 0 2 0 7
//        :     1 7 6 0 0 2
// cntZero: 1

// 1ms 90.99%
// backward traversal
// O(N) O(1)
class Solution {
	public void duplicateZeros(int[] A) {
		int cntZero = 0, n = A.length;
		for (int a : A) {
			if (a == 0)
				cntZero++;
		}
		for (int i = n-1; cntZero > 0 && i >= 0; --i) {
			// System.out.printf("i: %d, cntZero: %d\n", i, cntZero);
			if (i + cntZero < n)
				A[i + cntZero] = A[i];
			if (A[i] == 0) {
				cntZero--;
				if (i + cntZero < n)
					A[i + cntZero] = A[i];
			}
		}
	}
}
