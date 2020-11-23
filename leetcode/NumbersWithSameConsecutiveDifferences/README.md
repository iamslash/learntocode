# Problem

[Numbers With Same Consecutive Differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)

# Idea

두개의 숫자 `N, K` 가 주어진다. `N` 자리수의 숫자들 중 인접한 두수의
차이가 `K` 인 숫자들을 구하는 문제이다.

backtraking 으로도 할 수 있지만 iterative 하게 접근해 보자.

`vector<int> ans = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}` 을
선언하고 `N-1` 만큼 다음을 반복한다.

* `ans` 를 인덱스 `i` 를 이용하여 순회하면서 다음을 반복한다.
  * `vector<int> tmp` 를 선언한다.
  * `ans[i]` 를 최근 숫자로 하고 새로운 숫자를 추가하여 인접한 두 수의
    차이가 `K` 인 숫자를 만들어 `tmp` 에 삽입한다. 
  * 모든 순회가 완료되면 `ans = tmp` 를 수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
