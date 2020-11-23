# Problem

[Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/)

# Idea

문자열 `s` 와 정수 `k` 가 주어진다. `s` 의 문자들을 배치하여 최소
`k` 의 길이에 중복된 문자가 오지 않도록 배열하는 문제이다.

다음은 입력데이터와 출력데이터의 예이다.

```
s: aabbcc, k: 3, abcabc
s: aaabc,  k: 3, ""
s: a,      k: 0, a
s: a,      k: 2, a
a: "",     k: 3, ""
```

우선순위 큐 `priority_queue<pair<int, char>> pq` 를
선언하고 `(count, char)` 를 삽입한다. `pq` 가 비워질때
까지 문자를 배열한다.

# Implementation

* [c++11](a.cpp)

# Complexty

```
O(N) O(1)
```
