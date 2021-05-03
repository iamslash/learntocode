# Problem

> [Minimum Adjacent Swaps to Reach the Kth Smallest Number](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/)

숫자로 구성된 문자열 `num` 과 숫자 `k` 가 주어진다. `k` 번째 작은
숫자를 찾아라. 그 숫자를 `prm` 이라고 하자. `num` 에서 `prm` 으로
재배치 하기 위해 필요한 인접한 숫자의 최소 이동횟수를 구하라.

# Idea

예를 들어 `num = "5489355142", k = 4` 의 경우를 살펴보자.

```
num: 5489355142
prm: 5489355214
     5489355241
     5489355412
     5489355421
     
            __
num: 5489355142
prm: 5489355421
```

따라서 답은 2 이다.

`num` 보다 크고 `k` 번째 작은 문자열 `prm` 은 `next_permutation` 을
이용해서 구한다.

`num` 에서 `prm` 가 되기위해 필요한 인접한 숫자의 최소 이동 횟수는
`rotate` 을 이용해서 구한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
