# Problem

[Check If Word Is Valid After Substitutions](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/)

# Idea

문자열 `s` 가 주어진다. `s` 는 `a, b, c` 로만 구성되어 있다.  문제의
조건이 복잡하다. 그러나 잘 읽어 보면 `s` 에서 `abc` 가 없을 때 까지
반복해서 `abc` 를 제거했을 때 `s.empty()` 인지 검증하는 문제이다.

물론 brute force 하게 반복해서 지워도 된다. 그러나 스택을 사용한다면
시간복잡도를 더욱 낮출 수 있다.

스택 `stack<int> stck` 를 선언하고 `s` 를 처음부터 한문자씩
순회한다. 스택에 한문자씩 삽입하다가 가장 윗문자열 3 개가 `abc` 이면
stck 을 비운다. 모든 반복을 마치고 `stck.empty()` 이면 `true` 를
리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
