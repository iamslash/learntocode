# Abstract

manacher's algorithm 에 대해 적는다.

# References

* [Manacher’s Algorithm – Linear Time Longest Palindromic Substring – Part 1 @ geeksforgeeks](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/)
* [Longest Palindromic Substring Manacher's Algorithm @ youtube](https://www.youtube.com/watch?v=V-sEwsca1ak)

# Problem

문자열 `H` 가 주어진다. 길이가 가장 긴 회문부분문자열을 
구하는 문제이다.

# Idea

알고리즘을 이해하기에 앞서 대칭 인덱스를 구하는 요령을 익혀야 한다. 다음과 같이 인덱스 `j, r` 이 주어질 때 인덱스 `k` 를 구해보자.

```
    k   j   r
0 1 2 3 4 5 6 7 8
    
  k   j   r
0 1 2 3 4 5 6

j - k = r - j
    k = 2 * j - r
```

일차원 배열 `z[]`와 인덱스 `i, j, r` 을 정의한다. 단순히 구현하기 위해 `H` 를 홀수길이로 만들어 `S` 에 저장한다. 예를 들어 `H = banana` 의 경우 `S = .b.a.n.a.n.a.` 이다. 인덱스 `i` 를 중심으로 최대 회문문자열의 반지름을 `z[i]` 에 저장한다. `.` 문자 때문에 반지름의 길이보다 하나 큰 값을 저장한다.

알고리즘이 복잡하기 때문에 코드를 중심으로 과정을 이해하자.
다음은 `H = banaba` 의 경우 `manacher's algorithm` 의 과정이다. 

```
   i                            i
   j                            j
   r                              r
S: . b . a . n . a . n . a .    . b . a . n . a . n . a .
z: 0 0 0 0 0 0 0 0 0 0 0 0 0    1 0 0 0 0 0 0 0 0 0 0 0 0 

     i                              i
     j                            j
         r                            r
S: . b . a . n . a . n . a .    . b . a . n . a . n . a .
z: 1 2 0 0 0 0 0 0 0 0 0 0 0    1 2 1 0 0 0 0 0 0 0 0 0 0 

         i                              i
         j                            j
             r                            r
S: . b . a . n . a . n . a .    . b . a . n . a . n . a .
z: 1 2 1 2 0 0 0 0 0 0 0 0 0    1 2 1 2 1 0 0 0 0 0 0 0 0 

             i                              i
             j                            j
                     r                            r
S: . b . a . n . a . n . a .    . b . a . n . a . n . a .
z: 1 2 1 2 1 4 0 0 0 0 0 0 0    1 2 1 2 1 4 1 0 0 0 0 0 0 

                 i                              i
                 j                            j
                             r                            r
S: . b . a . n . a . n . a .    . b . a . n . a . n . a .
z: 1 2 1 2 1 4 1 6 0 0 0 0 0    1 2 1 2 1 4 1 6 1 0 0 0 0 

                     i                              i
                     j                            j
                             r                            r
S: . b . a . n . a . n . a .    . b . a . n . a . n . a .
z: 1 2 1 2 1 4 1 6 1 4 0 0 0    1 2 1 2 1 4 1 6 1 4 1 0 0 

                         i                              i
                         j                              j
                             r                            r
S: . b . a . n . a . n . a .    . b . a . n . a . n . a .
z: 1 2 1 2 1 4 1 6 1 4 1 2 0    1 2 1 2 1 4 1 6 1 4 1 2 1
```

`z[]` 를 모두 완성했다면 `x = max(z[])` 를 구한다. 그리고
`H.substr((x - z[x] + 1) / 2, z[x] - 1)` 이 답이다. 

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(H) O(H)
```