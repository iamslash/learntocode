# Problem

[ Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/)



# Idea

예를 들어, `W[] = ["abc"]` 인 경우를 살펴보자.

다음과 같이 모든 경우의 수에 대해 `prefix # suffix`
를 제작해 두면 `O(1)` 으로 검색이 가능하다.

```
   #c   0
  a#c   0
  a#    0
   #    0
 ab#    0
   #bc  0
abc#c   0
 ab#bc  0
  a#abc 0
 ab#c   0
abc#    0
   #abc 0
  a#bc  0
abc#bc  0
abc#abc 0
 ab#abc 0
```

prefix trie, suffix trie 를 사용하면 space complexity 를 최적화 할 수
있다.

# Implementation

* [java8](Solution.java)
* [c++11](a.cpp)

# Complexity

```
O(NW^2) O(NW)
```
