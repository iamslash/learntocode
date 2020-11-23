/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// // 20ms 38.60% 11.5MB 14.15%
// // O(N) O(N)
// class Solution {
//  public:
//   int minMeetingRooms(std::vector<Interval>& V) {
//     std::map<int, int> smp;
//     for (auto& i : V) {
//       smp[i.start]++;
//       smp[i.end]--;
//     }
//     int maxs = 0;
//     int sums = 0;
//     for (auto& pr : smp) {
//       sums += pr.second;
//       maxs = std::max(maxs, sums);
//     }
//     return maxs;
//   }
// };

// 12ms 99.60% 9.9MB 89.80%
// O(NlgN) O(N)
class Solution {
 public:
  int minMeetingRooms(std::vector<Interval>& V) {
    if (V.empty())
      return 0;
    std::sort(V.begin(), V.end(), [](const Interval& a,
                                     const Interval& b) {
                return a.start < b.start;
              });
    std::vector<int> rooms;
    for (int i = 0; i < V.size(); ++i) {
      bool bfind = false;
      for (int j = 0; j < rooms.size(); ++j) {
        if (rooms[j] <= V[i].start) {
          rooms[j] = V[i].end;
          bfind = true;
          break;
        }
      }
      if (!bfind)
        rooms.push_back(V[i].end);
    }
    return rooms.size();
  }
};

int main() {

  // std::vector<Interval> V = {{0, 30}, {5, 10}, {15, 20}};
  std::vector<Interval> V = {{7, 10}, {2, 4}};
  Solution sln;
  printf("%d\n", sln.minMeetingRooms(V));
  return 0;
}
