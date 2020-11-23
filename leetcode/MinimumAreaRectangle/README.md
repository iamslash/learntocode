# Problem

[Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/)

# Idea

좌표들의 모음 `P[][]` 가 주어지면 점 4 개를 선택하여 만들 수 있는
사각형들 중 가장 넓이가 적은 것의 크기를 구하는 문제이다.

문제를 잘 읽어봐야 한다. 모든 점을 포함하는 사각형의 넓이가 아니고 4
개의 점을 선택하여 만들 수 있는 최소 크기의 사각형의 넓이를 구하는
것이다.

한 점을 `x, y` 로 표기할 수 있다. `unordered_map<int, set<int>> rect`
를 선언하여 `x` 를 키로 `y` 를 값들로 저장하자.

`int ans = INT_MAX` 를 선언하여 최소 넓이를 저장한다.  이제 `rect` 를
순회하면서 두개의 원소를 선택하고 `ans` 를 갱신한다.  모든 반복을
마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
