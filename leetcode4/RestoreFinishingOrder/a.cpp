/* Copyright (C) 2025 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

// // hash set
// // O(N) O(N)
// class Solution {
// public:
//   vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
//     int n = friends.size();
//     unordered_set<int> friendSet;
//     vector<int> ans;
//     ans.reserve(n);

//     for (int friendID : friends) {
//       friendSet.insert(friendID);
//     }

//     for (int partID : order) {
//       if (friendSet.count(partID)) {
//         ans.push_back(partID);
//       }
//     }

//     return ans;
//   }
// };

// 0ms 100.00% 50.20MB 71.18%
// brute force
// O(N^2) O(N)
class Solution {
public:
  vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
    vector<int> ans;

    for (int partID : order) {
      if (count(friends.begin(), friends.end(), partID)) {
        ans.push_back(partID);
      }
    }

    return ans;
  }
};

int main() {
  return 0;
}
