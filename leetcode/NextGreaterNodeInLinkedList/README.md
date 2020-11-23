# Problem

[Next Greater Node In Linked List](https://leetcode.com/problems/next-greater-node-in-linked-list/)

# Idea

링크드 리스트의 헤드 `h` 가 주어진다. 링크드 리스트의 노드를 첫번 째
부터 `node_1, node_2, ...` 라고 해보자.  `next_larger(node_i)` 는
`node_i` 의 오른쪽의 노드들 중 `node_i->val` 보다 큰 값을 가진 것들 중
가장 작은 값을 리턴한다고 해보자. 링크드 리스트의 모든 노드들을
순회하면서 `next_larger(node_i)` 의 모음을 구하는 문제이다.

[Daily Temperatures @
leetcode](https://leetcode.com/problems/daily-temperatures/) 와 비슷한
문제이다. 먼저 링크드 리스트를 벡터 `vector<int> ans` 에 담는다.  스택
`stck<int> stck` 를 선언하여 가장 높은 값을 저장한다.

이제 `ans` 를 인덱스 `i` 로 거꾸로 순회하면서 다음을 반복한다.

* `stck.size() && stck.top() <= ans[i]` 인 동안 `stck.pop()` 을
  수행한다.
* `stck.empty()` 이면 `ans[i] = 0` 을 수행하고 그렇지 않으면 `ans[i] =
  stck.top()` 를 수행한다.
* `stck.push(ans[i])` 를 수행한다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
