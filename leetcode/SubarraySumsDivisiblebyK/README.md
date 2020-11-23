# Problem

[Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

# References

* [(Python) Concise Explanation and Proof @ leetcode](https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/310767/(Python)-Concise-Explanation-and-Proof)

# Idea

수열 `A[]` 와 숫자 `K` 가 주어진다. `A` 의 subarray 들 중 합을 `K` 로
나누었을 때 나누어 떨어지는 것들의 개수를 구하는 문제이다.

`i < j` 인 경우 `sum(i, j) = A[i] + A[i+1] + .. + A[j-1]` 라고 하자.
그렇다면 `sum(i, j) % K == 0` 이면 `sum(i) % K == sum(j) % K` 이다.
다음은 그 증명이다.

```
sum(i, j) = sum(0, j) - sum(0, i)

sum(0, j) - sum(0, i) = n * K (n is natural number)
sum(0, i)     = sum(0, j) - n * K
sum(0, i) % K = (sum(0, j) - n * K) % K
sum(0, i) % K = (sum(0, j) % K - (n * K) %K)
sum(0, i) % K = sum(0, j) % K
```

`i < j` 인 경우 `A[]` 의 subarray 들의 합의 개수는 `sum(i, j)` 의 개수와 같다. 곧 `A[]` 의 subarray 들 중 합이 `K` 로 나누어 떨어지는 것들의 개수는 `sum(i, j)` 들 중 합이 `K` 로 나누어 떨어지는 것의 개수와 같다. 결국 `sum(0, i) % K = sum(0, j) % K` 인 것들의 개수를 구하면 곧 답이다.

따라서 인덱스 `k` 를 `[0..j)` 동안 하나씩 늘려가면서 `sum(0, k) % K = remain` 를 `unordered_map<int, int> remainump = {{0, 1}}` 에 저장한다. 새로운 `k` 에 대해 `ans += remainump[remain]` 를 수행한다. 그리고 다음을 위해 `remainump[remain]++` 를 수행한다.

예를 들어 `A = 4 5 0 -2 -3 1, K = 5` 인 경우 다음과 같이 살펴보자.

| A[i] | subarray                                                       | prefix | ans | cnt               |
|------|----------------------------------------------------------------|--------|-----|-------------------|
|      |                                                                | 0      | 0   | `{0:1}`           |
| 4    | `4`                                                            | 4      | 0   | `{0:1, 4:1}`      |
| 5    | `4 5` `5`                                                      | 4      | 1   | `{0:1, 4:2}`      |
| 0    | `4 5 0` `5 0` `0`                                              | 4      | 3   | `{0:1, 4:3}`      |
| -2   | `4 5 0 -2` `5 0 -2` `0 -2` `-2`                                | 2      | 3   | `{0:1, 2:1, 4:3}` |
| -3   | `4 5 0 -2 -3` `5 0 -2 -3` `0 -2 -3` `-2 -3` `-3`               | 4      | 6   | `{0:1, 2:1, 4:4}` |
| 1    | `4 5 0 -2 -3 1` `5 0 -2 -3 1` `0 -2 -3 1` `-2 -3 1` `-3 1` `1` | 0      | 7   | `{0:2, 2:1, 4:4}` |

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
