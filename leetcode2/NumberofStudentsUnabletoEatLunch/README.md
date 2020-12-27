# Problem

[Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)

수열 `A[], B[]` 가 주어진다. `A[i]` 는 i-th 사람의 선호도 이다. `0, 1`
중 하나이다. `B[i]` 는 샌드위치의 타입이다. 역시 `0, 1` 이다.

`A[]` 는 queue 에 삽입되어 있다. `B[i]` 는 stack 에 삽입되어 있다.

`A[i]` 와 `B[j]` 가 일치하면 queue 에서 `A[i]` 를 제거하고 stack 에서
`B[j]` 를 제거한다. 모든 반복을 마치고 `B[j]` 에서 제거될 수 없는
샌드위치의 개수를 구하라.

# Idea

`B[j]` 를 기준으로 `A[]` 를 순회할 때 마다 일치하는 것이 발견되면
`A[i], B[j]` 를 각각 queue, stack 에서 제거하면 된다.

이것은 `B[j]` 입장에서 일치하는 `A[i]` 가 있는지 조사하는 것과 같다.

그렇다면 다음과 같은 방법으로 접근해 본다.

`int cnts[2] = {0, 0}` 를 선언하여 `A[i]` 선호도가 `0` 인 것의 개수,
`1` 인 것의 개수를 저장한다. `int j = 0` 을 선언하여 `B[]` 의 인덱스를
저장한다.

`j` 를 `[0..B.size())` 동안 순회하며 다음을 반복한다. 만약
`cnts[B[j]] == 0` 이면 반복을 종료한다.

* `cnts[B[j]--` 를 수행한다.

모든 반복을 마치면 `B.size() - j` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
