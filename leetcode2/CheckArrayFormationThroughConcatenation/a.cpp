/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


//              i
//         A: 1,3,5,7
//    pieces: [2,4,6,8]
// piecesMap:        2
//            [2,4,6,8]
//      flat: 

// Rumtime Error
// [17,89,1,72,69,70,18,39,92,51,47,99,71,5,16,57,67,26,62,24,23,15,61,37,81,30,82,96,3,94,7,41,43,2,66,8]
// [[4,93],[3],[19],[87,62],[49],[54],[13,21],[82],[5],[73],[34],[28],[29],[27],[42],[45,67],[85,16],[58,31,37],[64],[81],[72,60],[59],[17],[6],[97],[1,92],[84]]
// hash map
// O(N) O(N)
class Solution {
 public:
  bool canFormArray(vector<int>& A, vector<vector<int>>& pieces) {
    unordered_map<int, vector<int>> pieceMap;
    for (auto& piece : pieces) {
      pieceMap[piece[0]] = piece;
    }
    vector<int> flat;
    for (int a : A) {
      if (pieceMap.count(a)) {
        flat.insert(flat.end(),
                    pieceMap[a].begin(),
                    pieceMap[a].end());
      }
    }
    if (flat.empty())
      return false;
    return equal(A.begin(), A.end(), flat.begin());
  }
};
