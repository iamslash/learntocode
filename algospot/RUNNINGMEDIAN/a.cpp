// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/NERDS2

#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

int N, A, B;

// 난수생성기
struct RNDM {
  int m_a;
  int m_b;
  int m_n;
  RNDM(int a, int b) : m_a(a), m_b(b), m_n(0) {}
  int next() {
    // Question : needs (long long)a ???
    return m_n = m_n == 0 ? 1983 : (m_n * (int64_t)m_a + m_b) % 20090711;
  }
};

// n을 추가하고 난 뒤 중간값을 리턴한다.
int solve() {
  int r = 0;
  RNDM rndm(A, B);
  std::priority_queue<int, std::vector<int>, std::less<int> > max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;

  for (int i = 0; i < N; ++i) {
    int n_rndm = rndm.next();
    // printf(" %d\n", n_rndm);
    // loop invariant 1 : max_heap의 크기는 min_heap의 크기보다 크거나 같다.
    if (max_heap.size() == min_heap.size())
      max_heap.push(n_rndm);
    else
      min_heap.push(n_rndm);
    // loop invariant 2 : max_heap.top()은 min_heap.top()보다 작거나 같다.
    if (!max_heap.empty() && !min_heap.empty() &&
        min_heap.top() > max_heap.top()) {
      int a = max_heap.top();
      int b = min_heap.top();
      max_heap.pop(); min_heap.pop();
      max_heap.push(b);
      min_heap.push(a);
    }

    r = (r + max_heap.top()) % 20090711;
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d %d %d", &N, &A, &B);
    printf("%d\n", solve());
  }
  //
  return 0;
}
