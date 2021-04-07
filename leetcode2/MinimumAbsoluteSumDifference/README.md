# Problem

> [Minimum Absolute Sum Difference](https://leetcode.com/problems/minimum-absolute-sum-difference/)

수열 `A[], B[]` 가 주어진다. `sum(|A[i]-B[i]|)` 을 absolute sum
difference 라고 하자. absolute sum difference 가 최소가 되도록 `A[i]`
의 숫자를 최대 1 개만 교체해 보자. 그때의 absolute sum difference 를
구하라. 답이 너무 클 수 있으므로 `ans %(10^9+7)` 을 수행하자.

# Idea

예를 들어 `nums1 = [1,7,5], nums2 = [2,3,5]` 의 경우를 살펴보자.

```
  nums1: 1 7 5
  nums2: 2 3 5
absdiff: 1 4 0
sumdiff: 5

  nums1: 1 1 5
  nums2: 2 3 5
absdiff: 1 2 0
sumdiff: 3  
```

따라서 답은 `3` 이다.

다음과 같은 변수들을 선언한다.

> * `S[]`: `A[]` 를 정렬한 배열
> * `maxdiff`: `abs(A[i]-B[i])` 와 `abs(A[j]-B[i])` 의 최대
>   차이값. `j` 는 `i` 와 교체할 인덱스이다.
> * `diffsum`: absolute sum difference
> * `MOD`: `1_000_000_0007`

`A[]` 를 정렬하여 `S[]` 에 저장한다.

이제 인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `int diff` 를 선언하여 `abs(A[i]-b[i])` 를 저장한다. 그리고
  `diffsum` 에 더한다.
* `int j` 를 선언하여 `Arrays.binarySearch(S, B[i])` 를 저장한다.
  `S[j]` 혹은 `S[j-1]` 는 `B[i]` 와 가장 가까운 값이다. `abs(S[j] -
  B[i])` 가 같은 `i` 가 여러개 존재할 수 있기 때문에 매번 binary
  search 를 해야 한다. 
* `j < 0` 이면 `B[i]` 와 같은 값이 없다는 의미이다. `j = ~j` 를
  수행한다. 절대값을 부착하고 1 을 제거한다. 예를 들어 `j == -3` 이면
  `j = 2` 를 수행하게 된다.
* `j < A.length` 이면 `B[i]` 와 같은 값이 있다는 의미이다. `maxdiff =
  max(maxdiff, diff - abs(S[j]-B[i]))` 를 수행한다.
* `j > 0` 이면 `maxdiff = max(maxdiff, diff - abs(S[j-1]-B[i]))` 를
  수행한다. `j` 는 `j = ~j` 를 통해서 바뀌었을 수 있다. `S[j]` 와
  `B[i]` 가 같은 값이라고 가정할 수 없다.

모든 반복을 마치면 `(diffsum - maxdiff) % MOD` 가 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
