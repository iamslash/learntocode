# Problem

[Minimum Swaps To Make Sequences Increasing](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/)

수열 `A[], B[]` 가 주어진다. `A[i]` 와 `B[i]` 를 바꿀 수 있다. `A[],
B[]` 모두 순증가가 되도록 하기 위해 필요한 최소 교체 횟수를 구하라.

# Idea

인덱스 `i` 를 이용하여 `A[], B[]` 를 순회한다. 

이전에 구한 최소 교체 수를 이용하여 새로운 최소
교체수를 구하는 방식으로 풀어보자. 이전에 구한 것을 이용하여 새로운
것을 구하는 방식으로 풀어보자.  dynamic programming 이라고 할 만 하다.

먼저 `int swap` 을 선언하여 `A[i], B[i]` 를 바꾸는 경우 최소
교체수를 저장하자. `int nots` 을 선언하여 `A[i], B[i]` 를 
바꾸지 않는 경우 최소 교체수를 저장하자. 
`A[0], B[0]` 에 대한 `swap = 1, nots = 0` 가 자명하다.

다음과 같이 3 가지 경우를 생각해 보자.

0. `A[i-1] >= B[i] || B[i-1] >= A[i]` 일 때
> 0. `A[i], B[i]` 를 바꿨을 때 `A[i-1], B[i-1]` 도 바꿔야 한다.
>> 0. 최소의 `swap` 을 위해 `swap = swap + 1` 를 수행한다.
> 1. `A[i], B[i]` 를 안 바꾸었을 때 `A[i-1], B[i-1]` 도 바꾸지 않아야 한다.
>> 0. 최소의 `nots` 를 위해 `nots = nots` 를 수행한다.

1. `A[i-1] >= A[i] || B[i-1] >= B[i]` 일 때
> 0. 조건 `0` 에 의해 `A[i-1] < B[i] && B[i-1] < A[i]` 이다.
> 1. 예전 `swap` 을 보관하기 위해 `int t = swap` 를 수행한다.
> 2. `A[i], B[i]` 를 꼭 바꿔야 한다.
>> 0. 최소의 `swap` 을 위해 `swap = nots + 1` 를 수행한다.
> 3. `A[i-1], B[i-1]` 을 꼭 바꾸어야 한다.
>> 0. 최소의 `nots` 를 위해 `nots = swap` 를 수행한다.

2. `0, 1` 를 제외한 경우 즉 `A[i], B[i]` 를 바꿔도 되고 안 바꿔도 되는 경우
> 0. 최소값을 `int minval = min(swap[i-1], nots[i-1])` 와 같이 저장한다.
> 1. `swap = minval + 1`
> 2. `nots = minval`

예를 들어 `A = [1, 3, 5, 4], B = [1, 2, 3, 7]` 를 살펴보자.
`swap[], nots[]` 를 모두 채우면 `min(swap[n-1], nots[n-1])` 이
곧 답이다.

```
      i            i            i            i
   A: 1 3 5 4    1 3 5 4    1 3 5 4    1 3 5 4
   B: 1 2 3 7    1 2 3 7    1 2 3 7    1 2 3 7
swap: 1 0 0 0    1 1 0 0    1 1 2 0    1 1 2 1
nots: 0 0 0 0    0 0 0 0    0 0 0 0    0 0 0 2
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
