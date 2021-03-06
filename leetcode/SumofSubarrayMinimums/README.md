# Problem

[Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/)

# Idea

수열 `A` 가 주어진다. 모든 부분수열의 최소 값들을 더한 것을
구하는 문제이다.

예를 들어 `A = 3 1 2 4` 의 경우 인덱스 `i` 를 이용하여
순회할 때 다음과 같이 부분수열을 만들어 낼 수 있다.

```
0: {3}
1: {3 1} {1}
2: {3 1 2} {1 2} {2}
3: {3 1 2 4} {1 2 4} {2 4} {4}
```

각 부분 수열의 최소 값은 다음과 같다.

```
0: 3
1: 1 1
2: 1 1 2
3: 1 1 2 4
```

`A[i]` 단계에서 만들어진 부분 수열의 최소값들의 합을 `S[i]`
라고 하자. `S[i]` 는 `S[i-1]` 를 이용하여 구할 수 있다. 
특히 `A[i]` 가 지금껏 등장한 값들 중 가장 크다면 `S[i] = S[i-1] + A[i]` 
이다.

그렇다면 이번에는 `A[i]` 가 기존의 값들 보다 작은 경우를
처리하기 위해 monotone increasing stack 을 하나 도입해 보자.
`stack<pair<int, int>> stck` 를 선언하여 `{value of A[i] : count of A[i]}`
을 저장한다. 다음은 `A = 3 1 2 4 1` 의 경우 처리과정이다.

| i | A[i] | subarrays                                         | min num   | dot prod        | min sum | stack |
|:--|:-----|:--------------------------------------------------|:----------|:----------------|:--------|:------|
| 0 | 3    | {3}                                               | 3         | `3*1`           | 3       | {3:1} |
| 1 | 1    | {3, 1} {1}                                        | 1 1       | `3 - 3*1 + 1*2` | 5       | {1:2} |
| 2 | 2    | {3, 1, 2} {1, 2} {2}                              | 1 1 2     | `2 + 2*1`       | 9       | {1:2} {2:1} |
| 3 | 4    | {3, 1, 2, 4} {1, 2, 4} {2, 4} {4}                 | 1 1 2 4   | `4 + 4*1`       | 17      | {1:2} {2:1} {4:1} |
| 4 | 1    | {3, 1, 2, 4,1 } {1, 2, 4, 1} {2, 4, 1} {4, 1} {1} | 1 1 1 1 1 | `8 - 4*1 - 2*1 + 1*3` | 22 | {1:5} |

`A[]` 를 순회하면서 `ans` 에 `dot product` 를 더하는 방식이다. 
이때 `A[i]` 값이 `stack` 의 값들 보다 작으면
`dot product` 에서 예전에 더했던 값을 뺀다.
이때 뺀 것들의 개수를 `x` 라 하면
`dot product += A[i] * (x+1)` 를 수행한다.

위의 표를 기반으로 알고리즘을 생각해 보자.
인덱스 `i` 를 이용하여 `A` 를 순회하면서 다음을 반복한다.

0. `int cnt = 1` 를 수행한다.
1. `stck.size() && stck.top().first >= A[i]` 인 동안 다음을 반복한다.
  0. `stck` 에서 하나 제거한 것을 `pr` 이라 하자.
  1.  `cnt += pr.second` 를 수행한다.
  2.  `dot -= pr.first * pr.second` 를 수행한다.
2. `stck` 에 `{A[i], cnt}` 를 삽입한다. 이제 `stck` 는 monotone increasing 이다.
3. `dot += A[j] * cnt`
4. `ans = (ans + dot) % MOD`

다음은 `A = 3 1 2 4` 의 경우 풀이과정이다.

```
                 i            i            i            i
   A: 3 1 2 4    3 1 2 4    3 1 2 4    3 1 2 4    3 1 2 4
stck:            3          1          1 2        1 2 4  
                 1          2          2 1        2 1 1
 cnt: 1          1          2          1          1
 dot: 0          3          2          4          8
 ans: 0          3          5          9          17
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```