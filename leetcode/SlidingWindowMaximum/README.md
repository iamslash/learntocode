# Problem

[Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

수열 `nums` 와 숫자 `k` 가 주어진다. `k` 만큼의 윈도우를 만들어서
`nums` 를 순회한다. 한칸 씩 이동할 때 마다 윈도우안의 최대값들을
모아보자. 그리고 그 최대값들의 모음을 구하라.

# Idea

예를 들어 `nums = [1,3,-1,-3,5,3,6,7], k = 3` 인 경우를
살펴보자.

```
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```
따라서 답은 `[3, 3, 5, 5, 6, 7]` 이다.

`vector<int> ans` 를 선언하여 답을 저장한다. `deque<int> deq` 를
선언하여 인덱스를 저장한다. 그리고 윈도우안의 숫자들을 내림차순으로
유지한다. 그렇다면 `deq[0]` 이 항상 최대값이 된다.

인덱스 `i` 를 `[0,n)` 동안 순회하면서 다음을 반복한다.

* `deq.size() > 0 && deq.back() < nums[i]` 동안 `deq.pop_back()` 를
  수행한다. 그리고 `deq.push_back(i)` 를 수행한다. `deq` 는
  내림차순으로 정렬된다.
* `deq.size() > 0` 이면 `ans` 에 `nums[deq.front()]` 를 삽입한다.
* `deq.size() > 0 && deq.front() <= i - K + 1` 인 동안
  `deq.pop_front()` 를 수행한다. 다음 삽입을 위해 `deq` 의 크기를
  `k-1` 개로 유지한다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(N) O(N)
```
