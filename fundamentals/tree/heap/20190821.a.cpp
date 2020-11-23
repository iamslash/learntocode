// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <algorithm>

class Heap {
 public:
  std::vector<int> heap;
  // push to last and traverse it to root until find a right place
  void Push(int a) {
    heap.push_back(a);
    int idx = heap.size() - 1;
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
      std::swap(heap[idx], heap[(idx - 1) / 2]);
      idx = (idx - 1) / 2;
    }
  }
  // return root and place last in root
  // and traverse it to leaf until find a right place
  int Pop() {
    int r = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    while (true) {
      int left = here * 2 + 1;
      int right = here * 2 + 2;
      if (left >= heap.size())
        break;
      int next = here;
      if (heap[next] < heap[left])
        next = left;
      if (right < heap.size() && heap[next] < heap[right])
        next = right;
      if (next == here)
        break;
      std::swap(heap[here], heap[next]);
      here = next;
    }
    return r;
  }
};

int main() {
  Heap heap;
  heap.Push(8);
  heap.Push(8);
  heap.Push(7);
  heap.Push(6);
  heap.Push(6);
  heap.Push(6);
  heap.Push(6);
  heap.Push(6);
  heap.Push(5);

  printf("%d\n", heap.Pop());
  
  return 0;
}
