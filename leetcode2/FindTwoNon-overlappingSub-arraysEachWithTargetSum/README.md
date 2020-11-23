# Problem

[Find Two Non-overlapping Sub-arrays Each With Target Sum](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)

수열 `A[]` 와 숫자 `target` 이 주어진다.  `A[]` 의 부분수열들 중 합이
`target` 인 것을 두개 고르고 그 길이가 최소가 되도록 하자.  단, 두개의
부분수열은 서로 겹치지 않아야 한다.  그 때 두 부분수열의 길이의 합을
구하라.

# Idea

예를 들어 `A = [3, 2, 2, 4, 3], target = 3` 이라고 해보자. 합이 3 인
최소길이의 부분수열은 `[3], [3]` 이다. 따라서 답은 2 이다.

`vector<int> C(n)` 를 선언한다. `C[i]` 에 `A[0..i]` 의 부분수열중 합이
`target` 이고 길이가 최소인 것의 길이를 저장한다.

`int ans` 를 선언하여 답을 저장한다. `int sum` 을 부분수열의 합을
저장한다. 두개의 인덱스 `l, r` 를 선언한다. `l, r` 를 이용하여 sliding
window 를 만든다. sliding window 의 합은 `sum` 에 저장한다. `sum ==
target` 이면 `ans` 를 업데이트한다.

인덱스 `r` 을 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `sum += A[r]` 를 수행한다.
* `l` 를 `sum > target` 인 동안 전진한다. 이때 `sum -= A[l]` 를 수행한다.
* `sum == target` 이면 `ans` 를 업데이트해야 한다.
  * 마지막 슬라이드의 영역이 `A[l..r]` 이면 그것의 길이와 `A[0..l-1]`
    영역의 최소길이 부분수열의 길이를 더하고 `ans` 와 비교한다. 그리고
    더 적은 것을 `ans` 에 다시 저장한다.
  * 즉, `ans = min(ans, C[l-1] + C[r])` 를 수행한다.
* `r > 0` 이면 `C[r]` 를 업데이트 한다.
  * `C[r]` 과 `C[r-1]` 를 비교하고 더 적은 값을 `C[r]` 에 저장한다.

모든 반복을 마치고 `ans == MAX_VAL` 이면 `-1` 를 리턴한다.  그렇지
않으면 `ans` 를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```
