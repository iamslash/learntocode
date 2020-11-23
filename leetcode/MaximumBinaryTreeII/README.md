# Problem

[Maximum Binary Tree II](https://leetcode.com/problems/maximum-binary-tree-ii/)

# Idea

트리의 루트노드 `u` 와 숫자 `val` 이 주어진다. 모든 노드의 값은 그 노드의
서브트리 노드들 보다 크다. `val` 값을 갖는 노드를 삽입하고 트리의 루트노드를
구하는 문제이다.

트리의 밸런스를 유지할 필요는 없어 보인다. 규칙을 만들어서 구현을
수월하게 해보자. 여기서는 새로운 노드 `r` 을 생성하는 경우는 나머지
서브트리를 `r` 의 왼쪽 자식으로 저장한다. 노드를 생성하지 않고 탐색을
계속해야 하는 경우는 `r` 의 오른쪽 자식으로 탐색을 한다.

다음과 같은 몇가지 규칙을 고려하여 재귀적으로 해결한다.

* `u == NULL || u->val < val` 인 경우 노드를 하나 만들고 이것을 `r`
  이라고 하자. `r` 의 왼쪽 자식으로 `u` 를 저장한다. 그리고 `r` 을
  리턴한다.
* 그외의 경우는 `u` 의 오른쪽 자식으로 `insertIntoMaxTree(u->right,
  val)` 를 저장한다. 그리고 `u` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
