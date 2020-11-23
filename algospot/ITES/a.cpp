// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/ITES

#include <cstdio>
#include <queue>

int K, N;

class ASig {
 private:
  unsigned int m_n_id;
  unsigned int m_n_seq;
 public:
  ASig () : m_n_id(0), m_n_seq(1983) {}
  unsigned int GetID() { return m_n_id; }
  unsigned int Next() {
    if (m_n_id > 0) {
      m_n_seq = (m_n_seq * 214013 + 2531011) % 0x100000000;
      // m_n_seq = (m_n_seq * 214013 + 2531011) % 4294967296;      
    }
    m_n_id++;
    return m_n_seq % 10000 + 1;
  }
};

int Solve(int k, int n) {
  int r = 0;
  int psum = 0;
  ASig sig;
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    int next = sig.Next();
    q.push(next);
    psum += next;

    // pop until psum is less than k
    while (psum >= k) {
      if (psum == k)
        ++r;
      psum -= q.front();
      q.pop();
    }
  }
  
  return r;
}

int main() {

  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &K, &N);
    printf("%d\n", Solve(K, N));
  }

  // ASig asig;
  // for (int i = 0; i < 5; ++i)
  //   printf("%d ", asig.Next());
  // printf("\n");
  
  return 0;
}

