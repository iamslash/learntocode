# Problem

[Greatest Sum Divisible by Three](https://leetcode.com/problems/greatest-sum-divisible-by-three/)

# Idea

수열 `A[]` 가 주어진다. 모두 합했을 때 3 으로 나누어 떨어지는 수열의 합을 구하라.

`C[]` 를 선언하여 `C[i]` 에 3 으로 나누었을 때 나머지가 `i` 인 최대
합을 저장한다.  인덱스 `i` 를 이용하여 `A` 를 처음부터 끝까지 순회하며
다음을 반복한다.

* `C` 를 `T` 에 복사한다. 그리고 인덱스 `j` 를 이용하여 `T` 를
  순회하며 다음을 반복한다.
  * `sum = A[i] + T[j]` 는 지금까지 수열의 합중 최대이다. `C[sum%3]`
    를 업데이트한다.
    
모든 반복을 마치면 `C[0]` 이 답이다.

`K` 로 나누어 떨어지는 수열의 합도 수월히 구할 수 있다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
