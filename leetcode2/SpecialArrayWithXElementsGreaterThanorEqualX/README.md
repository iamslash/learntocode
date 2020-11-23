# Problem

[Special Array With X Elements Greater Than or Equal X](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/)

수열 `A[]` 가 주어진다. 다음의 규칙을 만족하는 `x` 가 존재하면
`x` 를 리턴하고 그렇지 않으면 `-1` 을 리턴하라.

* `x` 는 `A[]` 의 원소일 필요는 없다.
* `x` 보다 크거나 같은 수의 개수가 `x` 이다.

# Idea

예를 들어 `A = [0, 4, 3, 0, 4` 의 경우를 살펴보자.

```
       A: 0 4 3 0 4
              i
sorted A: 0 0 3 4 4
       x: 5 4 3 2 1
```

따라서 답은 `3` 이다.

`A` 를 오름차순으로 정렬한다. 그리고 인덱스 `i` 를 이용하여
처음부터 순회하면서 다음을 반복한다.

* `i == 0` 이고 `0 < x && x <= A[i]` 이면 `x` 를 리턴한다.
* `i > 0` 이고 `A[i-1] < x && x <= A[i]` 이면 `x`  를 리턴한다.

모든 반복을 마치면 `x` 는 존재하지 않기 때문에 `-1` 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
