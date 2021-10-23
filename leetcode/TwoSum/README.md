# Problem

> [Two Sum](https://leetcode.com/problems/two-sum/)

수열 `I[]` 와 숫자 `T` 가 주어진다. `I` 에서 합이 `T` 가
되는 서로다른 숫자를 구하는 문제이다.

# hash map

## Idea

맵 `ump` 를 정의하고 `I[]` 를 순회하면서 다음을 반복한다.

> * `T - I[i]` 가 `ump` 에 있으면 빙고
> * 없으면 `ump.insert({T - I[i], i})` 를 수행한다.

모든 반복을 마치면 

## Implementation

* [c++11](a.cpp)
* [python3](a.py)
* [java8](MainApp.java)

## Complexity

```
O(N) O(N)
```

# brute force

## Idea

`int dist = 1` 을 선언하고 두 수의 거리를 저장한다.  `int j = dist` 을
선언하고 두번째 수의 인덱스를 저장한다.  그렇다며 첫번째 수의 인덱스는
`j - dist` 이다. `nums[j-dist] + nums[j] == target` 이면 답이다.

java8 의 경우 hash map 방법보다 훨씬 빠르다.

## Implementation

* [c++11](a.cpp)
* [python3](a.py)
* [java8](MainApp.java)

## Complexity

```
O(N) O(1)
```
