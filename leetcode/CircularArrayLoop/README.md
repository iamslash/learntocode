# Problem

* [Circular Array Loop](https://leetcode.com/problems/circular-array-loop/)

# References

* [Linked List 루프찾기 @ youtube](https://www.youtube.com/watch?v=AWWxMl9-8CY)
* [FindTheDuplicateNumber @ learntocode](https://github.com/iamslash/learntocode/tree/master/leetcode/FindTheDuplicateNumber/README.md)

# Idea

수열 `V[]` 가 주어진다. 임의의 `V[i]` 에서 `i + V[i]` 로 움직였을 때
루프가 존재하는지 검증하는 문제이다. 루프에 포함된 노드수는 반드시 2 개 이상이어야 한다. 또한 루프의 방향은 한 방향이어야 한다.

floyd's tortoise and hair algorithm 으로도 해결할 수 있지만 memoization 으로 더욱 쉽게 해결할 수 있다.

`vector<bool> seen` 을 선언하여 `i` 를 방문했는지 여부를 저장한다.

인덱스 `i` 를 이용하여 `V[]` 를 순회하면서 다음을 반복한다.

0. `seen[i] == true` 이면 이미 방문했으니 건너뛴다.
1. 방문했으니 `seen[i] = true` 수행한다.
2. `unordered_set<int> ust` 를 선언하여 싸이클을 검증한다.
3. `cur = i` 수행하고 다음을 반복한다.
  0. `nxt = (cur + V[cur] % n + n) % n` 수행한다.
  1. `nxt == cur` 이면 single element loop 이다. 반복을 종료한다.
  2. `V[nxt] * V[cur] < 0` 이면 한 방향이 아니다. 반복을 종료한다.
  3. `ust.count(nxt) == true` 이면 답을 찾은 것이다. 모든 방복을 종료한다.
  4. `ust.insert(cur), cur = nxt, seen[nxt] = true` 를 수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```