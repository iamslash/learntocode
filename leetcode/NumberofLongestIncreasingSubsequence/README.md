# Problem

* [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

# Idea

정렬되지 않은 수열 `V` 가 주어지면 `LIS` 의 가지수를 구하는 문제이다.

벡터 `lens, cnts` 를 정의한다. `lens[i]` 는 `[0..i]` 수열중 
기울기가 양수인 것들의 개수를 담는다. 즉 `length(LIS(0..i))` 는
`lens[i] + 1` 과 같다. `cnts[i]` 는 `lens[i]` 의 가지수이다.

다음과 같이 `lens, cnts` 를 bottom-up style 로 채운다.

```
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (V[j] >= V[i])
          continue;
        if (lens[j] >= lens[i]) {
          lens[i] = lens[j] + 1;
          cnts[i] = cnts[j];
        } else if (lens[j]+1 == lens[i]) {
          cnts[i] = (cnts[i] + cnts[j]) % mod;
        }
      }
    }
```

`lens, cnts` 를 순회하면서 가장 큰 `LIS` 크기를 갖는 `cnts[i]`
를 모두 더하면 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
