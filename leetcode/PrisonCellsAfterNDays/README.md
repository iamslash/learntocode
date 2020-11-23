# Problem

[Prison Cells After N Days](https://leetcode.com/problems/prison-cells-after-n-days/)

# Idea

`0, 1` 로 구성된 수열 `C[]` 와 숫자 `N` 이 주어진다. `N` 회 동안 `C` 를 다음과 같은 규칙으로 변경한다. 변경된 수열을 구하는 문제이다.

`vector<int> firstC` 를 선언하여 첫번째 변경된 것을 저장하고 loop 의 기준으로 한다. `vector<int> nextC` 를 선언하여 변경된 `C[]` 를 저장한다. `int cycle = 0` 을 선언하여 cycle 구간의 길이를 저장한다.

`while(N-- > 0)` 동안 다음을 반복한다.

* 인덱스 `i` 를 `[1..n-1]` 동안 순회하면서 `nextC` 를 완성한다.
* 첫번째 `nextC` 라면 `firstC = nextC` 를 수행한다.
* `nextC == firstC` 라면 cycle 이 발견된 것이다. `N %= cycle` 를 수행한다.
* `C = nextC, cycle++` 를 수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```