# Problem

[Maximum Number of Occurrences of a Substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/)

# Idea

문자열 `s`, 숫자 `maxL, minS, maxS` 가 주어진다.  `s` 의 substring
중에 unique 한 문자열의 개수가 최대 `maxL` 이고 문자열의 길이가 최소
`minS`, 최대 `maxS` 인 것들 중 그 개수가 가장 많은 것을 구하는
문제이다.

그 부분문자열이 최대 개수가 되려면 `maxS` 는 생각할 필요가 없다.

sliding window 를 하나 만들고 처음 인덱스과 끝 인덱스를 각각 `i, j`
라고 해보자. 그러면 다음과 같은 pattern 으로 skeleton 을 구성할 수
있다.

```
while (j < s.size()) {
  // slide j
  // slide i with while
  // handle window
}
```

j 는 거북이이고 i 는 토끼다. j 는 한번씩 전진한다.  i 는 while 과 함께
주욱 전진한다.

조건이 맞으면 handle window 에서 처리한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
