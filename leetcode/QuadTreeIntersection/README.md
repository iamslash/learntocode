# Problem

[Quad Tree Intersection](https://leetcode.com/problems/quad-tree-intersection/)

# Idea

두개의 쿼드트리의 루트노드 `u, v` 가 주어진다. `u` 와 `v` 의 logical OR 결과에 해당하는 새로운 쿼드트리를 구하는 문제이다.

예를 들어 다음과 같은 두개의 쿼드트리를 살펴보자. 모든 노드들의 한쪽이 leaf 인 경우에 해당한다. 다음과 같은 경우의 수를 생각해 볼 수 있다.

* A 의 top left 이 leaf 이고 `T` 이면 B 의 top left 은 상관없이 A 의 top left 을 리턴한다.
* A 의 top right 이 leaf 이고 `F` 이면 B 의 top left 의 결정을 따른다. B 의 top left 을 리턴한다.
* A 의 top left 이 leaf 이고 `T` 이면 B 의 top left 은 상관없이 A 의 top left 을 리턴한다.
* A 의 top right 이 leaf 이고 `F` 이면 B 의 top left 의 결정을 따른다. B 의 top left 을 리턴한다.
  
```
A:                 B:                 C (A or B):
+-------+-------+  +-------+---+---+  +-------+-------+
|       |       |  |       | F | F |  |       | F | F |
|   T   |   F   |  |   T   +---+---+  |   T   +---+---+
|       |       |  |       | T | T |  |       | T | T |
+-------+-------+  +-------+---+---+  +-------+-------+
|       |       |  |       |       |  |       |       |
|   F   |   F   |  |   T   |   F   |  |   T   |   F   |
|       |       |  |       |       |  |       |       |
+-------+-------+  +-------+-------+  +-------+-------+
```

예를 들어 다음과 같은 두개의 쿼드트리를 생각해 보자. 양쪽이 모두 leaf 가 아닌 경우를 포함한다. 다음과 같은 경우의 수를 생각해 볼 수 있다.

* A 의 top left 은 leaf 가 아니다. B 의 top left 은 leaf 가 아니다. 각각 자식들을 재귀적으로 따져본다. 그리고 결과에 해당하는 노드들을 `Node* tl, tr, bl, br` 에 저장한다. 새로운 노드 `u` 를 만들어서 `u->topLeft, u->topRight, u->bottomLeft, u->bottomRight` 에 `tl, tr, bl, br` 을 저장한다. 자식이 있기 때문에 `u->val = false, u->isLeaf = false` 이다.
* A 의 bottom left 은 leaf 가 아니다. B 의 bottom left 는 leaf 가 아니다. 그런데 A, B 각각의 자식들은 모두 같은 값을 갖는다. 새로운 노드 `u` 를 만들어서 `u->val = false, u->isLeaf = false` 를 저장한다. `u` 의 자식들은 굳이 필요없다.

```
A:                 B:                 C (A or B):
+-------+-------+  +-------+---+---+  +-------+-------+
| F | F |       |  | F | F | F | F |  | F | F | F | F |
+---+---+   F   |  +---+---+---+---+  +---+---+---+---+
| T | T |       |  | T | T | T | T |  | T | T | T | T |
+-------+-------+  +-------+---+---+  +-------+-------+
| F | F |       |  | F | F |       |  |       |       |
+---+---+   F   |  +---+---+   F   |  |   F   |   F   |
| F | F |       |  | F | F |       |  |       |       |
+-------+-------+  +-------+-------+  +-------+-------+
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
