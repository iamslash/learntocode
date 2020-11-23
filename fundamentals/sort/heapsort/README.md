# Problem

수열 `V` 가 주어지면 heap sort 를
이용하여 정렬하자.

# Idea

1. max heap 을 생성한다. max heap 은 complete
   binary tree 이기 때문에 부모 노드가 `i` 라면 왼쪽 자식노드는
   `2i+1` 이고 오른쪽 자식노드는 `2i+2` 이다.
2. 가장 큰 수를 가장 마지막 수와 교체한다.
3. max heap 을 구성한다.
4. 2, 3 을 반복한다.

다음은 수열 `V = 8 4 7 1 3 5` 을 heap sort 하는 과정이다.

먼저 다음과 같이 `maxlv - 1` 레벨의 마지막 노드부터 루트노드까지
순회하면서 maxheap 을 구성한다.

```
  for (int i = n / 2 - 1; i >= 0; --i) {
    percdown(V, i, n);
  }
```

그리고 heap 의 마지막 노드부터 루트노드의 왼쪽 자식 노드까지 순회하면서
가장 큰 수를 마지막 수와 교체하고 max heap 을 구성한다.

```
V: 8 4 7 1 3 5    7 4 5 1 3 8    5 4 3 1 7 8    4 1 3 5 7 8

      8                7              5              4
    /   \            /   \          /   \          /   \
   4     7          4     5        4     3        1     3
  / \   /          / \            / 
 1   3 5          1   3          1   

V: 3 1 4 5 7 8    1 3 4 5 7 8

      3                1
    /
   1
```
   
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
