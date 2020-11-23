# Problem

[Number of Ways to Wear Different Hats to Each Other](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/)

이차원 배열 `person2hat[][]` 이 주어진다. `person2hat[i][j]` 는 i-th
사람이 선호하는 모자의 번호(1-based index) 들을 의미한다.

모자의 종류는 1 부터 40 까지 모두 40 종류이다. 사람은
`person2hat.size()` 만큼 있다. 취향을 고려하여 모자를 사람에게 씌웠을
때 그 경우의 수를 구하라.

# Idea

`vector<vector<int>> hat2person(40)` 를 선언하여 `hat2person[i][j]` 에
i-th 모자에 대응하는 j-th 사람들의 번호를 저장한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(2^N)
```
