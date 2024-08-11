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
- [Counting Sort](#counting-sort)
  - [Idea](#idea-3)
  - [Implementation](#implementation-3)
  - [Complexity](#complexity-3)

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
O(N) O(lgN)
```

# Counting Sort

## Idea

[Counting Sort](/fundamentals/sort/countingsort/README.md)는 특정 범위 내의 정수 데이터를 효율적으로 정렬하는 알고리즘입니다. 주어진 데이터의 값이 비교적 작은 범위에 걸쳐 있을 때 특히 유용합니다. 이 알고리즘은 데이터의 개수를 세는 배열(count 배열)을 사용하여 정렬을 수행합니다.

이 구현에서는 정수 배열에서 k번째 큰 값을 찾기 위해 [Counting Sort](/fundamentals/sort/countingsort/README.md)의 아이디어를 활용합니다. 구체적으로 다음과 같은 아이디어로 동작합니다:

- 주어진 숫자들의 범위가 -10,000에서 10,000이므로, 각 값의 빈도를 저장할 수 있는 20,001개의 버킷을 준비합니다.
- 각 숫자를 해당하는 버킷에 넣기 위해, 숫자의 값을 버킷 인덱스로 매핑합니다. 이를 위해 음수 값을 처리할 수 있도록 오프셋을 추가합니다.
- 각 버킷에 숫자가 몇 번 나오는지를 세어 저장합니다.
- 가장 큰 값부터 시작하여 k번째 큰 값을 찾기 위해, 버킷을 역순으로 순회하며 누적 개수를 세어 나갑니다.
- 누적 개수가 k 이상이 되면 해당 값이 k번째 큰 값입니다.

이 알고리즘은 데이터의 범위가 제한적일 때 효율적으로 동작합니다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N) O(N)
```
