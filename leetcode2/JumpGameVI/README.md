# Problem

* [Jump Game VI](https://leetcode.com/problems/jump-game-vi/)

수열 `A[]`, 숫자 `k` 가 주어진다. `A[i]` 에서 `A[i+1] ~ A[i+k]` 만큼 점프할 수
있다. `A[0]` 에서 출발하여 `A[n-1]` 에 도착했을 때 최대 합이 되도록 하고 그때의
최대합을 구하라.

# Iterative Dynamic Programming

## Idea

iterative dynamic programming 으로 해결할 만 하다.

`vector<int> C(n, INT_MIN)` 을 선언한다. `C[i]` 에 `A[i]` 에 도착했을 때
최대합을 저장한다. `C[0] = A[0]` 으로 초기화 한다. 

만약 `A[i+1] ~ A[i+k]` 중 첫번째 positive number 의 인덱스 `j` 를 만나면
`A[j..i+k]` 는 탐색할 필요가 없다. positive number 는 최대합을 증가시킬 테고
다음번 반복에 `A[j..i+k]` 를 방문할 수 있기 때문이다.

인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* 인덱스 `j` 를 `[i+1, min(i+k,n-1)]` 동안 순회하면서 다음을 반복한다.
  * `C[j]` 를 업데이트 한다. 즉, `C[j] = max(C[j], C[i] + A[j])` 를 수행한다.
  * `A[j] >= 0` 이면 `j+1` 이상을 방문할 이유가 없다. 반복을 중지한다.

모든 반복을 마치면 `C[n-1]` 를 리턴한다.

만약 `A[i]` 가 음수라면 monotonic decreasing deque 보다 시간복잡도가 크다.

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N) O(N)
```

# monotonic decreasing deque, sliding window

## Idea

`deque<int> deq{0}` 를 선언하여 인덱스 `i` 를 저장한다. 그리고 항상 `A[i]` 의 내림차순이 되도록 유지한다. `i` 를 방문하면서 `A[i]` 는 누적된 숫자의 합이 저장되게 된다. 따라서 별도의 cache 공간이 필요가 없다.

* 인덱스 `i` 를 선언하여 `[1..n)` 동안 순회하면서 다음을 반복한다. `i` 는 이제 방문할 인덱스를 의미하고 `deq` 은 `A[i]` 에 더할 숫자들을 의미한다.
  * `deq.size() <= k` 이어야 한다. 즉, `deq.front() + k < i` 동안 `deq.pop_front()` 를 수행한다.
  * `deq.front()` 는 `i` 에 도착할 때 더할 수 있는 가장 큰 수이다. 즉, `A[i] += A[deq.front()]` 를 수행한다.
  * `i` 를 `deq` 에 삽입해야 한다. 즉, `!deq.empty() && A[deq.back()] <= A[i])` 동안 `deq.pop_back()` 를 수행한다.
  * `deq.push_back(i)` 를 수행한다.

모든 반복을 마치면 `A.back()` 이 답이다.

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N) O(K)
```
