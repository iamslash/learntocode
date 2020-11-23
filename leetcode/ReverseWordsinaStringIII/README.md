# Problem

[Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-stringiii/)

# Idea

문자열 `s` 가 주어진다. 각 단어들마다 문자의 순서를 뒤집는 문제이다.

예를 들어 `s = "Let's take LeetCode contest"` 이면 답은 `"s'teL ekat
edoCteeL tsetnoc"` 이다.

다음과 같은 방법으로 해결해 보자.  인덱스 `i, j` 를 이용하여 처음부터
순회하면서 단어를 뒤집는다.

```
s: Let's take LeetCode contest
   i    j
   s'teL
         i   j
         ekat
              i       j
              edoCteeL
                       i      j
                       tsetnoc
   s'teL ekat edoCteeL tsetnoc
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
