# Problem

[Three Equal Parts](https://leetcode.com/problems/three-equal-parts/)

수열 `A[]` 가 주어진다. `A[i]` 는 `0` 혹은 `1` 이다. `A[0]..A[i],
A[i+1]..A[j-1], A[j]..A[n-1]` 과 같이 세구간으로 분리한다. 각 구간은
leading zero 가 허용된다. 세구간 모두 십진수로 변환했을 때 동일해야
한다. `{i,j}` 를 구하라. 만약 불가능하다면 `{-1,-1}` 를 리턴하라.

# Idea

예를 들어 `A= [1, 0, 1, 0, 1]` 의 경우를 살펴보자.

```
   i   j     k
A: 1 | 0 1 | 0 1
```

따라서 답은 `{0, 3}` 이다.

`vector<int> oneIdxs` 를 선언하여 `A[i]` 가 `1` 일때 `i` 를
저장한다. `oneIdxs.size() == 0` 이면 `A[]` 는 모두 `0` 이다. `{0,2}`
를 리턴한다. `oneIdx.size() % 3 != 0` 이면 세구간으로 분리할 수
없다. `{-1, -1}` 를 리턴하라.

`oneIdex[]` 의 크기는 3 의 배수이다. 다음과 같이 각 구간의 시작 인덱스
`i, j, k` 를 구할 수 있다.

* `i = oneIdxs[0]`
* `j = oneIdxs[oneIdxs.size() / 3]`
* `k = oneIdxs[oneIdxs.size() / 3 * 2]`

그리고 각 구간의 크기는 `int len = n - k` 이다.

이제 세구간으로 나누고 `1` 의 개수는 같지만 십진수표현이 다를때를
찾는다. 만약 있다면 `{-1,1}` 를 리턴한다.

```
01
01
10
```

첫 번째 구간의 종료 인덱스는 `i+len-1` 이고 세번째 구간의 시작
인덱스는 `j+len` 이다.  모든 반복을 마치면 `{i+len-1, j+len}` 이
답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
