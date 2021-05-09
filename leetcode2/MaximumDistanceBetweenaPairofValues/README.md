# Problem

> [Maximum Distance Between a Pair of Values](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)

수열 `A[], B[]` 가 주어진다. `i` 를 `A[]` 의 인덱스, `j` 를 `B[]` 의
인덱스라고 하자. 다음을 만족하는 `i, j` 에 대해 최대 거리 `max(j-i)`
를 구하라.

* `i <= j`
* `A[i] <= B[j]`

# Idea

예를 들어 `A = [55,30,5,4,2], B = [100,20,10,10,5]` 의 경우를
살펴보자.

```
                 i
      A:  55 30  5  4 2
      B: 100 20 10 10 5
                        j
maxDist: 2           
```

따라서 답은 `2` 이다. two pointers 로 해결할 만 하다.

`int i = 0, j = 0, ans = 0` 를 선언하여 두 인덱스와 답을
저장한다. `int n = A.length, int m = B.length` 를 선언하여 각각 `A[],
B[]` 의 길이를 저장한다.

`i < n && j < m` 인 동안 다음을 반복한다.

* `A[i] > B[j]` 이면 `i` 를 하나 증가한다.
* `A[i] <= B[j]` 이면 해당 구간이 나타났다. `ans` 를 업데이트
  한다. 즉, `ans = max(ans, j - i)` 를 수행한다. 그리고 `j` 를 하나
  증가한다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
