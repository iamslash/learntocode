# Problem

[Decode XORed Permutation](https://leetcode.com/problems/decode-xored-permutation/)

수열 `encoded[]` 가 주어진다. 원래의 수 `perm[]` 가 있다. `perm[]`
크기는 홀수 이고 개수는 `encoded[]` 보다 하나 크다. 그리고 `encoded[i]
= perm[i] XOR perm[i + 1]` 이다. `perm[]` 을 구하라.

# Idea

예를 들어 `encoded = [3,1]` 의 경우를 살펴보자.

```
encoded:   3 1
   perm: 1 2 3
   
   perm: a0    a1    a2    ...       a_n-1 
encoded:       a0^a1 a1^a2 a2^a3 ... a_n-2^a_n-1
    all: a0^a1^a2^...^a_n-1
     a0: all^(a1^a2)^(a3^a4)^...^(a_n-2^a_n-1)
   perm: a0 a0^(a0^a1) a1^(a1^a2) ... a_n-2^(a_n-2^a_n-1)
```

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(N)
```

# Similar Questions

* [Decode XORed Array](https://leetcode.com/problems/decode-xored-array/)
