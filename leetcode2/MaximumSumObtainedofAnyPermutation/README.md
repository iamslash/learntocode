# Problem

[Maximum Sum Obtained of Any Permutation](https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/)

수열 `N[]`, 간격의 모음 `R[][]` 가 주어진다.  `R[i][0]` 는 시작을
인덱스를, `R[i][1]` 은 종료 인덱스를 의미한다.  `N[]` 을 적당히
배치하여 `R[][]` 의 영역의 숫자들을 모두 합하자.  그 합이 최대가 될때
그 합을 구하라.

# Idea

`R[][]` 의 영역들이 겹치는 곳에 가장 큰 수를 배치하면 된다.

먼저 `vector<int> cnt(N.size())` 를 선언하고 `N[]` 의 인덱스별 발생
횟수를 저장한다. `R[][]` 을 `r[]` 로 순회하면서 다음을 반복한다.

* `cnt[r[0]] += 1` 을 수행한다.
* `cnt[r[1] + 1] -= 1` 을 수행한다.

이제 partial sum 처럼 `cnt[]` 를 순회하면서 합한다. 신기하게도
`cnt[i]` 는 `N[i]` 의 발생횟수가 저장된다. 이것을 오름 차순으로
정리한다. 그리고 `N[]` 을 오름차순으로 정리한다.

인덱스 `i` 를 이용하여 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `ans = (ans + N[i] * cnt[i]) % MOD`

모든 반복을 마치면 `ans` 가 답이다.

```
  R: 1,3 0,1
  N: 1 2 3 4 5
cnt: 1 1-1  -1
     1 2 1 1 0
     0 1 1 1 2
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
