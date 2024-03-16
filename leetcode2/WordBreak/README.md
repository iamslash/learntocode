# Problem

[Word Break](https://leetcode.com/problems/word-break/)

문자열 `s` 가 주어진다. 문자열의 모음 `W[]` 가 주어진다. 
`s` 가 `W[]` 의 문자열들로 구성되는지 검증하라.

# Idea

[CoinChange](/leetcode/CoinChange/README.md) 와
비슷하다. `s` 가 총 금액이고 `W[]` 가 동전의 모음이라고 생각하고
접근하자.

먼저 `vector<bool> C(n+1)` 를 선언하여 `C[i]` 에 `s[i]` 로 시작하는
문자열이 `W[]` 로 구성될 수 있는지를 저장한다. `C[n]` 은 seed value
이기 때문에 `true` 로 초기화 한다.

인덱스 `i` 를 `[n-1..0]` 동안 순회하면서 다음을 반복한다. 

* `W[]` 를 `word` 로 순회하면서 다음을 반복한다.
  * `i + word.size() <= n` 이고 `C[i + word.size()]` 이고
    `strncmp(&s[i], word.c_str(), word.size()) == 0` 이면 `C[i] =
    true` 를 수행한다. 그리고 더이상 `W[]` 를 순회할 이유가
    없다. 반복을 멈춘다.

모든 반복을 마치면 `C[0]` 이 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(SW) O(S)
```
