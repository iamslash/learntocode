# Problem

[Maximum Side Length of a Square with Sum Less than or Equal to Threshold](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

# Idea

2D 숫자의 모음 `M[][]`, 임계값 `T` 가 주어진다. `M` 에서 많은
정사각형을 찾을 수 있다. 넓이의 합이 최대가 되는 정사각형을 찾았을 때
그 변의 길이를 구하는 문제이다.

`gs[][]` 를 선언하여 [grid sum](/fundamentals/partialsum/gridsum/README.md) 를 저장한다.
`int len = 1` 를 선언한다. 한 변의 길이가 `len` 인 정사각형을 찾을 때마다 `len` 을 하나씩 증가한다.
`M[][]` 을 index `y, x` 로 순회하면서 `gs` 를 채우고 `len` 을 업데이트한다.
모든 반복을 마치면 `len` 이 답이다.

```
M
1 1 2 
1 1 2 
1 1 2 

gs
0 0 0 0 
0 1 2 4
0 2 4 8 
0 3 6 12
```

# Implementation

* [java8](Solution.java)

# Complexity

```
O(HW) O(HW)
```
