# Problem

[Decoded String at Index](https://leetcode.com/problems/decoded-string-at-index/)

# Idea

인코딩된 문자열 `S` 아 숫자 `K` 가 주어진다. `S` 를 디코딩했을 때 `K`
번째 문자를 구하는 문제이다. 인코딩 방법은 문자열과 숫자를
이용한다. 문제의 조건에 의해 숫자는 한자리수 이다.  예를 들어 `leet2`
를 디코딩 하면 `leetleet` 이다. 또한 `leet2co3` 이면
`leetleetcoleetleetcoleetleetco` 이다.

문자열과 숫자를 합쳐서 블록이라고 해보자. 하나의 블록을 살펴보면
디코딩했을 때 지금까지의 문자열의 길이를 알 수 있다. 

예를 들어서 `leet2co3` 에서 첫번 째 블록 `leet2` 를 살펴보면
디코딩했을 때 전체 길이는 `4 * 2 = 8` 임을 알 수 있다. 또한 두번 째
블록 `co3` 를 살펴보면 디코딩했을 때 전체 길이는 `(8 + 2) * 3 = 30`
임을 알 수 있다.

인덱스 `i` 를 이용해서 `S` 를 순회한다. 블록을 하나씩 디코딩했을 때
전체 길이를 `len` 에 저장하고 `len > K` 일 때 중지한다. 이제
`K` 번째 문자는 마지막 블록 어딘가에 위치해 있다는 말이다.

이제 `i` 를 하나씩 줄여가면서 다음을 반복한다.

* `isdigit(S[i])` 이면 `len /= S[i]-'0', K %= len` 를 수행한다. `K`
  번째 문자는 마지막 블록에 있을 것이기 때문에 `K % len == 0` 이 될
  때까지 `len` 을 하나씩 줄여가면서 `K` 번째 문자를 찾아야 한다.
* `!isdigit(S[i]) && (K % len-- == 0)` 이면 `S[i]` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
