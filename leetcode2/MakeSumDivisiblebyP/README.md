# Problem

[Make Sum Divisible by P](https://leetcode.com/problems/make-sum-divisible-by-p/)

수열 `A[]`, 숫자 `P` 가 주어진다. `A[]` 에서 최소길이 subarray 를
제거하여 남은 원소들의 합이 `P` 로 나누어 떨어지게 하자. 제거해야할
subarray 의 개수를 구하라.

# Idea

`ps[]` 를 partial sum 이라고 하면 다음과 같은 수식이 성립한다. `i, j`
는 제거해야할 subarray 인덱스의 시작과 끝을 의미한다.

```
// remove a subarray to make ps[n] divisible by p
(ps[n] - (ps[i] - ps[j])) % p = 0 

                    ps[n] % p = (ps[i] - ps[j]) % p 

                    ps[j] % p = ps[i]% p - ps[n]%p
                    // Add p to make a positive number
                    ps[j] % p = (ps[i]% p - ps[n]%p + p) % p
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
