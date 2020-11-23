# Problem

[Number of Valid Subarrays](https://leetcode.com/problems/number-of-valid-subarrays/)

# Idea

수열 `V[]` 가 주어진다. 가장 왼쪽의 숫자가 다른 숫자들보다 작거나 같은
부분수열의 개수를 구하는 문제이다.

스택을 이용하면 선형시간으로 해결할 수 있다.

먼저 스택 `stack<int> stck` 를 선언한다.  인덱스 `i` 를 이용하여
처음부터 끝까지 순회하면서 `stck` 를 단조증가의 상태를 유지하자. `i`
가 이동할 때 마다 `stck.size()` 를 누적하여 더하면 곧 답이된다.

다음은 `V[] = (1, 4, 2, 5, 3)` 의 답을 구하는 과정이다.  `stck` 의 각
원소부터 `V[i]` 까지 모은 숫자들이 부분수열이 된다.

```
                i             i              i
V: 1 4 2 5 3    1 4 2 5 3   1 4 2 5 3    1 4 2 5 3
s:              1           1 4          1 2
r: 0            1           3            5

         i              i    
V: 1 4 2 5 3    1 4 2 5 3    
s: 1 2 5        1 2 3            
r: 8            11              
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
