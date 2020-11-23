# Problem

[Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/)

# Idea

문자의 모음 `A[]` 가 주어진다. 단어들의 순서를 뒤집은 문자열을 구하는 문제이다. 

예를 들어 `A = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]` 이면 답은 `["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]` 이다.

다음과 같은 방법으로 해결해 보자. 
먼저 모든 문자를 한번 뒤집는다.
인덱스 `i, j` 를 이용하여 처음부터 순회하면서 단어를 뒤집는다.

```
s: the sky is blue
   eulb si yks eht
   i   j
   blue
        i j
        is
           i  j
           sky
               i  j
               the
   blue is sky the
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
