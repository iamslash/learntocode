# Problem

[Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/)

# Idea

수열 `A[]` 가 주어지면 `i < j && A[i] <= A[j]` 를 만족하는 최대의 `j -
i` 를 구하는 문제이다.

monotone descreasing stack 을 사용하여 해결한다. 그리고 `int ans = 0`
를 선언하여 `j - i` 의 최대값을 저장한다.

스택 `stack<int> stck` 를 선언하여 `A[i]` 가 단조 감소하도록 인덱스
`i` 를 스택에 저장한다. 스택을 채웠으면 `A[i]` 를 거꾸로 순회하면서
`A[stck.top()] <= A[i]` 를 만족할 때 마다 `ans` 를 갱신하고
`stck.pop()` 를 수행한다. 이때 `i <= ans` 인 경우는 고려할 필요가
없다.

다음은 `A = 6 0 8 2 1 5` 의 풀이과정이다.

```
   A: 6 0 8 2 1 5    6 0 8 2 1 5    6 0 8 2 1 5    6 0 8 2 1 5
      i                i                i                i
stck: 0              0 1            0 1
 ans: 

   A: 6 0 8 2 1 5    6 0 8 2 1 5    
              i                i    
stck: 0 1            0 1
 ans:

   A: 6 0 8 2 1 5     
                i    
stck: 0               
 ans: 4           
```
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
