# Problem

[Design Excel Sum Formula](https://leetcode.com/problems/design-excel-sum-formula/)

행과 열의 숫자 `H, W` 가 주어지면 `set, get, sum` 을 구현하는
문제이다.

# Idea

`sum(r, c, ranges[])` 은 `set()` 혹은 `sum` 에 의해 동일한 `r, c` 가
오버래핑될때 까지 `ranges[]` 를 보관해야 한다.

행과열의 데이터를 저장하기 위해 `vector<vector<int>> m_M` 를
선언한다. 그리고 `ranges[]` 를 보관하기 위해 맵 `map<pair<int, char>,
vector<string>> m_smp` 를 선언한다.

* `void set(int r, char c, int v)`

`m_smp` 가 `{r, c}` 를 가지고 있는지 검사하고 있다면 오버래핑되는
것이므로 제거한다. 그리고 `m_M[r][c]` 에 `v` 를 저장한다.
`v` 는 리스트가 아니고 하나이기 때문에 `m_smp` 에 저장할
필요는 없다.

* `int get(int r, char c)`

`m_smp` 가 `{r, c}` 를 가지고 있는지 검사하고 있다면 `sum(r, c,
m_smp[{r, c}]` 를 리턴한다. 그렇지 않다면 `m_M[r-1][c-'A']` 를
리턴한다.  `sum()` 을 호출하면 파싱해서 숫자로 반환하는 코드를
중복작성할 필요가 없다.

* `int sum(int r, int c, vector<string> V)`

누적된 합을 위해 `sum` 을 선언한다.

`V` 를 순회하면서 문자열 `s` 에 대해 다음을 반복한다.

0. `s` 가 범위가 아니라면 `sum += get(y, x)` 를 수행한다.
1. `s` 가 범위라면 `ltc, ltr, rbc, rbr` 를 구하고 `get(y, x+'A')` 를
이용하여 합을 누적한다.

문제의 조건에 의해 `V` 를 보관해야 하므로 `m_smp[{r, c}] = V` 를
수행한다.  그리고 `sum` 을 리턴한다.

# Implementation

* [c++11](a.cpp)
* [java11](MainApp.java)

# Complexity

```
set: O(1) O(N)
get: O(1) O(N)
sum: O(S) O(N)

S: count of ranges
```
