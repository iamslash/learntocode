# Problem

* [Continuous Subarray Sum @ leetcode](https://leetcode.com/problems/continuous-subarray-sum/)

# Idea

숫자들의 배열이 주어졌을 때 `i` 인덱스의 숫자를 `a[i]` 이라고 하자.
`[0, i]` 영역 숫자들의 합을 `S[i]` 이라고 하자.
`[i, j]` 영역 숫자들의 합을 `T[i,j]` 이라고 하자.
`T[i,j] = S[j] - S[i-1]` 이다.
이때 `T[i,j]` 가 `k` 로 나누어 떨어진다는 말은
`S[j] - S[i-1]` 이 `k` 로 나누어 떨어진다는 말과 같다.
즉 `S[j] ≡ S[i-1] mod k` 이다.

`a[]` 를 처음부터 순회하면서 `S[i] % k` 가 이전에 등장했었다면
참이다. 이때 `a` 는 최소 두개이어야 하기 때문에 `T[i,j]` 에서 
`i + 2 <= j` 인 것을 유의하자.

# Implementation

* [c++11](a.cpp)

# Complexity

```
C(N) C(N)
```
