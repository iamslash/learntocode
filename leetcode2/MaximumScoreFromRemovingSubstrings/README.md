# Problem

[Maximum Score From Removing Substrings](https://leetcode.com/problems/maximum-score-from-removing-substrings/)

문자열 `s` 와 숫자 `x, y` 가 주어진다. `s` 에 대해 `ab` 혹은 `ba` 를
찾아 지운다. `ab` 를 지우면 `x` 만큼 `ba` 를 지우면 `y` 만큼 점수를
모은다.  점수가 최대가 되도록 문자열을 삭제했을 때 그 최고 점수를
구하라.

# Idea

예를 들어 `s = "cdbcbbaaabab", x = 4, y = 5` 의 경우를 살펴보자.

```
x: 4
y: 5
cdbcbbaaabab   5
cdbcbaabab     5
cdbcabab       5
cdbcab         4
cdbc
```

따라서 답은 19 이다.

`x < y` 이면 `x, y` 를 바꾸고 `x` 가 항상 크도록 한다.  `String z, w`
를 선언하여 각각 `x` 를 얻는 문자열 혹은 `y` 를 얻는 문자열을
저장한다.

`Deque<Character> xStack = new ArrayDeque<>()` 를
선언한다.

`char c` 로 `s.toCharArray()` 순회하며 다음을 반복한다.

* `xStack.size() > 0 && xStack.getLast() == z.charAt(0) && c ==
  zCharAt(1)` 이면 `z` 를 발견한 것이다. 즉, `xStack.pollLast()` 를
  수행하고 `ans += x` 를 수행한다.
* 그렇지 않으면 `xStack.addLast(c)` 를 수행한다.

`Deque<Character> yStack = new ArrayDeque<>()` 를 선언한다.

`xStack.size() > 0` 동안 다음을 반복한다.

* `char c = xStack.pollLast()` 를 수행한다.
* `yStack.size() > 0 && c == w.charAt(0) && yStack.getLast() ==
  w.charAt(1)` 이면 `w` 를 발견한 것이다. 즉, `yStack.pollLast()` 를
  수행하고 `ans += y` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(N)
```
