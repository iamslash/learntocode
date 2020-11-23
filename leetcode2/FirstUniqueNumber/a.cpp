/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>

using namespace std;

// // 1164ms 5.43% 135.1MB 31.50%
// // list, hash table
// // ShowFirstUnique: O(1)
// //             add: O(1)
// class FirstUnique {
//  private:
//   list<int> uniqs;
//   unordered_map<int, list<int>::iterator> pointers;
//  public:
//   FirstUnique(vector<int>& A) {
//     for (int a : A)
//       add(a);
//   }
    
//   int showFirstUnique() {
//     if (uniqs.empty())
//       return -1;
//     return uniqs.front();
//   }
    
//   void add(int val) {
//     if (pointers.count(val) == 0) {
//       pointers[val] = uniqs.insert(uniqs.end(), val);
//     } else {
//       if (pointers[val] != uniqs.end()) {
//         uniqs.erase(pointers[val]);
//         pointers[val] = uniqs.end();
//       }
//     }
//   }
// };

// 1216ms 5.43% 120.1MB 89.38%
// list, hash table
// ShowFirstUnique: O(1)
//             add: O(1)
class FirstUnique {
 private:
  queue<int> q;
  unordered_map<int, int> cnts;
 public:
  FirstUnique(vector<int>& A) {
    for (int a : A)
      add(a);
  }
    
  int showFirstUnique() {
    while (!q.empty()) {
      if (cnts[q.front()] > 1)
        q.pop();
      else 
        break;
    }
    return q.empty() ? -1 : q.front();    
  }
    
  void add(int val) {
    if (++cnts[val] == 1) {
      q.push(val);
    }
  }
};
