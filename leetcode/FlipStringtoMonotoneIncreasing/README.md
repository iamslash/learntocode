# Problem

[Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/)

# Idea

`0, 1` 로 구성된 문자열 `s` 가 주어진다. monotone increasing 
이 되도록 flipping 할 때 최소 횟수를 구하는 문제이다.

dynamic programming 으로 해결한다.

먼저 `int ones` 를 선언하여 `1` 의 개수를 저장한다. monotone
increasing 을 만들기 위해 `1` 을 flipping 한 횟수를 의미한다. 
`int rslt` 를 선언하여 지금까지 수행한 최소의 flipping 횟수를
저장한다. 

그리고 `s` 를 인덱스 `i` 를 이용하여 처음부터 끝까지
순회하며 다음을 반복한다.

0. `s[i] == '1'` 이면 `ones += 1` 를 수행한다.
1. `s[i] == '0'` 이면 `rslt = min(rslt + 1, ones)` 를 수행하여 
   flipping 을 수행한 경우의 횟수와 수행하지 않는
   경우의 횟수를 비교하여 최소의 값을 갱신한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```