# Problem

[Strange Printer](https://leetcode.com/problems/strange-printer/)

영문 소문자로 구성된 문자열 `s` 가 주어진다. 프린터는 한번 출력을
시작하면 같은 문자만 출력할 수 있다. 만약 이미 출력한 곳을 다시
출력하게 되면 덮어쓰기 된다. `s` 를 출력할 때 최소로 출력시작 횟수를
구하라.

# Idea

예를 들어 `s = "aaabbb"` 를 살펴보자.

```
s: a b a
   a a a
     b
```

따라서 답은 2 이다.

이번에는 `s = "abcabc"` 를 살펴보자.

```
s: a b c a b c
   a a a a
     b
           b
       c
             c
```

따라서 답은 5 이다.

dynamic programming 으로 해결할 만 하다.

`vector<vector<C>>` 를 선언하여 `C[i][j]` 에 `i` 인덱스에서 시작하여
`j` 인덱스로 끝날때 최소 출력횟수를 저장한다.

그렇다면 다음과 같이 초기화 할 수 있다.

```
C[i][i]   = 1
C[i][i+1] = s[i] == s[i+1] ? 1 : 2
```

그리고 2 이상의 길이 `len` 에 대하여 `beg` 로 `[0, beg+len]` 을
순회한다.  그리고 다시 `k` 로 `[0, len)`을 순회한다.  다음과 같은
dynamic programming equation 을 생각해낼 수 있다.

```
C[beg][beg+len] = len + 1 // max for [beg, beg+len]

tmp             = C[beg][beg+K] + C[beg+k+1][beg+len]
C[beg][beg+len] = min(C[beg][beg+len], s[beg+k] == s[beg+len] ? tmp-1; tmp)
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^3) O(N^2)
```
