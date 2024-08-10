- [Problem](#problem)
- [Sort](#sort)
  - [Idea](#idea)
  - [Implementation](#implementation)
  - [Complexity](#complexity)
- [Heap](#heap)
  - [Idea](#idea-1)
  - [Implementation](#implementation-1)
  - [Complexity](#complexity-1)
- [Quick Select](#quick-select)
  - [Idea](#idea-2)
  - [Implementation](#implementation-2)
  - [Complexity](#complexity-2)

----

# Problem

[Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

수열 `nums[]`, 숫자 `k` 가 주어진다. `nums[]` 의 숫자들중 `k` 번째로 큰 숫자를 구하라.

# Sort

## Idea

`nums[]` 를 오름차순으로 정렬한다. `nums[n-k]` 가 답이다.

## Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)
* [python3](a.py)
* [go](a.go)
* [kotlin](MainApp.kt)

## Complexity

```
O(NlgN) O(1)
```

# Heap

## Idea

정렬의 대상을 줄이면 시간 복잡도를 개선할 수 있다. `PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a, b) -> a - b)` 를 선언한다. 이제 `pq.peek()` 는 가장 작은 수가 저장된다. 모든 숫자들을 `pq` 에 하나씩 삽입한다. 이때 `pq.size()` 가 `k` 보다 크다면 `pq` 에서 하나 제거해도 된다.

모든 반복을 마치면 `pq.poll()` 이 답이다. 

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(NlgK) O(1)
```

# Quick Select

## Idea

역시 정렬의 대상을 줄이면서 답을 찾는 방식이다. 정렬의 대상을 절반씩 줄여가면서 `n - k` 번째 작은 수를 찾는다.

[Quick Select](/fundamentals/search/quickselect/README.md) 를 참고하자.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(NlgN) O(lgN)
```
