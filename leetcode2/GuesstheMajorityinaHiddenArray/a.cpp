/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//       i
//    A: 0 0 1 0 1 1 1 1
//    a: 2
//    e: 0
//    b: 0
//    c: 2
//    d: 0 
// cnts: 1 2 2 1 2
//               i
// cnt1: 2
//  id1: 3
// cnt2: 3
//  id2: 4
//
// last: 0
//

// // too difficult
// // 332ms 28.47% 31.6MB 36.50%
// class Solution {
//  public:
//   int guessMajority(ArrayReader &reader) {
//     int n = reader.length();
//     vector<int> cnts(n);
//     cnts[0] = 1;
//     int a = reader.query(0, 1, 2, 3);
//     int e = reader.query(1, 2, 3, 4);
//     cnts[4] = a == e ? 1 : 2;
//     int b = reader.query(0, 2, 3, 4);
//     cnts[1] = b == e ? 1 : 2;
//     int c = reader.query(0, 1, 3, 4);
//     cnts[2] = b == c ? cnts[1] : 3 - cnts[1];
//     int d = reader.query(0, 1, 2, 4);
//     cnts[3] = c == d ? cnts[2] : 3 - cnts[2];
//     int cnt1 = 0, cnt2 = 0;
//     int id1 = -1, id2 = -1;
//     int ans = -1;
//     for (int i = 0; i < 5; ++i) {
//       if (cnts[i] == 1) {
//         cnt1++;
//         id1 = i;
//       } else {
//         cnt2++;
//         id2 = i;
//       }
//     }
//     int last = e;
//     for (int i = 5; i < n; ++i) {
//       int cur = reader.query(i-3, i-2, i-1, i);
//       cnts[i] = cur == last ? cnts[i-4] : (3 - cnts[i-4]);
//       last = cur;
//       if (cnts[i] == 1) {
//         cnt1++;
//         id1 = i;
//       } else {
//         cnt2++;
//         id2 = i;
//       }
//     }
//     if (cnt1 == cnt2)
//       return -1;
//     return cnt1 > cnt2 ? id1 : id2;
//   }
// };

// too difficult
// 116ms 100.00% 20.8MB 97.81%
class Solution {
 public:
  int guessMajority(ArrayReader &reader) {
    vector<int> a, q;
    int has4 = false, has2 = false, sz = reader.length(), cnt = 0, b = 0;
    for (int i = 0; i < 5; ++i) {
      q.push_back(reader.query(i == 0 ? 1 : 0, i <= 1 ? 2 : 1, 
                           i <= 2 ? 3 : 2, i <= 3 ? 4 : 3));
      has4 |= q.back() == 4;
      has2 |= q.back() == 2;
    }
    for (auto i = 0; i < q.size(); ++i)
      if (q[i] == (has4 ? (has2 ? 2 : 4) : 0)) {
        ++cnt;
        a.push_back(i);
      }
      else
        b = i;
    for (auto i = 5; i < sz - 1; i += 2) {
      auto res = reader.query(a[0], a[1], i , i + 1);
      cnt += res / 2;
      if (res == 0)
        b = i;
    }
    if (sz % 2 == 0)
      cnt += reader.query(a[0], a[1], a[2] , sz - 1) / 4;
    return cnt == (sz - cnt)  ? -1 : cnt > (sz - cnt) ? a[0] : b;
  }
};
