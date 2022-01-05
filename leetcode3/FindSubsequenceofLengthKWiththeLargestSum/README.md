# Problem

[Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)

수열 `nums[]`, 숫자 `k` 가 주어진다. 합이 최대가 되는 `k` 크기의
subsequence 를 구하라.

# Idea

`PriorityQueue<Integer> pq` 를 선언하고 `nums[]` 의 인덱스를
저장한다. 꼭대기값은 `nums[i]` 의 최소값이다. `nums[]` 를 모두
삽입한다. `pq` 의 크기는 `k` 보다 작거나 같다.

`pq` 를 꺼내 인덱스의 오름차순으로 정렬한다. 그것이 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
