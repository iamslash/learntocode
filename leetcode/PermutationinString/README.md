# Problem

[Permutation in Strin](https://leetcode.com/problems/permutation-in-string/)

# Idea

문자열 `a, b` 가 주어진다. `a` 의 순열이 `b` 의 부분문자열과 일치하는지
검증하는 문제이다.

`vector<int> src(26)` 를 선언하고 `a` 의 문자에 대한 개수를 `src[i]`
에 저장한다. 그리고 `vector<int> dst(26)` 를 선언한다.

인덱스 `i` 를 이용하여 `b` 를 처음부터 순회한다. `i >= a.size()` 이면
`dst[b[i-a.size()]]++` 를 수행한다. `src == dst` 이면
`(i-a.size()..i]` 가 `a` 의 순열과 같다는 의미이다.

예를들어 `a = "ab", b = "eidbaooo"` 를 살펴보자.

```
b: e i d b a o o o    b: e i d b a o o o    b: e i d b a o o o      
   i                       i                       i              
s: 0 0 0 1 1 0        s: 0 0 0 1 1 0        s: 0 0 0 1 1 0    
d: 1 0 0 0 0 0        d: 1 1 0 0 0 0        d: 0 1 1 0 0 0    

b: e i d b a o o o    b: e i d b a o o o       
         i                       i                 
s: 0 0 0 1 1 0        s: 0 0 0 1 1 0     
d: 0 0 1 1 0 0        d: 0 0 0 1 1 0     
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
