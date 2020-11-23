# Problem

[Largest Values From Labels](https://leetcode.com/problems/largest-values-from-labels/)

# Idea

수열 `V[], L[]`, 숫자 `num_wanted, use_limit` 이 주어진다.  `V[]` 에서
`num_wanted` 보다 작거나 같은 개수의 subsequence 를 선택한다.
이때, 선택하는 숫자는 같은 `L[i]` 에서 `use_limit` 만큼 고를 수 있다.
그리고 선택한 subsequence 들의 합을 구하는 문제이다.

문제를 이해하는 것이 매우 어렵다. `L[i]` 별로 `V[i]` 를 그루핑 한다.
그룹은 내림차순으로 정렬한다. 각 그룹을 순회하면서 subsequence 의
길이가 `num_wanted` 보다 작을 동안 `use_limit` 만큼씩 선택한다.

예를 들어 `V = [5, 4, 3, 2, 1], L = [1, 1, 2, 2, 3], num_wanted = 3,
use_limit = 1` 의 경우를 살펴보자.

```
label: value
    1: 5 4
    2: 3 2
    3: 1

subseq: 5 3 1

answer:9
```

다음은 `V = [5, 4, 3, 2, 1], L = [1, 3, 3, 3, 2], num_wanted = 3,
use_limit = 2` 의 경우를 살펴보자.

```
label: value
    1: 5
    3: 4 3 2
    2: 1

subseq: 5 4 3

answer: 12
```

`multiset<int, int> smp` 를 선언하여 `{V[i], L[i]}` 를 저장한다.
`smp` 의 key 인 `V[i]` 는 오름차순으로 정렬되어 있다. 따라서 `smp` 를
거꾸로 순회하면 `V[i]` 를 내림차순으로 얻어올 수 있다.

`unordered_map<int, int> ump` 를 선언하여 `{L[i], count of L[i]}` 를
저장한다. `ump[i]` 는 `use_limit` 보다 작거나 같아야 한다.

이제 `smp` 를 먼저 채우고 `smp` 를 거꾸로 순회하면서 `num_wanted` 만큼
숫자를 선택한다. 이때 `ump[smp[i]] <= use_limit` 이어야 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
