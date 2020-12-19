# Problem

[Minimum Incompatibility](https://leetcode.com/problems/minimum-incompatibility/)

수열 `A[]`, 숫자 `k` 가 주어진다. `A[]` 의 숫자들을 `k` 개의 그룹으로
나눈다. 이때 `A.size()` 는 `k` 로 나누어 떨어진다. 또한 그룹으로
나누었을 때 그 원소의 개수는 `A.size() / k` 이다.

그룹으로 나누었을 때 최대 원소와 최소 원소의 차이를 incompatibility
라고 하자. incompatibility 의 합이 최소가 되도록 `A[]` 를 `k` 개의
그룹으로 나누자.  이때 incompatibility 의 합을 구하라.

# Idea

문제의 조건에 의해 `1 <= k <= A.size() <= 16` 이다.  bit sequence 를
이용하여 해결할 만 하다.

먼저 `A[]` 를 오름차순으로 정렬한다. incompatibility 의 합이 최소가
되려면 각 그룹별 incompatibility 가 최소가 되야하기 때문이다.

그리고 `vector<int> range(1 << n)` 을 선언한다. `bm` 은 그룹을
구성하는 선택된 숫자들의 인덱스를 표현한다. 예를 들어 `bm = 0110` 이면
그룹에 `A[1], A[2]` 가 있다는 의미이다.  `range[bm]` 에
incompatibility 를 저장한다. 예를 들어 `A = [1, 2, 1, 4]` 이고 `bm =
0110` 이면 `A[1] = 2, A[2] = 1` 이다. 따라서 `range[0110] = 2 - 1`
이다.

`[0..(1<<n))` 범위의 `range` 를 채운다.

이제 `vector<int> C(1 << n)` 을 선언하다. 역시 `bm` 은 그룹을 구성하는
`A[]` 의 인덱스를 표현한다. `C[bm]` 에 incompatibility 의 합을
저장한다.

모든 반복을 마치면 `C.back()` 이 답이다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(2^N) O(2^N)
```
