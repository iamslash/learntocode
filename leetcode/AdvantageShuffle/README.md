# Problem

[Advantage Shuffle](https://leetcode.com/problems/advantage-shuffle/)

# Idea

숫자의 모음 `A[], B[]` 가 주어진다. `A[]` 의 순열중 `A[i] > B[j]` 를
만족하는 개수가 가장 많은 `A[]` 의 순열을 구하는 문제이다.

`A[]` 를 정렬할 필요가 있다. `multiset<int> sst` 를 선언하고 `A[]` 를
채운다. 이제 `*sst.rbegin()` 은 가장 큰 값을 갖는다. 

인덱스 `i` 를 이용하여 `B[]` 를 순회하면서 다음을 반복한다.

0. `*sst.rbegin() <= B[i]` 이면 `sst` 의 숫자는 모두 `B[i]` 보다
   작다는 의미이다. `sst` 의 제일 작은수 `A[i] = *sst.begin()` 를 수행한다.
1. `*sst.rbegin() >= B[i]` 이면 `sst` 에 `B[i]` 보다 큰 수가 있다는
   의미이다. `A[i] = *sst.upper_bound(B[i])` 를 수행한다.
2. `A[i]` 에 저장된 숫자는 `sst` 에서 삭제한다.

모든 반복이 끝나면 `A[]` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
