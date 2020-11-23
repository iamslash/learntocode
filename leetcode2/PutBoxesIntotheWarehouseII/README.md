# Problem

[Put Boxes Into the Warehouse II](https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/)

박스 높이의 모음 `B[]`, 창고 높이의 모음 `W[]` 가 주어진다.  박스를
창고의 왼쪽 혹은 오른쪽으로 삽인한다.  박스의 순서는 조정할 수 있다.
최대로 배치할 수 있는 박스의 개수를 구하라.

# Idea

먼저 박스를 내림 차순으로 정렬한다. 그리고 인덱스 `k` 로
순회한다. 창고의 왼쪽과 오른쪽에서 시작할 인덱스 `i, j` 를 선언한다.

`B[i]` 를 `W[i]` 혹은 `W[j]` 에 배치해 본다. 배치가 된다면 `i++` 혹은
`j--` 와 `k++` 를 수행한다. 배치할 수 없다면 `k++` 만 수행한다.

# Implementation

* [golang](a.go)

# Complexity

```
O(NlgN) O(1)
```
