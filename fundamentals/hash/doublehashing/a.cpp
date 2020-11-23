// Copyright (C) 2019 by iamslash

#include <cstdio>
#include <vector>

#define TABLE_SIZE 13
#define PRIME 7

class DoubleHash {
 private:
  std::vector<int> m_hash;
  int m_used;
  int hash1(int key) {
    return key % m_hash.size();
  }
  int hash2(int key) {
    return (PRIME - (key % PRIME));
  }
 public:
  DoubleHash() {
    m_hash = std::vector<int>(TABLE_SIZE, -1);
    m_used = 0;   
  }
  bool isFull() {
    return m_used == m_hash.size();
  }
  void insert(int key, int val) {
    if (isFull())
      return;
    int idx = hash1(key);
    if (m_hash[idx] == -1) {
      m_hash[idx] = val;
    } else {
      int idx2 = hash2(key);
      int i = 1;
      while (true) {
        int nidx = (idx + i * idx2) % m_hash.size();
        if (m_hash[nidx] == -1) {
          m_hash[nidx] = val;
          break;
        }
        ++i;
      }
    }
    m_used++;
  }
  void display() {
    for (int a : m_hash)
      printf("%d ", a);
    printf("\n");
  }
};

int main() {
  std::vector<int> V = {19, 27, 36, 10, 64};
  int n = V.size();

  DoubleHash dh;
  for (int i = 0; i < n; ++i)
    dh.insert(V[i], V[i]);
  dh.display();
  
  return 0;
}

