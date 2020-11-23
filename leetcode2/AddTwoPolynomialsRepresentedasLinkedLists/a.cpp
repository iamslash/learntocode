/* Copyright (C) 2020 by iamslash */

#include <cstdio>

using namespace std;

//       a
// a: 2x^2  4x  3
// b: 3x^2 -4x -1
//       b

// 208ms 100.00% 43.9MB 100.00%
// hash map, linked list
// O(NlgN) O(N)
class Solution {
 public:
  PolyNode* addPoly(PolyNode* a, PolyNode* b) {
    map<int, int> polyMap;
    while (a) {
      int pow = a->power;
      int cof = a->coefficient;
      polyMap[pow] += cof;
      a = a->next;
    }
    while (b) {
      int pow = b->power;
      int cof = b->coefficient;
      polyMap[pow] += cof;
      b = b->next;
    }
    PolyNode head;
    PolyNode* p = &head;
    for (auto it = polyMap.rbegin(); it != polyMap.rend(); ++it) {
      int cof = it->second;
      int pow = it->first;
      if (cof == 0)
        continue;
      p->next = new PolyNode(cof, pow);
      p = p->next;
    }
    return head.next;
  }
};
