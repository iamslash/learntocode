# Problem

[Minimum Number of Operations to Sort a Binary Tree by Level](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/)

`TreeNode root` 가 주어진다. 각 level 의 노드들을 strictly increasing
order 로 정렬하라. 이때 임의의 두 node 를 얼마든지 교체할 수 있다.
모든 level 을 정렬했을 때 필요한 교체횟수를 구하라.

# Idea

다음과 같이 두가지 종류의 배열 `idxs[], vals[]` 이 있다고 하자.
`idxs[], vals[]` 를 `vals[]` 의 오름차순으로 정렬한다.

```
idxs: 0 1 2 3 4 
vals: 7 8 3 5 2
      
idxs: 4 2 3 0 1 
vals: 2 3 5 7 8
```

인덱스 `i` 를 기준으로 `idxs[i] == i` 가 될 때까지 `idxs[i]` 를
교체한다. 교체할 때 마다 답을 하나 증가한다.

```
      i
idxs: 4 2 3 0 1
      1 2 3 0 4
      2 1 3 0 4
      3 1 2 0 4
      0 1 2 3 4

        i
      0 1 2 3 4

          i
      0 1 2 3 4

            i
      0 1 2 3 4

              i
      0 1 2 3 4
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N^2lgN) O(N^2)
```
