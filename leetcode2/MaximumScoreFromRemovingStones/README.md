# Problem

[Maximum Score From Removing Stones](https://leetcode.com/problems/maximum-score-from-removing-stones/)

숫자 `a, b, c` 가 주어진다. 두개의 숫자를 하나씩 제거할 수 있다.
제거할 때 마다 1 점씩 획득한다. 최대점수를 구하라.

# Idea

예를 들어 `a = 2, b = 4, c = 6` 의 경우를 살펴보자.

```
2 4 6 
2 3 5
2 2 4
2 1 3
1 1 2
0 1 1
0 0 0
```

따라서 답은 0 이다.

가장 큰 수 두개를 선택하여 하나씩 제거 한다. 그렇게
계속 반복한다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(max(a, b, c))
```
