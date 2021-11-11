# Problem

[Number of Equal Count Substrings](https://leetcode.com/problems/number-of-equal-count-substrings/)

# Idea

문자열 `s`, 숫자 `count` 가 주어진다. `s` 의 subarray 중 그 것을
구성하는 영문 소문자가 `count` 만큼만 존재하는 것들의 길이를 구하라.

예를 들어 `s = "aaabcbbcc", count = 3` 의 경우를 살펴보자.

```
s: a a a b c b c c
   -----
         ---------
   ---------------         
```

따라서 답은 `3` 이다.

sliding window 를 활용하며 해결할 만 하다.  window 의 크기는 `count`
의 배수이다. `s` 를 구성하는 unique 한 영문 소문자의 개수를
구한다. 그것을 `uniqCharCnt` 라고 하자.  sliding window 의 최대 크기
즉, substring 의 최대 크기는 `uniqCharCnt * count` 이다. 이 것을
`maxWndSize` 라고 하자. sliding window 의 크기를 `[count..maxWndSize]`
만큼 순회하며 선형 탐색하자.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
