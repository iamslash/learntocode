# Problem

[Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)

트리의 루트노드 `root` 와 숫자 `startValue, destValue` 가 주어진다.
`startValue` 를 갖는 노드에서 destValue 를 갖는 노드까지의 최단 경로를
구하라. `startValue` 에서 LCA 까지 하나의 노드경로는 `U` 로 나타낸다.
LCA 에서 `destValue` 까지 하나의 노드경로는 왼쪽 혹은 오른쪽에 따라
`L` 혹은 `R` 로 나타낸다.

# Idea

예를 들어 `root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6`
의 경우를 살펴보자.

```
     5
    / \
   1   2
  /   / \
 3   6   4

3 - 1 - 5 - 2 - 6
    U   U   R   L
```

따라서 답은 `UURL` 이다.

[DFS](/fundamentals/graph/dfs/README.md) 로 해결할 만 하다. 다음과 같이 두가지
방법이 있다.

첫번재 방법은 `startValue, destValue` 까지의 경로를 `srcPath, dstPath` 에 각각
저장한다. [DFS](/fundamentals/graph/dfs/README.md) 를 이용해야 하기 때문에
경로는 거꾸로 저장된다.

`srcPath, dstPath` 의 끝에서 부터 공통되는 부분을 제거한다.  공통되는 문자열의
개수를 `i` 라고 하자.  `srcPath.length() - i` 개수 만큼 `U` 를 만들어 답에
추가한다. `dstPath.reverse().substring(i)` 를 답에 추가한다.

두번째 방법은 [LCA](/leetcode/LowestCommonAncestorofaBinaryTree/README.md) 를 이용한다. [LCA](/leetcode/LowestCommonAncestorofaBinaryTree/README.md) 를 먼저 찾는다. LCA 부터 `startValue` 까지
DFS 하면서 답에 경로를 추가한다. LCA 부터 `destValue` 까지 DFS 하면서 답에
경로를 추가한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)
* [python3](a.py)

# Complexity

```
O(N) O(lgN)
```
