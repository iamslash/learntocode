# Problem

[Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)

# Idea

수열 `A`, 숫자 `K` 가 주어진다. `A` 의 subarray 들 중 서로다른 숫자가
정확히 `K` 만큼인 것들의 개수를 구하는 문제이다.

서로 다른 숫자가 정확히 `K` 만큼인 subarray 들의 개수를 구하는 것은
어렵다. 그러나 최대 `K` 만큼인 subarray 들의 개수를 구하는 것은 쉽다.

최대 `K` 만큼인 subarray 들의 개수를 구하는 부분문제를
`cntWithMostK(vector<int>& A, int K)` 라고 하자. 그러면
`cntWithMost(A, K) - cntWithMostK(A, K-1)` 이 답이다.

이제 `cntWithMost(A, K)` 를 구현해 보자. 예를 들어 `A = [1,2,1,2,3], K
= 2` 인 경우를 살펴보자. `unordered_map<int, int> cnt` 를 선언하여
`{number, count of the number}` 를 저장한다. `int i, j` 를 선언하여
윈도우를 움직인다. 서로 다른 수의 개수가 최대 `K` 인 경우 subarray 의
개수는 `j - i + 1` 이다. 이것을 `ans` 에 더한다. 모든 반복이 끝나면 
`ans` 가 곧 답이다.

한편 `A = [1, 2, 1, 2, 3]` 인 경우 `K` 와 상관없이 `j` 위치에 따른
subarray 의 개수는 `j - i + 1` 임을 이해하자.

```
     i            i            i           i
  A: 1 2 1 2 3    1 2 1 2 3    1 2 1 2 3   1 2 1 2 3
     j              j              j             j
cnt: 1            3            6           10
     (1)          (2)          (1)         (2)
                  (1 2)        (2 1)       (1 2)
                               (1 2 1)     (2 1 2)
                                           (1 2 1 2)
```

마지막으로 `A = [1 2 1 2 3], K = 2` 인 경우 풀이과정을 살펴보자.  먼저
`cntWithMostK(A, K)` 의 풀이과정은 다음과 같다.

```
  K: 2            1            0            0
                  i            i            i
  A: 1 2 1 2 3    1 2 1 2 3    1 2 1 2 3    1 2 1 2 3
                  j              j              j
cnt:              1            1 2          1 2
                  1            1 1          2 1
ans: 0            1            3            6

  K: 0            0            
     i                  i      
  A: 1 2 1 2 3    1 2 1 2 3    
           j              j    
cnt: 1 2          1 2 3        
     2 2          0 1 1        
ans: 10           12             
```

다음은 `cntWithMostK(A, K-1)` 의 풀이과정이다.

```
  K: 1            0            0            0
                  i              i              i
  A: 1 2 1 2 3    1 2 1 2 3    1 2 1 2 3    1 2 1 2 3
                  j              j              j
cnt:              1            1 2          1 2
                  1            0 1          1 0
ans: 0            1            2            3

  K: 0            0            
           i              i  
  A: 1 2 1 2 3    1 2 1 2 3    
           j              j    
cnt: 1 2          1 2 3        
     0 1          0 0 1        
ans: 4            5            
```

따라서 `12 - 5 = 7` 이 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [python3](a.py)
* [go](a.go)
* [ES6](a.js)

# Complexity

```
O(N) O(N)
```
