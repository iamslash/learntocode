# Problem

[Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

# Idea

숫자 `s` 와 수열 `V[]` 가 주어진다. `v[]` 의 부분수열중 합이 `s` 보다 크거나 
같은 것들 중 가장 길이가 적은 것을 구하는 문제이다.

sliding window 전략을 이용한다. 인덱스 `i, j` 를 이용하여 `V[]` 를
순회한다.  `[i, j]` 가 구성하는 영역을 window 라 하고 영역의 합을 `sum` 
에 저장하자.

`sum >= s` 이면 `V[i]` 를 `sum` 에서 제거한다. `sum < s` 이면 `V[j]`
를 `sum` 에 더한다. window 를 오른쪽으로 이동하다 보면 `minlen` 을
구할 수 있다.

다음은 `s = 7, V = (2, 3, 1, 2, 4, 3)` 의 예이다.

```
     i                  i                   i          
  V: 2 3 1 2 4 3     V: 2 3 1 2 4 3      V: 2 3 1 2 4 3
     j                    j                     j          
sum: 0             sum: 2              sum: 5          
len: INT_MAX       len: INT_MAX        len: INT_MAX    

     i                  i                     i          
  V: 2 3 1 2 4 3     V: 2 3 1 2 4 3      V: 2 3 1 2 4 3
           j                    j                   j          
sum: 6             sum: 8              sum: 6         
len: INT_MAX       len: INT_MAX        len: INT_MAX    

       i                    i                     i          
  V: 2 3 1 2 4 3     V: 2 3 1 2 4 3      V: 2 3 1 2 4 3
               j                  j                     j          
sum: 10             sum: 7              sum: 9         
len: INT_MAX       len: 3               len: 3    

             i    
  V: 2 3 1 2 4 3  
                 j
sum: 7            
len: 2            
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
