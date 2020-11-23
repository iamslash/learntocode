# Problem

[Range Sum of Sorted Subarray Sums](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/)

수열 `A[]`, 숫자 `n, left, right` 가 주어진다. `A[]` 의 subarray 들의 합을
모아서 수열 `B` 만들고 정렬하자. `B[left..right]` 영역의 합을 구하라.

# Idea

`priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq`
를 선언하고 `{A[i], i+1}` 를 삽입한다. `pq` 는 이미 정렬되어 있다.

`A[]` 의 모든 수는 positivie number 이다. `pq` 에서 하나 꺼내어 `pr` 이라고 하자.
`pr.first` 와 `A[pr.second+1]` 를 더하면 새로운 subarray 를 만들 수 있다.
이것을 다시 `pq` 에 삽입한다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
