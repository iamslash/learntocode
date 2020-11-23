# Problem

수열 `A[]` 가 주어진다. 부분수열들 중 합이 `K` 보다 작거나 같은 것들 중
최대를 구하라.

# Idea

`set<int> psSet` 를 선언하여 `A[]` 의 부분합을 저장한다. 기본 값을
위해 `psSet.insert(0)` 을 수행한다. `int cum` 을 선언하여 `A[i]` 까지
합을 더한다.  `int ans` 을 선언하여 답을 저장한다.

인덱스 `i` 를 선언하여 `A` 를 처음부터 끝까지 순회하며 다음을
반복한다.

* `cum += A[i]` 를 수행한다.
* 이제 `cum - K` 의 lower_bound 를 `psSet` 에서 검색한다. 
  * `it` 가 발견되었다면 `K` 보다 작은 부분수열의 합이 존재한다는
    의미이다. `ans` 가 최대가 되도록 업데이트한다. `ans = max(ans,
    cum-*it)` 를 수행한다.
  * `it` 가 발견되지 않았다면 `K` 보다 작은 부분수열의 합은 없다는 의미이다.
* 새로운 부분수열의 합이 만들어 졌으므로 `psSet.insert(cum)` 를 수행한다.
  
모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
