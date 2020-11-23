# Problem

[Get the Maximum Score](https://leetcode.com/problems/get-the-maximum-score/)

두개의 수열 `A, B` 가 주어진다. `A, B` 는 모두 오름차순으로 정렬되어
있다.  `A` 의 시작원소 혹은 `B` 의 시작원소에서 오른쪽 방향으로 한칸씩
전진한다.  이때 `A[i] == B[j]` 이면 반대 수열로 이동할 수도 있고
이동하지 않을 수도 있다. 이동할 때마다 만나는 숫자를 모두 합한다. 그
합이 최대가 되도록 하고 그 합을 구하라.

# Idea

two pointers 로 해결할 만 하다. `A, B` 의 길이를 각각 `n, m` 이라고
하자.  그리고 두개의 인덱스 `i, j` 로 각각 `A, B` 를 순회한다. `int a,
b` 를 선언하여 `A` 경로의 합, `B` 경로의 합을 저장한다.

`while(i < n || j < m)` 인 동안 다음을 반복한다.

* `i < n && (j == m || A[i] < B[j])` 이면 `a` 에 `A[i]` 를 더하고 `i++` 한다.
* `j < m && (i == n || A[i] > B[j])` 이면 `b` 에 `B[j]` 를 더하고 `j++` 한다.
* 그외의 경우는 `a = b = max(a, b) + A[i]` 를 수행하고 `i++, j++` 한다.

예를 들어 다음과 같은 경우를 살펴보자.

```
       i
A: 2 5
B: 3 6
       j
a: 2 7
b: 3 9
```

```
       i
A: 2 5
B: 5 6
       j
a: 2 7
b: 7 13
```

```
       i
A: 2 5
B: 5 6 7
         j
a: 2 7
b: 71321
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
