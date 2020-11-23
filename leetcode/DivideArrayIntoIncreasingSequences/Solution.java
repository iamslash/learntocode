// 5ms 74.03% 56.4MB 100.00%
// brute force
// O(N) O(1)
class Solution {
  public boolean canDivideIntoSubsequences(int[] A, int K) {
    int n = A.length, d = 1, l = 1;
    for (int i = 1; i < n; ++i) {
      if (A[i-1] == A[i])
        ++l;
      else
        l = 1;
      d = Math.max(d, l);
    }
    return n >= d * K;
  }
}
