# Problem

[Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/)

수열 `src[], tgt[], allow[]` 가 주어진다. `src[]` 의 인덱스가 `allow[0],
allow[1]` 인 숫자 얼마든지 서로 위치를 바꿀 수 있다.

Hamming Distance 는 두 수열 `src[]` 와 `tgt[]` 의 같은 위치의 숫자들을 살펴보고
그 값이 다른 숫자들의 개수를 의미한다.

`src[]` 의 숫자들의 위치를 `allow[]` 를 이용하여 조정해 보자. 그리고 `src[]` 와
`tgt[]` 의 Hamming Distance 를 최소화 해보자. 그때 그 최소값을 구하라.

# Idea

[Disjoint Set](/fundamentals/disjointset/unionfind/README.md) 을 이용할 만 하다.

`DisjointSet ds = new DisjointSet(allow.length)` 를 선언한다. `allow[]` 를 
순회하면서 `ds.merge(allow[0], allow[1])` 를 수행한다. 이제 인덱스 `u, v`
가 있으면 서로 같은 group 에 속하는지 알 수 있게 되었다.

`int minHam = 0` 를 선언하여 답을 저장한다.
`Map<Integer, Map<Integer, Integer>> numMap = new HashMap<>()` 를 선언하여
`{root-idx: {num-val: cnt}` 를 저장한다. `num-val` 은 문제의 조건에 의해서 중복이 가능하다.

인덱스 `i` 를 이용하여 `[0..n)` 만큼 순회하며 다음을 반복한다.

* `int num_val = src[i]` 를 수행한다.
* `int root_idx = ds.find(i)` 를 수행한다.
* `numMap` 에 `root_idx` key 가 없다면 삽입한다. 즉, `numMap.putIfAbsent(root_idx, new HashMap<>()` 를 수행한다.
* `Map<Integer, Integer> ChildMap = numMap.get(root_idx)` 를 수행한다.
* `childMap` 에 `num_val` 의 출현 횟수를 하나 증가한다. 즉, `childMap.put(num_val, childMap.getOrDefault(num_val, 0) + 1)` 를 수행한다.

인덱스 `i` 를 이용하여 `[0..n)` 만큼 순회하며 다음을 반복한다.

* `int num_val = src[i]` 를 수행한다.
* `int root_idx = ds.find(i)` 를 수행한다.
* `numMap` 에 `root_idx` key 가 없다면 삽입한다. 즉, `numMap.putIfAbsent(root_idx, new HashMap<>()` 를 수행한다.
* `Map<Integer, Integer> childMap = numMap.get(root_idx)` 를 수행한다.
* `childMap` 에 `num_val` 의 출현 횟수를 하나 증가한다. 즉, `childMap.put(num_val, childMap.getOrDefault(num_val, 0) + 1)` 를 수행한다.

인덱스 `i` 를 이용하여 `[0..n)` 만큼 순회하며 다음을 반복한다.

* `int num_val = tgt[i]` 를 수행한다.
* `int root_idx = ds.find(i)` 를 수행한다.
* `Map<Integer, Integer> childMap = numMap.get(root_idx)` 를 수행한다.
* `childMap` 에 `num_val` 이 없다면 `minHam` 을 하나 증가한다.
* `childMap` 에 `num_val` 이 있다면 `num_val` 의 출현 횟수를 하나 감소한다. 즉, `childMap.put(num_val, childMap.get(num_val) - 1)` 를 수행한다.

모든 반복을 마치면 `minHam` 이 곧 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(N)
```
