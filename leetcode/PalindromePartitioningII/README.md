# Problem

* [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/)

# Idea

문자열이 주어지면 모든 부분문자열들이 회문이 될 수 있도록하는
최소 개수의 파티션을 구하는 문제이다. [manacher algorithm](/fundamentals/string/manacher/README.md) with dynamic programming 으로 해결한다.

예를 들어 `abc` 는 최소개수 파티션이 2 이다. `a|b|c` 이기 때문이다. 
`aab` 는 최소개수 파티션이 1 이다. `aa|b` 이기 때문이다.  

최소 파티션의 개수는 다음과 같이 문자열의 길이 보다 하나 큰 
캐시 `C` 를 정의하여 저장한다. `C[i]` 는 `s[i-1]` 까지의 최소 파티션
길이이다.

`C` 는 seed number `-1` 을 사용하여 다음과 같이 초기화 한다.

```
s: a b c 
C:-1 0 1 2 

s: a a b
C:-1 0 1 2
```

`s` 를 인덱스 `i` 를 이용하여 처음부터 순회한다. `s[i]` 를 중심으로
회문을 검사해본다. 회문이 홀수 혹은 짝수인지에 따라 다른 방식으로 구현한다.
만약 `s[i]` 를 중심으로 길이 2 인 짝수 회문이 존재한다면 
`C[i+1] = min(C[i+1], C[i-1]+1)` 이다.
만약 `s[i]` 를 중심으로 길이 3 인 홀수 회문이 존재한다면
`C[i+2] = min(C[i+2], C[i-1]+1)` 이다.

```
     i
s: a a b
C:-1 0 0 2

     i
s: a a a b
C:-1 0 1 0 3
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```