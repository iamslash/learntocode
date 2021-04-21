# Problem

> [Maximum XOR for Each Query](https://leetcode.com/problems/maximum-xor-for-each-query/)

수열 `nums[]` 와 숫자 `maxBit` 가 주어진다. `nums[]` 와 같은 길이의
`ans[]` 를 선언한다. 인덱스 `i` 를 `[0..n)` 만큼 순회하면서 다음을
반복한다.

* `k < 2^maxBit` 를 만족하는 `k` 를 찾는다. 또한 `num[0] XOR nums[1]
  XOR ... XOR nums[nums.length-1] XOR k` 가 최대가 되야 한다. 
* `k` 를 `ans[i]` 에 저장한다.
* `i` 를 하나 증가하고 `nums[]` 의 마지막 원소를 제거한다.

모든 반복을 마친 `ans[]` 를 구하라.

# Idea

`num[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k` 가 최대가
되는 값은 `(1 << k) - 1` 와 같다. 또한 `k` 값은 `i` 가 증가할 때 마다 계속
바뀌는 값임을 유의하자.

또한 `XOR` 은 다음과 같은 성질이 있다.

```
      a XOR b = c
a XOR a XOR b = c XOR a
            b = c XOR a                       
```

예를 들어 `nums = [0,1,1,3], maxBit = 2` 의 경우를 살펴보자.  최대
값은 `(1 << 2) - 1 = 3` 이다.

```
0 ^ 1 ^ 1 ^ 3 ^ k_0 = 3    k_0: 0
    0 ^ 1 ^ 1 ^ k_1 = 3    k_1: 3
        0 ^ 1 ^ k_2 = 3    k_2: 2
            0 ^ k_3 = 3    k_3: 3


                k_0 = 3 ^ 0 ^ 1 ^ 1 ^ 3
                k_1 = 3 ^ 0 ^ 1 ^ 1
                k_2 = 3 ^ 0 ^ 1 
                k_3 = 3 ^ 0
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
