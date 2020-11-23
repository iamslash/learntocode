# Problem

[Maximum Nesting Depth of Two Valid Parentheses Strings](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/)

# Idea

`(, )` 으로 구성된 문자열 `s` 가 주어진다. `s` 를 `A, B` 와 같이
두개의 subsequences 로 나누자. 이때 `max(depth(A), depth(B))` 가
최소가 되도록 하자. 그 때 `s[i]` 가 `A` 에 속하면 `0` `B` 에 속하면
`1` 을 `ans[i]` 에 저장하자. `0` 과 `1` 은 반대여도 상관없다.  `ans[]`
를 구하는 문제이다.

예를 들어 다음과 같이 `s = ( ( ( ( ( ) ) ) ) )` 인 경우를 살펴보자.

`max(depth(A), depth(B))` 가 최소가 되려면 `depth(A)` 와 `depth(B)` 가
차이가 작아야 한다. 그렇다면 `s[i]` 를 한번은 `A` 에 한번은 `B` 에
교대로 배치하면 좋을 것 같다.

```
s: ( ( ( ( ( ) ) ) ) )
   1 2 3 4 5 5 4 3 2 1
   A B A B A A B A B A
```

먼저 `int lvl = 0` 을 순회하여 괄호의 `dpeth` 를 저장한다.  그리고
인덱스 `i` 를 이용하여 `s` 를 순회하면서 다음을 반복한다.

* `s[i] == '('` 이면 `lvl++` 한다. `lvl` 이 홀수 이면 `A` 에 배치한다.
  * `ans[i] = 0`
* `s[i] == ')'` 이고 `lvl` 이 짝수이면 `B` 에 배치하고 `lvl--` 한다.
  * `ans[i] = 1`
  
`ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
