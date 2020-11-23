# Problem

[Maximal Square](https://leetcode.com/problems/maximal-square/)

`0, 1` 로 구성된 이차원 배열 `M[][]` 이 주어진다. `1` 로 구성된
가장 큰 정사각형의 `1` 의 개수를 구하라.

# Idea

`C[][]` 를 선언한다. 그리고 `C[y][x]` 에 `M[y][x]` 를 right bottom
으로 하는 max valid square 의 한 변 길이를 저장한다. 

그렇다면 `C[y+1][x], C[y][x+1], C[y+1][x+1]` 를 이용하여 `C[y][x]` 를
구할 수 있다. 그리고 `M[y][x]` 를 right bottom 으로 하는 max valid
square 의 한 변 길이를 얻어낼 수 있다.

```
if (M[y][x] > '0')
  C[y][x] = min(C[y-1][x-1], C[y-1][x], C[y][x-1]) + 1
ans = max(ans, C[y][x] * C[y][x])
```

다음은 `2 x 2` 의 `C[1][1]` 를 구하는 과정이다.

```
M:       C:
   1 1      1 1
   1 1      1 2
   
C[1][1] = min(C[0][0], C[0][1], C[1][0]) + 1
```

다음은 `3 x 3` 의 `M[2][2]` 를 구하는 과정이다.

```
M:         C:
   1 0 1      1 0 1
   1 1 1      1 1 1 
   1 1 1      1 2 2
   
C[2][2] = min(C[1][1], C[2][1], C[1][2]) + 1
```

`M[y][x]` 는 int 가 아니고 char 임을 유의하자. 또한 `C[][]` 를
선언하는 대신 `M[][]` 를 사용하면 space complexity 를 줄일 수 있다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [python3](a.py)
* [go](a.go)

# Complexity

```
O(HW) O(1)
```
