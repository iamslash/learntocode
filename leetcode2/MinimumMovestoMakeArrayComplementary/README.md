# Problem

[Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)

짝수개의 수열 `nums[]` 와 숫자 `limit` 이 주어진다. `nums[]` 의 임의의
숫자를 `[1..limit]` 의 숫자로 교체할 수 있다.  `nums[]` 를
complementary 로 만들기 위한 최소 교체수를 구하라.

`A[]` 가 complementary 하다는 의미는 다음과 같다.

* 가능한 `i` 에 대하여 `A[i] + A[n-1-i]` 가 모두 같다.

예를 들어, `A = [1, 2, 3, 4]` 는 `1 + 4 = 5, 2 + 3 = 5` 이기 때문에
`A` 는 complementary 하다.

# References

* [[Python/Java] simple O(max(n, k)) method @ leetcode.discuss](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/952773/PythonJava-simple-O(max(n-k))-method)

# Idea

인덱스 `i` 를 `[0..n/2)` 동안 순회하면서 `A[i] + A[n-1-i]` 를
수행한다고 생각해 보자. `a = A[i], b = A[n-1-i]` 라고 해보자.

문제의 조건에 의해 `1 <= nums[i] <= limit <= 105` 이다.  따라서 바꿀
수 있는 `a, b` 에 대해 `a + b` 의 범위는 `[2..2*limit]` 이다.

`vector<int> delta(2 * limit + 2)` 를 선언한다. `nums[]` 를 순회하며 
`a + b` 의 모든 경우를 저장한다. 그리고 다시 `delta` 를 순회하며 최소교체수를
구하는 방식으로 생각해 본다.

다음과 같이 `a + b` 의 경우의 수를 생각해 볼 수 있다. `T` 는 `a + b`
가 만족해야할 목표값이다.

* 2 <= T < min(A, B) + 1
  * A, B 를 둘다 더 작은 값으로 만들기 위해 2 번의 교체가 필요하다.
* min(A, B) + 1 <= T < A + B
  * A, B 중 작은 값을 더 크게 만들기 위해 1 번의 교체가 필요하다.
* T = A + B
  * 이미 `T` 와 같기 때문에 교체가 필요 없다.
* A + B < T < max(A, B) + limit
  * A, B 중 큰 값을 더 작게 만들기 위해 1 번의 교체가 필요하다.
* max(A, B) + limit < T <= 2 * limit
  * A, B 를 둘다 더 큰 값으로 만들기 위해 2 번의 교체가 필요하다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(max(N, K)) O(K)
```
