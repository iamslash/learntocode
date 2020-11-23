# Problem

[Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)

이차원 행렬 `M[][]` 가 주어진다. `1` 로 구성된 정사각형이 몇개 있는지
구하라.

# Idea

예를 들어 다음과 같은 경우를 살펴보자.

```
0 1 1 1 
1 1 1 1
0 1 1 1

squares with 1 len: 10
squares with 2 len:  4
squares with 3 len:  1
```

따라서 답은 15 이다.

sub matrices 에서 개수를 구하는 문제들은 대부분 한가지 방법을 이용하여
해결할 수 있다. matrix 를 순회할 때 sub matrices 의 right bottom point
라고 가정하고 전략을 생각해 본다.

그리고 별도의 cache 를 선언하는 것보다는 input 으로 주어진 값을
재활용할 수도 있다.

`int cnt = 0` 를 선언하여 답을 저장한다. 인덱스 `y, x` 를 이용하여
`[0..h), [0..w)` 를 각각 순회하며 다음을 반복한다.

* `M[y][x]` 가 1 이면 `M[y][x-1], M[y-1][x-1], M[y-1][x]` 의 값을
  고려하여 `M[y][x]` 를 right bottom 으로 하는 square 의 개수를
  구한다. 그리고 그 개수를 다시 `M[y][x]` 에 저장한다. 그리고 `cnt` 에
  더한다.

모든 반복을 마치면 `cnt` 가 곧 답이다.

다음은 앞서 언급한 예의 풀이과정이다.

```
M:
0 1 1 1    0 1 1 1    0 1 1 1    0 1 1 1
1 1 1 1    1 1 1 1    1 1 1 1    1 1 1 1
0 1 1 1    0 1 1 1    0 1 1 1    0 1 1 1
cnt:
0          1          2          3  

M:
0 1 1 1    0 1 1 1    0 1 1 1    0 1 1 1
1 1 1 1    1 1 1 1    1 1 2 1    1 1 2 2
0 1 1 1    0 1 1 1    0 1 1 1    0 1 1 1
cnt:
4          5          7          9

M:
0 1 1 1    0 1 1 1    0 1 1 1    0 1 1 1
1 1 2 2    1 1 2 2    1 1 2 2    1 1 2 2
0 1 1 1    0 1 1 1    0 1 2 1    0 1 2 3
cnt:
9          10         12         15
```

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(HW) O(1)
```
