# Problem

[Lexicographically Smallest String After Applying Operations](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/)

문자열 `s`, 숫자 `a, b` 가 주어진다. `s` 에 다음과 같은 동작을 임의로
선택하여 여러번 적용할 수 있다.

* `s` 의 odd index 에 `a` 를 더한다. `9` 를 넘으면 `0` 으로 돌아간다.
* `s` 를 `b` 만큼 오른쪽으로 회전한다.

앞서 언급한 두가지 동작을 무수히 적용했을 때 만들 수 있는 문자열들 중
사전순으로 가장 작은 것을 구하라.

# Idea

같은 숫자가 나올 때까지 완전탐색한다.

`unordered_set<string> seen` 을 선언하여 이미 방문한 문자열을
저장한다.  `string best` 를 선언하여 사전순으로 가장 작은 문자열을
저장한다. 

문자열 `s[i]` 에 `a` 만큼 더하는 방법은 다음과 같다. 

```
s[i] = (s[i] - '0' + a) % 10
```

문자열 `s` 를 `b` 만큼 오른쪽으로 회전하는 방법은 다음과 같다.

```
reverse(s.begin(), s.end())
reverse(s.begin(), s.begin() + b)
reverse(s.begin() + b, s.end())

b: 2
s: 1 2 3 4 5 6

   6 5 4 3 2 1
   5 6 4 3 2 1
   5 6 1 2 3 4
```

DFS를 마치면 `best` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(2^N) O(N)
```
