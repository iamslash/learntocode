# Problem

[Shortest Way to Form String](https://leetcode.com/problems/shortest-way-to-form-string/)

문자열 `S` 와 `T` 가 주어진다. `S` 의 subsequence 들을 연결해서 `T` 를
만들어 보자. 가장 적은 subsequence 개수를 구하는 문제이다. `T` 를
만드는 것이 불가능하면 `-1` 을 리턴한다.

# Idea

`int ans` 를 선언하여 답을 저장한다. 인덱스 `int i, j` 를 선언하여 `j
< T.size() && ans <= j` 동안 `S, T` 를 순회한다. `S.size() < T.size()`
이므로 `i` 는 여러번 `0` 으로 초기화 할 수 있다.  `i = 0` 할 때 마다
`ans++` 를 수행한다. 

예를 들어서 `S = abc, T = abcbc` 를 살펴보자. `ans <= j` 이므로 답은
`ans + 1 = 2` 이다.

```
  S: abc      abc      abc      abc      abc      abc     
     i         i         i         i     i         i
  T: abcbc    abcbc    abcbc    abcbc    abcbc    abcbc
     j         j         j         j        j        j
ans: 0        0        0        0        1        1

  S: abc      abc    
       i         i   
  T: abcbc    abcbc  
         j         j 
ans: 1        1
```

다음은 `S = abc, T = abdbc` 를 살펴보자. `ans > j` 이므로 답은 `-1`
이다.

```
  S: abc      abc      abc      abc      abc   
     i          i      i        i        i
  T: acdbc    acdbc    acdbc    acdbc    acdbc 
     j         j         j        j        j
ans: 0        0        1        2        3
```

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)
* [go](a.go)
* [js](a.js)

# Complexity

```
O(ST) O(1)
```
