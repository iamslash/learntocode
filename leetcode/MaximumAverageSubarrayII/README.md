# Problem

[Maximum Average Subarray II](https://leetcode.com/problems/maximum-average-subarray-ii/)

# Idea

수열 `V` 와 숫자 `k` 가 주어지면 개수가 `k` 보다 크거나 같고 평균이 가장 큰 
`V` 의 연속된 부분수열의 평균값 `maxavg` 을 구하는 문제이다.

예를 들어 `V = (1, 12, -5, -6, 50, 3), k = 4` 인 경우를 살펴보자.

```
i        j
1 12 -5 -6 50 3

k = 4
avg of V[0..3]: 0.5
avg of V[1..4]: 12.75
avg of V[2..5]: 10.5

k = 5
avg of V[0..4]: 10.4
avg of V[1..5]: 10.8

k = 6
avg of V[0..5]: 9.16667

maxavg: 12.75
```

`maxavg` 는 `V` 의 최소값 `minval` 과 최대값 `maxval` 사이에
존재한다. 따라서 인덱스 `i, j (j - i + 1 >= k)` 에 대하여 `(V[i] -
maxval) + (V[i+1] - maxval) + ... + (V[j] - maxval) <= 0` 이다.

`lftavg = minval, rgtavg = maxval, midavg` 를 선언하고 `rgtavg -
lftavg > 0.00001` 동안 `midavg` 를 적절히 변경하면서 binary search
하면 `maxavg` 를 찾아낼 수 있다.

`while (lftavg + 0.00001 > rgtavg)` 동안 다음을 반복한다.

0. `midavg = (lftavg + rgtavg) / 2`
1. 인덱스 `i, j (j - i + 1 >= k)` 에 대하여 `(V[i] - midavg) +
   (V[i+1] - midavg) + ... + (V[j] - midavg) > 0` 이면 `maxavg <
   rgtavg` 이므로 `rgtavg = midavg` 한다.
2. 인덱스 `i, j (j - i + 1 >= k)` 에 대하여 `(V[i] - midavg) +
   (V[i+1] - midavg) + ... + (V[j] - midavg) <= 0` 이면 `maxavg >
   lftavg` 이므로 `lftavg = midavg` 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
