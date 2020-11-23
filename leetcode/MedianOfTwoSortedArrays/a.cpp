// Copyright (C) 2017 by iamslash
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// http://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/

// There are two sorted arrays nums1 and nums2 of size m and n
// respectively.

// Find the median of the two sorted arrays. The overall run time
// complexity should be O(log (m+n)).

// Example 1:
// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0

// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5



// 1 3 5 7 9
// 2 4 8
// k = 6

// 2 4 8
// 5 7 9
// k = 4

// 2 4 8
// 5 7 9
// k = 4

// 4 8
// 5 7 9
// k = 3

// 5 7 9
// 8
// k = 2

// 7 9
// 8
// k = 1

// 8
// 9
// k = 0

#include <cstdio>
#include <vector>
#include <limits>

// 1
// 2 3 4 5 6 7 8 9
//
// left M | right M
// left N | right N
//
// m: 1, n: 4
//
// l     : 0     1
// h     : 1     1
// pm    : 0     1
// pn    : 5     4
// maxlm : min() 1
// minrm : 1     max()
// maxln : 7     5
// minrn : 6     6
class Solution {
 public: 
  double findMedianSortedArrays(std::vector<int>& M, std::vector<int>& N) {
    if (M.size() > N.size())
      return findMedianSortedArrays(N, M);
    int m = M.size();
    int n = N.size();
    int l = 0;
    int h = m;
    while (l <= h) {
      int pm = (l+h)/2; // partition for M
      int pn = (m+n+1)/2 - pm; // partition for M

      int maxlm = (pm == 0) ? std::numeric_limits<int>::min() : M[pm-1]; // max left M
      int minrm = (pm == m) ? std::numeric_limits<int>::max() : M[pm];   // min right M
      int maxln = (pn == 0) ? std::numeric_limits<int>::min() : N[pn-1]; // max left M
      int minrn = (pn == n) ? std::numeric_limits<int>::max() : N[pn];   // min right M

      if (maxlm <= minrn && maxln <= minrm) {
        double rslt = (double)std::max(maxlm, maxln);
        if ((m+n)%2 == 0)
          rslt = (rslt + (double)std::min(minrm, minrn)) / 2.0;
        return rslt;
      } else if (maxlm > minrn) {
        h = pm - 1;
      } else {
        l = pm + 1;
      }
    }
  }
};

int main() {
  Solution s;
  // std::vector<int> M = {1, 3};
  // std::vector<int> N = {2};
  std::vector<int> M = {1, 2};
  std::vector<int> N = {3, 4};
  printf("%lf\n", s.findMedianSortedArrays(M, N));
  // printf("%lf\n", s._kth(M, 0, N, N.size(), 1));
}
