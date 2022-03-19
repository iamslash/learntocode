/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// 72ms 93.97% 24.2MB 59.05%
// heap
// O(NlgN) O(N)
class Solution {
public:
  int connectSticks(vector<int>& sticks) {
    priority_queue<int> pq;
    for (int len : sticks) {
      pq.push(-len);
    }
    int ans = 0;
    while (pq.size() > 1) {
      int sum = -pq.top(); pq.pop();
      sum += -pq.top(); pq.pop();
      ans += sum;
      pq.push(-sum);
    }
    return ans;
  }
};

// 155ms 17.51% 24.1MB 59.05%
// heap
// O(NlgN) O(N)
class Solution {
public:
  int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int len : sticks) {
      pq.push(len);
    }
    int ans = 0;
    while (pq.size() > 1) {
      int sum = pq.top(); pq.pop();
      sum += pq.top(); pq.pop();
      ans += sum;
      pq.push(sum);
    }
    return ans;
  }
};

// 80ms 84.34% 24.3MB 21.89%
struct Comparator {
  bool operator() (int a, int b) {
    return a > b;
  }
};
class Solution {
public:
  int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, Comparator> pq;
    for (int len : sticks) {
      pq.push(len);
    }
    int ans = 0;
    while (pq.size() > 1) {
      int sum = pq.top(); pq.pop();
      sum += pq.top(); pq.pop();
      ans += sum;
      pq.push(sum);
    }
    return ans;
  }
};

int main() {
  return 0;
}
