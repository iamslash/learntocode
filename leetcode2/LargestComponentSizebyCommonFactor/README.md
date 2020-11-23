# Problem

[Largest Component Size by Common Factor](https://leetcode.com/problems/largest-component-size-by-common-factor/)

수열 `A[]` 가 주어진다. `len(A)` 만큼의 node 가 있고 node 의 값은
`A[i]` 와 같다. 서로 다른 node 가 1 보다 큰 공약수가 있다면 연결할 수
있다.  node 들을 모두 연결했을 때 가장 많은 수의 node 를 갖는 comonent
를 찾고 그 node 의 개수를 리턴하라.

# Idea

예를 들어 `A = [4,6,15,35]` 의 경우를 살펴보자.

```
4 - 6 - 15 - 35
```

따라서 답은 `4` 이다.

이번에는 `A = [20, 50, 9, 63]` 의 경우를 살펴보자.

```
20 - 50  9 - 63
```

따라서 답은 `2` 이다.

`A` 를 순회하면서 가장 큰 숫자 `n` 를 찾는다.  `n+1` 크기의 Disjoint
Set 을 제작한다.

그리고 인덱스 `i` 를 이용하여 `A` 를 순회하며 다음을 반복한다.

* 인덱스 `k` 를 이용하여 `[2..sqrt(A[i])` 를 순회하며 다음을 반복한다.
  * `a % k == 0` 이면 `ds.merge(a, k), ds.merge(a, a/k)` 를 수행한다.
  
`unordered_map<int, int> ump` 를 선언하고 `A[i]` 의 부모에 소속된 node
들의 개수를 저장한다. `int ans = 1` 을 선언하여 답을 저장한다.

이제 `int a` 로 `A` 를 순회하며 다음을 반복한다.

* `ans = max(ans, ++ump[ds.find(a)])`

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
