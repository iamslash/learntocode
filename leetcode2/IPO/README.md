# Problem

[IPO](https://leetcode.com/problems/ipo/)

숫자 `k, W`, 수열 `P[], C[]` 가 주어진다.`P[i]` 는 `i` 프로젝트의
수익이다. `C[i]` 는 `i` 프로젝트를 수행할 때 필요한 자본이다. `W` 는
현재 가지고 있는 자본이다. 최대 `k` 만큼의 프로젝트를 수행할 수 있다.
가장 큰 수익을 냈을 때 그 수익을 찾는 문제이다.

# Idea

greedy algorithm 으로 해결할 만 하다.

`priority_queue<int> doableProfitQueue` 를 선언하고 `W` 로 가능한
프로젝트들의 수익을 저장한다. `doableProfitQueue.top()` 은 가장 큰
프로젝트의 수익이다. 가장 큰 수익을 찾는 문제 이기 때문에 수익만
저장해도 좋다.

`multiset<pair<int, int>> undoablePrjSet` 를 선언하고 `W` 로
불가능한 프로젝트들의 `{C[i], P[i]}` 를 저장한다. sorted set 이기 때문에
`{C[i], P[i]}` 의 오름차순으로 저장된다.

`while (k-- > 0 && doableProfitQueue.size() > 0)` 동안 다음을 반복한다.

* `doableProfitQueue` 에서 수익을 하나 꺼내어 `W` 에 더한다. 이제 `W`
  는 증가했다.
* `undoablePrjSet` 을 처음부터 순회하면서 비용이 `W` 보다 작은 것의 프로젝트 수익을
  `doableProfitQueue` 애 삽입한다. 
  
모든 반복을 마치면 `W` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(PlgP) O(P)
```
