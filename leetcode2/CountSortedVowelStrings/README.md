# Problem

[Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/)

숫자 `n` 이 주어진다. 영문자 모음 `a, e, i, o, u` 를 `n` 개 만큼
배치한다. 이때 순서는 사전순으로 오름차순이어야 한다. 모든 경우의 수를
구하라.

# Idea

예를 들어 `n = 1` 인 경우를 살펴보자.

```
a 1
e 1
i 1
o 1
u 1
```

따라서 답은 5 이다.

이번에는 `n = 2` 인 경우를 살펴보자.

```
a{a,e,i,o,u} 5
e{e,i,o,u}   4
i{i,o,u}     3
o{o,u}       2
u{u}         1
```

따라서 답은 15 이다.

이번에는 `n = 3` 인 경우를 살펴보자.

```
a{...}       15
e{...}       10
i{...}        6
o{...}        3
u{...}        1
```

따라서 답은 35 이다.

`int a=1, e=1, i=1, o=1, u=1` 를 선언한다.

인덱스 `i` 를 이용하여 `[0..n-1)` 동안 순회하며 다음을 반복한다.

* a = a + e + i + o + u
* e = e + i + o + u
* i = i + o + u
* o = o + u
* u = u

모든 반복을 마치면 `a + e + i + o + u` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
