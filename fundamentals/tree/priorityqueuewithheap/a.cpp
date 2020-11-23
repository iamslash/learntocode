// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

// push to last and promote it
void push_heap(std::vector<int>& heap, int new_value) {
  heap.push_back(new_value);
  int idx = heap.size() - 1;
  while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
    int idx_parent = (idx - 1) / 2;
    std::swap(heap[idx], heap[idx_parent]);
    idx = idx_parent;
  }
}

// replace root with last node and place it
void pop_heap(std::vector<int>& heap) {
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
}

int main() {
  const int HEAP_SIZE = 10;
  std::vector<int> heap(HEAP_SIZE, 0);
  for (int i = 1; i < HEAP_SIZE; ++i) {
    push_heap(heap, i);
  }
  pop_heap(heap);
  pop_heap(heap);

  for (int i = 0; i < HEAP_SIZE; ++i) {
    printf("%d ", heap[i]);
  }
  printf("\n");

  return 0;
}
