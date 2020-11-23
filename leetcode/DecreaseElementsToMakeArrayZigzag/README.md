# Problem

[Decrease Elements To Make Array Zigzag](https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/)

# Idea

수열 `A[]` 가 주어진다. `A[i]` 가 `A[i-2] > A[i-1] < A[i] > A[i+1] <
A[i+2]` 혹은 `A[i-2] < A[i-1] > A[i] < A[i+1] > A[i+2]` 가 되도록
`A[i]` 의 값을 감소해 보자. 감소의 개수를 최소화 했을 경우 그 수를
구하는 문제이다.

문제를 잘 살펴보면 인덱스 `i` 가 짝수일 때 `A[i-1], A[i+1]` 보다
작도록 하거나 인덱스 `i` 가 홀수일 때 `A[i-1], A[i+1]` 보다 작도록
하는 감소수의 합중 최소인 것을 구하는 것과 같다.

예를 들어 `A = [1, 2, 3]` 을 살펴보자. `i` 가 짝수인 경우
감소수는 `0 . -2` 이고 `i` 가 홀수인 경우 감소수는 `. -2 .` 이다.
따라서 답은 `2 = abs(-2)` 이다.

`int cntevn` 을 선언하여 `i` 가 짝수인 경우 감소수의 합을 저장한다.
`int cntodd` 을 선언하여 `i` 가 홀수인 경우 감소수의 합을 저장한다.
문제의 조건에 의해 `1 <= A[i] < 1000` 이다. `A[0]` 은 왼쪽수를 `1001`
로 하고 `A[n-1]` 은 오른쪽수를 `1001` 로 하자.

감소수는 `max(0, A[i] - min(A[i-1], A[i+1]) + 1)` 이다.

다음은 `A = [9, 6, 1, 6, 2]` 인 경우 풀이 과정이다.

```
     A: 9 6 1 6 2
cntevn: 4   4   4
cntodd:   6  12 
```

`min(cntevn, cntodd)` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
