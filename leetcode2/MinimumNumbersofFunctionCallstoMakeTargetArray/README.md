# Problem

[Minimum Numbers of Function Calls to Make Target Array](https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/)

수열 `A[]` 가 주어진다. 허용된 연산은 두가지가 있다. `A[i]` 를 하나
증가하거나 `A[0..n-1] = A[0..n-1]*2` 를 할 수 있다. `n` 개의 0 으로
구성된 수열이 있을 때 `A[]` 와 같기 위해 필요한 연산의 수를 구하라.

# Idea

거꾸로 생각해 보자. 즉, `A[]` 에서 `n` 개의 0 으로 구성된 수열로
변환해 보자.

예를 들어, `A = [1, 5]` 를 살펴보자.

`A[i]` 가 홀수이면 무조건 하나 감소한다. 그리고 짝수가 되면 left most
bit 의 위치만큼 나눠야 한다. 짝수를 나누는 연산은 모든 원소에 대해서
해야 한다. `maxLen` 을 선언하여 가장 큰 위치를 저장하자. `ans` 를
선언하고 답을 저장한다. 홀수를 만날 때 마다 `ans++` 한다.  모든 반복을
마치면 `ans + maxLen - 1` 이 답이다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
