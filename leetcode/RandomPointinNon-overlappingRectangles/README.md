# Problem

[Random Point in Non-overlapping Rectangles](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/)

# Idea

사각형의 모음 `R[]` 이 주어진다. 사각형들의 내부의 점을 랜덤하게
생성하는 문제이다.

`R[]` 의 넓이의 총합을 `sum` 이라고 하자. `rand() % sum` 에 해당하는
사각형을 `R[i]` 라고 하자. `R[i]` 의 넓이와 높이를 `w, h` 라고 하자.

`x = R[i][0] + rand() % w, y = R[i][1] + rand() % h` 가 답이다. 

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
