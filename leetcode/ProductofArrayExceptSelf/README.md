# Problem

[Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

수열 `nums[]` 가 주어진다. 다음과 같은 수열 `ans[]` 을 구하라.

* `ans[i]` 는 `nums[i]` 를 제외한 다른 수들의 곱이다.

# Idea

예를 들어 `nums = [1,2,3,4]` 의 경우를 살펴보자.

```
nums:  1  2 3 4
 ans: 24 12 8 6
```

따라서 답은 `[24, 12, 8, 6]` 이다.

`/` 를 사용할 수 없다. `ans[i]` 를 구하기 위해서는 `nums[i]` 의 왼쪽
수들의 곱과 `nums[i]` 의 오른쪽 수들의 곱이 필요하다.

왼쪽 수들의 곱을 `leftProd[]` 에 저장한다. 오른쪽 수들의 곱을
`rightProd[]` 에 저장한다. `ans[i] = leftProd[i] * rightProd[i]` 이다.

`int cumPrd = 1` 를 이용하여 space complextiy 를 `O(1)` 로 해결할 수도
있다. 

- `ans[]` 를 모두 `1` 로 채운다.
- 인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.
  - `ans[i] *= cumPrd`
  - `cumPrd *= nums[i]`
- `cumPrd = 1` 로 한다.
- 인덱스 `i` 를 `(n..0]` 동안 순회하면서 다음을 반복한다.
  - `ans[i] *= cumPrd`
  - `cumPrd *= nums[i]`
- 모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
