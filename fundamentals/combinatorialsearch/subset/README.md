# Problem

> [Backtracking to find all subsets @ geeksforgeeks](https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/)

양의 정수 `n` 이 주어졌을 때 `[1..n]` 의 숫자들로 구성된 부분집합을 만들어 보자.

# Bit Manipulation

## idea

예를 들어 `n = 3` 일때를 생각해 보자. 숫자 `subset` 를 이용하여 `[1..2^3)` 만큼
순회하면서 모든 `subset` 을 이진수로 나타내보자.

```
subset: 1  001
        2  010
        3  011
        4  100
        5  101
        6  110
        7  111
```

이진수 subset 를 구성하는 숫자는  `1, 2, 3` 숫자의 존재여부를 표현한다. 결국
발생된 subset 의 개수 즉, `2^n-1` 은 만들어야할 부분집합의 개수와 같다. 공집합
까지 포함하면 부분집합의 개수는 `2^n` 이다. backtracking 보다 이해하기 쉽다.

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(2^N) O(N)
```

# BackTracking

## Idea

`vector<vector<int>> rslt` 를 선언하여 답을 저장한다. `vector<int> comb` 를
선언하여 답에 추가할 후보를 저장한다.

다음과 같이 부분문제 `dfs` 를 구상한다.

```
void dfs(int pos)

pos: the position to visit at this time
```

다음과 같이 부분문제 `dfs` 를 구현한다.

* `pos > 0` 이면 후보에 해당하는 `comb` 를 `rslt` 에 추가한다.
* 숫자 `num` 를 `[pos+1..n]` 동안 순회하면서 다음을 반복한다. `num` 을 포함한
  경우와 포함하지 않는 경우를 모두 방문한다.
  * `comb` 에 `num` 을 추가한다.
  * `dfs(num)` 을 호출한다.
  * `comb` 에서 `num` 을 제거한다.

`dfs(0)` 을 호출하면 DFS 를 수행하고 `rslt` 가 곧 답이다.

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(2^N) O(N)
```
