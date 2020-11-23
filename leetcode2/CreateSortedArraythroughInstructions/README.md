# Problem

[Create Sorted Array through Instructions](https://leetcode.com/problems/create-sorted-array-through-instructions/)

수열 `I[]` 가 주어진다. `I[i]` 를 순서대로 `A[]` 에 삽입한다.  이때
`I[i]` 를 삽입할 때 마다 `A[]` 의 숫자들 중 `I[i]` 보다 작은 수들의
개수와 `I[i]` 보다 큰 수들의 개수중 더 작은 것을 `I[i]` 의 비용이라고
하자. `I[]` 의 모든 수를 `A[]` 로 모두 옯겼을 때 그 비용의 합을
구하라.

# Idea

[fenwick tree](/fundamentals/tree/fenwick/README.md) 를 이용하면 쉽게 해결할 수 있다. `vector<int> data(100001)` 를 선언한다. `I[x]` 가 `A[]` 에 삽입되면 `data[x]` 에 `1` 를 저장한다.

`int n = I.size()` 를 선언하자. `int ans = 0` 를 선언하여 답을 저장한다. 인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `I[i]` 보다 작은 수들의 개수는 `sum(I[i] - 1)` 이다.
* `I[i]` 보다 큰 수들의 개수는 `i - sum(I[i])` 이다.
* `ans = (ans + min(sum(I[i] - 1), i - sum(I[i])) % MOD` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [py3](a.py)

# Complexity

```
O(NlgN) O(N)
```
