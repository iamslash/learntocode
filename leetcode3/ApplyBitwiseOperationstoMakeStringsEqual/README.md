# Problem

[Apply Bitwise Operations to Make Strings Equal](https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/)

문자열 `s, t` 가 주어진다. `s, t` 는 `0, 1` 로 구성되어 있다.

`s` 에 대해 다음과 같은 동작을 무수히 반복할 수 있다.

* 임의의 `i, j (0 <= i, j < n)` 를 고른다.
* `s[i] = s[i] or s[j]`, `s[j] = s[i] xor s[j]` 를 수행한다.

`s` 가 `t` 가 될 수 있는지 검증하라.

# Idea

예를 들어 `s = "1010", target = "0110"` 의 경우를 살펴보자.

```
   _   _
s: 1 0 1 0
     _ _
   0 0 1 0
   
   0 1 1 0
```

따라서 답은 `true` 이다.

임의의 `i, j` 에 대해 모든 `s[i], s[j]` 를 생각해 보자.

```
         s[i]: 0 0 1 1 
         s[j]: 0 1 0 1
 s[i] or s[j]: 0 1 1 1
s[i] xor s[j]: 0 1 1 0
```

다음과 같은 규칙들을 발견할 수 있다.

* `s` 의 두 숫자가 `0, 0` 이면 어느 숫자도 `1` 로 바꿀 수 없다.
* `s` 의 두 숫자가 `0, 1` 혹은 `1, 0` 이면 두 숫자를 `1, 1` 로
  바꾸어야 한다.
* `s` 의 두 숫자가 `1, 1` 이면 두 숫자를 `0, 1` 혹은 `1, 0` 으로 바꿀
  수 있다.

이 것을 다음과 같이 요약할 수 있다.

```
s.contains("1") == t.contains("1")
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(1)
```
