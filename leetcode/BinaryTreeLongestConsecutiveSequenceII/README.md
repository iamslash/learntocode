# Problem

[Binary Tree Longest Consecutive Sequence II](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/)

# Idea

Binary Tree 의 루트노드 `u` 가 주어진다. 연속된 값을 갖는 서브트리의
최대 개수를 구하는 문제이다.

예를 들어 이진트리가 다음과 같을 때 연속된 값을 갖는 서브트리는 
`2, 1` 혹은 `1, 2` 이므로 답은 `2` 이다.

```
   1
  / \
 2   3  
```

다음과 같은 부분문제를 정의하고 재귀적으로 해결해보자.

```cpp
vector<int, int> dfs(TreeNode* u);
return: (increment count from child to u, decrement count from child to u)
```

한편 `l = dfs(u->left)` 를 수행하고 `r = dfs(u->right)` 를 할 때
한가지 주의할 점이 있다. 왼쪽 자손들과 연속이고 오른쪽 자손들과 연속이 아닌 경우를
고려해야 하기 때문에 `dec = max(l[1], r[1]), inc = max(l[0],
r[0])` 를 수행해야 한다.

다음은 recursion tree 이다.

```
          1
        (1, 3)
        /   \
      2       4
   (1, 2)    (1, 1)   
    /
   3
(1, 1)
```

# Implementation

* [c++11](a.cpp)

# Complextiy

```
O(N) O(N)
```
