# Problem

[Length of Longest Fibonacci Subsequence](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)

# Idea

숫자의 모음 `A[]` 가 주어진다. subsequences 중 피보나치 수열과 
비슷한 것 중 가장 긴 것을 구하는 문제이다.

먼저 피보나치를 구성하는 최소 3 가지 숫자를 생각해보자. 이것을 a, b, c
(a < b < c)라고 하자. `A[]` 를 이중 반복을 하면서 c 를 먼저 정하고 b
를 정한다. a = c - b 라고 할 수 있다. 그러나 a 라는 숫자가 `A[]` 에
있는지 확인해야 한다.

따라서, `unordered_map<int, int> idx` 를 선언하여 `{A[i], i}` 가
저장되어 있으면 좋을 것 같다. `idx[c-b].count > 0` 이면 `a` 는 `A[]`
에 존재하는 것이다.

dynamic programming 을 위해 캐시 `unordered_map<int, int> maxlen` 을
선언하고 `{피보나치 유사수열 숫자 중 c 의 인덱스, 피보나치 유사수열의
최대 길이}` 를 저장한다. 맵을 사용하면 이차원 배열을 사용하는 것보다
공간복잡도를 절약할 수 있다. 또한 `n = A.size()` 이다.

이제 `a, b, c` 가 존재하면 그 때의 인덱스를 `i, j, k` 라고 해보자.
`maxlen[j * n + k] = maxlen[i * n + j] + 1` 임은 당연하다.
`maxlen[j * n + k]` 는 2 가 빠져있다. `c` 가 처음 발견되었을 때
`maxlen[i * n + j]` 가 0 이기 때문이다. 따라서 최대값은 `ans =
max(and, maxlen[j * n + k] + 2)` 를 이용한다.

모든 반복이 끝나면 `ans` 를 확인한다. 앞서 언급하였다 싶이 `max[j *
n + k]` 는 2 이하일 수 있다. 따라서 `ans >= 3` 이면 `ans` 가 답이고
그렇지 않으면 `0` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
