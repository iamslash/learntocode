// Copyright (C) 2025 by iamslash

// Idea: brute force
//
// i is independent from j, k
// S(n) = Σ(i=0 to n-1) Σ(j=0 to n-1) Σ(k=0 to n-1) [ i * (j OR k) ]
//      = (Σ(i=0 to n-1) i) × (Σ(j=0 to n-1) Σ(k=0 to n-1) [j OR k]).
//
// When n is incremented by 1
//
// sum of new row elements which have same column index, n - 1:
// for (int j = 0; j < n - 1; ++j) {
//     sumJK += (n - 1) | j;
// }
//
// sum of new column elements which have same row index, n - 1:
// for (int j = 0; j < n - 1; ++j) {
//     sumJK += (n - 1) | j;
// }
//
// new edge elements which have same row, column index, n - 1:
// sumJK += n - 1

// 8ms 60.00% 40.88MB 60.00%
// brute force
// O(N^2) O(1)
class Solution {
    public int maxSizedArray(long s) {
        long sumI = 0, sumJK = 0;
        int n = 0;

        while (++n > 0) {
            
            sumI += n - 1;

            // new row, column elements
            for (int j = 0; j < n - 1; ++j) {
                sumJK += ((n - 1) | j) * 2;
            }

            // new edge element
            sumJK += n - 1;

            if (sumI * sumJK > s) {
                return n - 1;
            }
        }
        
        return 0;
    }
}
