# Problem

* [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

# Idea

수열 `V` 와 숫자 `m` 이 주어진다. `V` 를 `m` 개의 그룹으로 나눈다.
이때 각 그룹의 합들 중 가장 큰 값을 `maxsum` 이라고 하자.  `maxsum` 이
최소가 되도록 `m` 그룹으로 나누었을 때 `maxsum` 을 구하는 문제이다. 
`1 <= m <= min(50, n)` 이다. `m` 은 항상 `n` 보다 작다.

가장 잘게 나누면 각 숫자가 하나의 그룹이 될 수 있다. 그 때 `maxsum` 은
가장 큰 숫자가 되고 이것을 `losum` 이라고 하자.  모든 숫자를 하나의
그룹으로 하면 `maxsum` 은 모든 숫자를 합한 값이고 이것을 `hisum`
이라고 하자.

`maxsum` 은 `losum` 과 `hisum` 을 포함한 중간에 존재한다. binary
search 를 이용하여 해결한다.

```
    int64_t msm = 0;
    while (lsm < hsm) {
      msm = (hsm + lsm) / 2;
      if (isPartAble(V, m, msm))
        hsm = msm;
      else
        lsm = msm + 1;
    }
    return hsm;
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
