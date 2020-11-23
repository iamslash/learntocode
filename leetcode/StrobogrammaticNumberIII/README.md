# Problem

* [Strobogrammatic Number III](https://leetcode.com/problems/strobogrammatic-number-iii/)

# Idea

두개의 문자열 `lo, hi` 가 주어지면 `lo` 보다 크거나 같고 `hi` 보다 작거나
같은 strobogrammatic number 문자열 `s` 의 개수를 구하는 문제이다.

다음과 같은 부분문제를 정의하고 backtracking 으로 해결해보자.

```
void dfs(string s, int left, int right)

    s: 이번에 변경해야할 문자열
 left: 이번에 변경해야할 s 의 왼쪽 인덱스
right: 이번에 변경해야할 s 의 오른쪽 인덱스
```

`s` 의 길이를 `lo.size()` 에서 `hi.size()` 만큼 변경하면서
strobogrammatic number 문자열을 만들어 보고 조건에 맞으면
`m_cnt` 를 하나씩 증가하자.

![](reucrsiontree.png)

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(5^(N)) O(N)
```