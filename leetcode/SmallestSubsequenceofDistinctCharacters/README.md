# Problem

[Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

# Idea

영문 소문자로 구성된 문자열 `s` 가 주어진다. `s` 의 서로 다른 문자를
하나씩만 사용해서 사전순으로 가장 작은 subsequence 를 구하는 문제이다.

`vector<int> cnt(26)` 을 선언하여 `{c-'a': count of c}` 를
저장한다. `vector<int> use(26)` 을 선언하여 `{c-'a': used count of c}`
를 저장한다. `string ans` 을 선언하여 답을 저장한다.

`s` 를 처음부터 순회한다. `ans` 에 삽입된 문자들의 개수가 아직 남아 있고
`s[i]` 보다 사전순으로 크다면 `ans` 에서 제거한다. 그리고 `s[i]` 를
`ans` 에 삽입한다. 

모든 반복을 마치고 나면 `ans` 가 곧 답이다.

다음은 `s = "cdadabcc"` 의 풀이 과정이다.

```
                          i                    i
    s: c d a d a b c c    c d a d a b c c    c d a d a b c c 
count: c d a b            c d a b            c d a b
       3 2 2 1            3 2 2 1            3 2 2 1
 used: c d a b            c d a b            c d a b
       0 0 0 0            1 0 0 0            1 1 0 0
  ans:                    c                  c d
  
           i                    i                    i
    s: c d a d a b c c    c d a d a b c c    c d a d a b c c 
count: c d a b            c d a b            c d a b
       2 1 2 1            2 1 2 1            2 1 1 1
 used: c d a b            c d a b            c d a b
       0 0 1 0            0 1 1 0            0 1 1 0
  ans: a                  a d                a d

                 i                    i                    i
    s: c d a d a b c c    c d a d a b c c    c d a d a b c c 
count: c d a b            c d a b            c d a b
       2 1 1 1            2 1 1 1            1 1 1 1
 used: c d a b            c d a b            c d a b
       0 1 1 1            1 1 1 1            1 1 1 1
  ans: a d b              a d b c            a d b c

```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
