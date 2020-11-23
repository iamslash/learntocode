# Problem

[Path In Zigzag Labelled Binary Tree](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)

# Idea

숫자 `lbl` 이 주어진다. `1` 부터 시작해서 `lbl` 를 leaf 로 하는 binary
tree 를 제작한다. 짝수 레벨마다 노드들의 순서를 뒤집는다.  `1` 부터
`lbl` 까지 경로를 구하는 문제이다.

예를 들어 다음과 같은 트리를 살펴보자.

```
           1
      /        \
     3          2
   /   \      /   \
  4     5     6    7
 / \   / \   / \  / \
15 14 13 12 11 10 9  8
```

* `14` 의 부모는 원래 `7 = 14/2` 이다. 그러나 `7` 이 속한 레벨의 모든 노드가
  뒤집혔을 때 `7` 의 위치에 오는 `4` 가 부모가 된다.
* `4` 의 부모는 원래 `2 = 4/2` 이다. 그러나 `2` 가 속한 레벨의 모든 노드가
  뒤집혔을 때 `2` 의 위치에 오는 `3` 이 부모가 된다.
* `3` 의 부모는 `1` 이다.

위의 사실을 살펴보면 다음과 같은 규칙을 발견할 수 있다.

* 현재 노드 `lbl` 이 속한 레벨의 모든 노드를 뒤집고 원래 `lbl` 의
  위치에 오는 `lbl` 를 2 로 나누면 부모의 `lbl` 을 얻을 수 있다.

즉, 다음과 같이 `lbl` 과 레벨 `lvl` 을 이용하여 부모의 `lbl` 을 얻을
수 있다.

```
lbl of parent = (2^(lvl-1) + (2^lvl - 1) - lbl) / 2
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
