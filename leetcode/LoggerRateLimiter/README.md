# Problem

[Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/)

최근 10 초 동안 출력되지 않은 메시지 이면 true 를 리턴하고 출력이
되었으면 false 를 리턴하라.

# Idea

`unordered_map<string, int> history` 를 선언하여
`{msg:last_sec}` 을 저장한다. 

입력 데이터 `ts, msg` 에 대해 `ts - history[msg] < 10` 이면
false 를 리턴한다. 그렇지 않으면 `history[msg] = ts` 를
수행하고 true 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(N)
```
