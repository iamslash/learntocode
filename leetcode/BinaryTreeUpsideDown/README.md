# Problem

* [Binary Tree Upside Down](https://leetcode.com/problems/binary-tree-upside-down/)

# Idea

다음과 같이 트리가 뒤집혀야 한다.

```
    1                   4
   / \                 / \
  2   3     =>        5   2
 / \                     / \
4   5                   3   1
```

위의 트리에서 다음과 같이 3 개의 원소를 갖는 트리를 살펴보자.

```
  2                    4
 / \        =>        / \
4   5                5   2
```

시계방향으로 회전했음을 알 수 있다. 앞서 언급한 트리에서 두가지 서브트리 `2, 4, 5` 와 `1, 2, 3` 를
살펴보자. 각각 회전하고 서브트들이 시계방향으로 회전했음을 알 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
