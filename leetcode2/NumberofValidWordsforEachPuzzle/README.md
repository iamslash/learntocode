# Problem

[Number of Valid Words for Each Puzzle](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/)

문자열의 모음 `W[], P[]` 가 주어진다. `P[i]` 가 다음을 만족하는 `W[]`
의 개수를 구하라.

* `W[i]` 는 `P[0]` 을 반드시 가지고 있어야 한다.
* `W[i]` 의 모든 글자는 `P[i]` 에 존재해야 한다.

# Idea

`Map<Integer, List<Integer>> C` 를 선언하여 소문자별 `W[i]` 를
저장한다. `C` 가 모두 채워지면 소문자 하나를 포함한 모든 단어를 알수
있게 된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
