
// Find nCr for given n and r.

// Input:
// First line contains no of test cases T, for every test case 2
// integers as inputs (n,r).


// Output:
// Compute and print the value in seperate line. Modulus your output
// to 10^9+7. If n


// Constraints:
// 1<=T<=50
// 1<=n<=1000
// 1<=r<=800


// Example:
// Input:
// 1
// 3 2

// Output:
// 3

// in every line first value is always 0 + 1 pattern
// C[1] = C[1] + C[0] = 0 + 1 = 1
//   C[2] = C[2] + C[1] = 0 + 1 = 1
//   C[1] = C[1] + C[0] = 1 + 1 = 2
//     C[3] = C[3] + C[2] = 0 + 1 = 1
//     C[2] = C[2] + C[1] = 2 + 1 = 3
//     C[1] = C[1] + C[0] = 2 + 1 = 3
// pascal triangle
int nCr_dp(int n, int r, int p) {
  int C[r+1] = {0,};
  C[0] = 1; // top row of pascal triangle
  for (int i = 1; i <= n; ++i) {
    for (int j = std::min(i, r); j > 0; --j) {
      // nCj = (n-1)Cj + (n-1)C(j-1)
      C[j] = (C[j] + C[j-1]) % p;
    }
  }
  return C[r];
}
