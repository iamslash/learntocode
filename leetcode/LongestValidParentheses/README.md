# Problem

* [Longest Valid Parentheses @ leetcode](https://leetcode.com/problems/longest-valid-parentheses/)

소괄호들의 문자열을 처음부터 끝까지 순회하면서
짝이 맞는 괄호의 최대 개수를 출력해보자.

# Stack

## Idea

다음과 같은 예가 있다.

```
(()
2

)()())
4

)())()())
4
```

stack 에 괄호의 인덱스를 삽입한다. seed 값으로 -1 을 삽입한다. 짝이
맞는 괄호들을 stack 에서 제거한다.  stack 에 해결되지 않는 괄호들이
존재할 때 마지막에 해결된 우측괄호 인덱스와 `stack.top()` 의 차이가
가장 큰 값이 답이다.

## Implementation

* [c++11](stack.cpp)

## Complexity

```
O(N) O(N)
```

# Back and Forth

## Idea

`int ing` 를 선언하여 짝을 맞추고 있는 괄호의 개수를 저장한다. `int
cnt` 을 선언하여 짝이 맞는 괄호의 개수를 저장한다. `int ans` 를
선언하여 답을 저장한다.

## Implementation

* [java8](Solution.java)

## Complexity

```
O(N) O(1)
```
