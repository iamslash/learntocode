# Problem

[Split Array With Same Average](https://leetcode.com/problems/split-array-with-same-average/)

수열 `A[]` 가 주어진다. 평균이 같은 두개의 수열로 분리할 수 있는지
검증하라.

# Idea

예를 들어 `A = [1, 2, 3, 4, 5, 6, 7, 8]` 의 경우를 살펴보자.  `B = [1,
4, 5, 8], C = [2, 3, 6, 7]` 로 분리할 수 있다.  이때 평균은 각각 `4.5`
이다.  따라서 답은 `true` 이다.

두개의 수열 `B, C` 중 개수가 적은 것을 `B` 라고 할 때 다음과 같은
규칙을 생각해 낼 수 있다.

```
Asum / n = Bsum / i 
         = CSum / (n-i)

       k = B.size() (1 <= i <= n/2)

    Bsum = Asum * i / n (This should be an integer)

    So, Asum * i % n == 0 
```

k 를 `[1..n/2]` 동안 순회하면서 `ASum * k % n == 0` 을 만족하는 것이
있는지 조사한다.

It's too difficult.

# Implementation

* [c++11](a.cpp)

# Complexity

```
```
