# Problem

> [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/)

Complete binary tree `TreeNode root` 가 주어진다. node 의
개수를 구하라.

# Idea

모든 node 를 방문한다면 시간 복잡도는 `O(N)`, 공간 복잡도는 `O(lgN)` 이다. 

이것을 [Complete binary tree](/doc/tree.md) 의 특성을 참고하여 더욱 최적화해보자. 예를 들어
다음과 같은 경우를 살펴보자.

```
root: 
    1
   / \
  2   3
 / \  /
4  5 6
```

어떤 노드의 가장 왼쪽 자손들의 깊이를 `leftHeight` 라고 하자.\

이제 `1` 를 방문한다. `leftHeight(1) == 2` 이다.  `1` 의 오른쪽 자식은 `3` 이다.
또한 `leftHeight(3) == 1` 이다. `leftHeight(1) == leftHeight(3) + 1` 이다.
주어진 tree 는 Complete Binary Tree 이다. 따라서 `2` 를 root 로 하는 tree 는
[Perfect Binary Tree](/doc/tree.md) 이다. 그렇다면 `1` 의 왼쪽 자손들과 자신을 포함한 노드의 개수는
`1 << leftHeight(1)` 이다.  즉, 4 와 같다.

이번에는 다른 경우를 살펴보자.

```
root: 
           1
        /     \
       2       3
     /   \    / \   
    4     5  10 11
   / \   / \ 
  6   7 8   9 
```

다시 `1` 을 방문한다. `leftHeight(1) == 3` 이다. `1` 의 오른쪽 자식은 `3` 이다.
또한 `leftHeight(3) == 0` 이다. `leftHeight(1) != leftHeight(3) + 1` 이다. `3`
을 root 로 하는 tree 는 [Perfect Binary Tree](/doc/tree.md) 이다. 따라서 `1` 과 오른쪽 자손
노드들의 개수는 `1 << leftHeight(1) - 1` 이다. 즉, `1 << 2` 과 같다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(lgN)
```
