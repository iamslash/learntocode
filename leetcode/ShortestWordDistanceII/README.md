# Problem

* [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii/)

# Idea

문자열의 모음 `W[]` 와 문자열 `a, b` 가 주어지면 `a, b` 의
거리중 가장 짧은 것을 구하는 문제이다. 이때 문자열은 중복이 가능하다.

`map<string, vector<int>> smp` 를 선언하고 문자열을 키로
인덱스를 밸류로 저장한다.

`a, b` 의 밸류에 해당하는 인덱스들을 서로 짝지어 가장 최소인 녀석을
구한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
