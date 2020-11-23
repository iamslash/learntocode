# Problem

양의 정수 `n` 이 주어졌을 때 `[1..n]` 
의 숫자들로 구성된 부분집합을 
만들어 보자.

# References

* [Backtracking to find all subsets @ geeksforgeeks](https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/)

# Idea

예를들어 `n = 3` 일때 다음과 같이
부분집합들을 만들어 낼 수 있다.

```
123
12 23 13
1 2 3
{}
```

공집합을 포함한 부분집합의 개수는 `2^n` 과 같다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(2^N) O(N)
```
