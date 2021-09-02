# Problem

[Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)

문자열 `s` 가 주어진다. `s` 는 `]` 혹은 `[` 로만 구성되어 있다.
임의의 문자를 서로 무한히 교체할 수 있다. 모든 괄호가 짝이 맞도록
해보자.  최소 교체 횟수를 구하라.

# Idea

괄호문제는 무조건 stack 으로 접근해 본다. 짝이 맞는 괄호는 제거하고
짝이 맞지 않는 괄호는 stack 에 남겨보자. 다음과 같은 패턴을 발견할 수
있다.

```
               ans  stack    size
s: ][          1    [        1
s: ]][[        1    [[       2
s: ]]][[[      2    [[[      3
s: ]]]][[[[    2    [[[[     4
s: ]]]]][[[[[  3    [[[[[    5
```

따라서 다음과 같은 수식을 발견할 수 있다.

```
ans = (stack.size() + 1) / 2
```

stack 의 개수가 중요하기 때문에 꼭 stack 을 사용하지 않고 짝이 맞지
않는 괄호의 개수만 구해도 된다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
