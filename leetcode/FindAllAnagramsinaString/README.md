# Problem

[Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

문자열 `s, p` 가 주어진다. `s` 에서 `p` 의 anagram 이 존재하는
인덱스들의 모음을 구하는 문제이다.

# Idea

예를 들어 ` s = "cbaebabacd", p = "abc"` 의 경우를 살펴보자.  `p` 의
길이만큼 윈도우가 있다고 해보자. 그 윈도우를 `s` 위에서
이동한다. 이동할 때 마다 `p` 를 구성하는 문자들과 `s` 를 구성하는
문자들의 개수가 같다면 `s` 에서 윈도우의 시작 인덱스를 답에 추가한다.

```
        ___
     s: cbaebabacd
     p: abc
```

`int[] sFreqs = new int[26]`, `int[] pFreqs = new int[26]` 을 선언하여
각각 `s, p` 의 구성 문자의 발생횟수를 저장한다. 윈도우를 하나 이동할
때마다 `sFreqs` 와 `pFreqs` 를 비교한다. 같다면 `s` 에서 윈도우의 시작
인덱스를 답에 저장한다.

```
        ___
     s: cbaebabacd
           i
     p: abc
sFreqs: a b c
        0 0 1
pFreqs: a b c
        1 1 1
 
```

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
