# Problem

> [Count Pairs of Equal Substrings With Minimum Difference](https://leetcode.com/problems/count-pairs-of-equal-substrings-with-minimum-difference/)

문자열 `s1, s2` 가 주어진다. 다음의 조건을 만족하는 `(i,j,a,b)` 짝의
개수를 구하라.

* `0 <= i <= j < s1.length()`
* `0 <= a <= b < s2.length()`
* `s1[i..j]` is a substring of `s1`
* `s2[a..b]` is a substring of `s2`
* `s1[i..j] == s2[a..b]`
* `a - j` should be minimum

# Idea

예를 들어 `s1 = "abcd", s2 = "bccda"` 의
경우를 살펴보자.

```
       .
   s1: abcd
   s2: bccda
           .
pairs: (0,0,4,4)        
```

따라서 답은 1 이다.

`s1[i..j]` 의 끝 문자의 인덱스와 `s2[a..b]` 의 시작 문자의 인덱스의
거리가 최대가 되면 문제의 조건을 만족한다. `s1[i..j] == s2[a..b]` 를
만족하려면 두 부분문자열은 같은 문자를 갖게 된다. 이때 `a - j` 가
최소가 되려면 `s1[i..j].length` 는 1 이 되야 한다.

예를 들어 다음과 같은 경우를 살펴보자.

```
       ..
   s1: xyzw
   s2: zwxy
         ..         
a - j: 1

       .
   s1: xyzw
   s2: zwxy
         .         
a - j: 2
```

따라서 `s1[i..j], s2[a..b]` 는 각각 한 문자이어야 한다.

이 것을 시작으로 다음과 같이 풀어보자.

먼저 필요한 변수를 선언한다.

> * `minDist` : 최소 거리값
> * `cnt` : 답

`char c` 를 `['a'..'z']` 동안 순회하면서 다음을 반복한다.

* `s1[i..j]` 에서 `j` 를 구한다. 즉, `int j = s1.indexof(c)` 를
  수행한다.
* `s2[a..b]` 에서 `b` 를 구한다. 즉, `int a = s2.lastIndexOf(c)` 를
  수행한다.
* `j == -1 || a == -1` 이면 `s1[i..j] == s2[a..b]` 를 만족하는
  부분문자열들은 존재하지 않는다. 건너뛰자.
* `j - a` 가 `minDist` 보다 작으면 `minDist, cnt` 를 업데이트 한다.
* `j - a == minDist` 이면 `cnt` 를 하나 증가한다.

모든 반복을 마치면 `cnt` 가 곧 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```
