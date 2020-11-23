# Problem

[Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/)

다음과 같은 특징을 갖는 배열을 Mountain Array 라고 하자.

* `A.length >= 3`
* 봉우리에 해당하는 인덱스 `i` 가 있을 때 `A[0] < A[1] < A[i-1] <
  A[i]`, `A[i] > A[i+1] > A[n-1]` 를 만족한다.
  
`A` 에서 `target` 에 해당하는 최소 인덱스를 구하라.

# Idea

봉우리가 하나인 모양의 그래프이다. 봉우리를 찾고 그 때의 인덱스를 `p`
라고 하자. `A[0..p]` 에서 target 에 해당하는 인덱스가 있다면 리턴한다.
`A[p..n-1]` 에서 target 에 해당하는 인덱스가 있다면 리턴한다.
모두 해당안된다면 `-1` 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
