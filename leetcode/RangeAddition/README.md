# Problem

[Range Addition](https://leetcode.com/problems/range-addition/)

# Idea

숫자 `n` 과 수열의 모음 `U[][]` 가 주어진다. `u` 의 길이만큼 벡터 `r[]` 
을 생성한다. `U[][0]` 부터 `U[][1]` 까지 `U[][2]` 를 더한다. 최종 
`r[]` 을 구하는 문제이다.

부분합을 이용한다. 예를 들어 `n=5, U=((1,3,2))` 인 경우
다음과 같이 `r[1] += 2; r[4] -= 2` 한 다음 부분합을 구하면
`r[]` 이 완성된다.

```
 r: 0 2 0 0-2
ps:   2 2 2 0
```

`U` 를 모두 적용하고 마지막에 한번 부분합을 구하면 그것이 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(U) O(1)
```
