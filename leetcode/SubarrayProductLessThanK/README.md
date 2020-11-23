# Problem

* [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/)

# Idea

수열 `V` 와 숫자 `K` 가 주어진다. `V` 의 부분 수열중 합이 
`K` 보다 작은 것들의 수를 구하는 문제이다.

two pointers 를 이용하여 해결한다.

두개의 인덱스 `i, j` 가 서로 인덱스 0 을 가지고 있다고 해보자.
이때 `j` 가 하나씩 늘어날 때 마다 부분집합의 개수가 `j-i+1` 만큼 늘어나는
것을 알 수 있다.

```      
          i          i             i           i  
          j            j             j             j
      V: 10 5 2 6   10 5 2 6    10 5 2 6    10 5 2 6
subsets: (10)       (10 5)        (5 2)       (5 2 6)
                       (5)          (2)         (2 6)
                                                  (6)
```

`j` 를 0 부터 `V.size()` 만큼 순회하면서 부분집합의 개수를 구한다. 

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
