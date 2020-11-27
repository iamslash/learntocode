# Problem

[Decode String](https://leetcode.com/problems/decode-string/)

문자열 `s` 가 주어진다. 각 문자는 `0-9, a-z, [, ]` 로만 구성되어 있다.
`k[encoded_string]` 형태의 문자열을 만나면 `k` 번 만큼
`encoded_string` 을 반복한다. 이때 `[,]` 가 중첩되면 가장 안쪽의 `[,]`
를 먼저 처리해야 한다. 모든 문자열을 디코딩하라.

# Idea

`[,]` 가 겹치는 것을 우선순위에 맞게 처리하기위해 `stack` 을 사용한다.

`stack<pair<string, string>> stck` 을 선언하여 `{k, decoded-string}`
을 저장한다. loop invariant 를 쉽게 구현하기 위해 `stck.push(0, "")`
으로 초기화한다.

`string num` 을 선언하여 반복에 해당하는 숫자를 문자열의 형태로
저장한다.

`s` 를 `char c` 로 순회하면서 다음을 반복한다.

* `c` 가 숫자이면 `num += c` 를 수행한다.
* `c` 가 `[` 이면 `{num, ""}` 를 삽입한다.
* `c` 가 문자이면 `stck.top().second += c` 를 수행한다.
* `c` 가 `]` 이면 `stck` 에서 하나꺼내 `{k,s}` 라고 하자. `s` 를 `k`
  만큼 반복한 문자열을 `stck.top().second` 에 더한다.

모든 반복을 마치면 `stck.top().second` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
