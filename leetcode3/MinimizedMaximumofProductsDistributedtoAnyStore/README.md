# Problem

[Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)

숫자 `n` 과 수열 `quantities[]` 가 주어진다. `n` 개의 상점이 있고
`len(quantities)` 만큼의 상품이 있다. `quantities[i]` 는 `i` 상품의 개수를
의미한다. 상품을 상점에 공평하게 나눠주자. 하나의 상점에 `i` 상품 한 종류만 줄
수 있다. 그 개수는 `[1..quantities[i]]` 이다. 상점이 가진 상품 개수의 최대값이
최소가 되도록 하라. 그리고 상품 개수의 최대값을 구하라.

# Idea

상품개수의 최대 값을 `maxCnt` 라고 해보자. 다음과 같은 규칙을 발견할 수 있다.

```
int cnt = 0;
for (qty in quantities) {
  cnt += (qty + (maxCnt - 1)) / maxCnt
}

cnt is same with maxCnt
```

[binary search](/fundamentals/search/binarysearch/README.md) 로 해결할 만 하다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(1)
```
