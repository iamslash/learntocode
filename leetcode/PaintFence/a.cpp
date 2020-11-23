// 4ms 100.00% 8.2MB 55.17%
// Q. what is the range of n, k? int
// O(N) O(1)
class Solution {
 public:    
  int numWays(int n, int k) {        
    if (n == 0)
      return 0;
    if (n == 1)
      return k;
    // numWays(n,k) = numWaysDiff(n) + numWaySame(n)
    //              = numWays(n-1)*(k-1) + numWays(n-1)
    //              = (numWays(n-1,k) + numWays(n-2))*(k-1)
    int cntdiff = k*(k-1); // count of diff colors
    int cntsame = k; // count of same colors
    for (int i = 3; i <= n; ++i) {
      int prevcntdiff = cntdiff;
      cntdiff = (cntdiff + cntsame) * (k-1);
      cntsame = prevcntdiff;
    }
    return cntdiff + cntsame;     
  }
};