# Problem

[RLE Iterator](https://leetcode.com/problems/rle-iterator/)

# Idea

RLE encoding 숫자열 `A[]` 가 주어진다. RLEIterator class 를
구현하는 문제이다.

인덱스 `m_i, m_j` 와 같이 두개를 사용해서 구현한다.  `m_i` 는 `A[]` 의
인덱스 이고 `m_j` 는 `A[m_i]` 의 인덱스 이다.  즉, `m_j` 는 `0` 부터
시작하여 `A[m_i]-1` 까지 증가하면 `m_i += 2, m_j = 0` 이 된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
