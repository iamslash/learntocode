# Problem

[Longest Chunked Palindrome Decomposition](https://leetcode.com/problems/longest-chunked-palindrome-decomposition/)

# Idea

문자열 `s` 가 주어진다. `s` 를 더욱 작은 문자열 `a_1, a_2, ..., a_k`
로 나눈다. 단, `a_1 == a_k, a_2 == a_k-1, ...` 를 만족해야 한다.
최대의 개수로 나누었을 때 그 개수를 구하는 문제이다.

예를 들어 다음과 같은 문자열 `s = "ghiabghi"` 를 살펴보자.  인덱스 `i`
를 왼쪽에서부터 하나씩 전진한다. `string l, r` 을 선언하여 왼쪽 끝
문자열과 오른쪽 끝 문자열을 저장한다. `l == r` 일 때 마다 `int ans =
0` 를 하나 증가하고 `l = "", r = ""` 를 수행한다.  greedy approach
라고 할 만 하다.

```
     i                    i                    i
  s: g h i a b g h i    g h i a b g h i    g h i a b g h i
                   j                j                j
  l: g                  g h                g h i
  r: i                  h i                g h i
ans: 0                  0                  1
           i                    i                    i
  s: g h i a b g h i    g h i a b g h i    g h i a b g h i
             j                j                j
  l: a                  a b                g
  r: b                  a b                i
ans: 1                  2                  2
                 i                    i      
  s: g h i a b g h i    g h i a b g h i    
       j                j                
  l: g h                g h i              
  r: h i                g h i                
ans: 2                  3                   
```

이번에는 recursive 하게 해결해보자. 먼저 다음과 같이 부분문제를 정의한다.

```c
int solve(string s, int ans = 0)
     s: 문자열
   ans: 개수
return: 답
```

인덱스 `i` 를 `[1..n/2]` 동안 순회하면서 다음을 반복한다.

* 왼쪽 끝 문자열을 `l`, 오른쪽 끝 문자열을 `r` 이라 하자.
* `l` 과 `r` 의 시작 문자와 종료 문자가 같은지 검사한다. 즉, `s[0] ==
  s[n-i] && s[i-1] == s[n-1]` 를 검사한다.
* 그렇다면 `l` 과 `r` 이 같은지 검사한다. 즉, `s.substr(0, i) ==
  s.substr(n - l)` 를 검사한다.
* 그렇다면 `solve(s.substr(i, n - i - i), ans + 2)` 를 리턴한다.

모든 반복이 끝나면 `n > 0` 이면 `ans + 1` 를 리턴한다. `n <= 0` 이면
`ans` 를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [python3](a.py)

# Complexity

```
O(N) O(1)
```
