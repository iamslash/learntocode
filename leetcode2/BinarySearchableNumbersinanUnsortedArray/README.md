# Problem

[Binary Searchable Numbers in an Unsorted Array](https://leetcode.com/problems/binary-searchable-numbers-in-an-unsorted-array/)

수열 `nums` 가 주어진다. 다음의 알고리즘으로 찾을 수 있는 target 의 개수를
구하라. 다음의 알고리즘은 binary search 와 비슷하다.

```c
func(sequence, target)
  while sequence is not empty
    randomly choose an element from sequence as the pivot
    if pivot = target, return true
    else if pivot < target, remove pivot and all elements to its left from the sequence
    else, remove pivot and all elements to its right from the sequence
  end while
  return false
```

# foward and backward

## Idea

예를 들어 `nums = [-1, 5, 2]` 의 경우를 살펴보자. 

* `target == -1` 일 때를 생각해 보자.
  * `pivot == 2` 일 때 `2` 가 제거된다. `pivot == 5` 일 때 `5` 가 제거된다. 찾았다.
  * `pivot == 5` 일 때 `5, 2` 가 제거된다. 찾았다.
  * `pivot == -1` 일 때 찾았다.
* `target == 5` 일 때를 생각해 보자.
  * `pivot == 2` 일 때 `-1, 5, 2` 가 제거된다. 찾지 못한다.
* `target == 2` 일 때를 생각해 보자. 
  * `pivot == 5` 일 때 `5, 2` 가 제거된다. 찾지 못한다.
  
`target` 이 다음의 조건을 만족하면 검색의 대상이 된다.

* `target` 의 왼편의 수들은 모두 `target` 보다 작다.
* `target` 의 오픈편의 수들은 모두 `target` 보다 크다. 

다음과 같은 변수들을 선언한다. 

* `boolean valids[]` 를 선언하여 `nums[i]` 왼편의 수가 모두 `nums[i]`
보다 작은지 저장한다.
* `int maxNum = -100_0001` 을 선언하여 지금까지 발견한 최대 숫자를
  저장한다.
* `int minNum = 100_0001` 을 선언하여 지금까지 발견한 최소 숫자를
  저장한다.
* `int ans = 0` 을 선언하여 답을 저장한다.

이제 인덱스 `i` 를 이용하여 `[0, n)` 동안 순회하면서 다음을 반복한다. 

* `nums[i] > maxNum` 이면 `valids[i] == true` 를 수행한다.
* `maxNum = max(maxNum, nums[i])` 를 수행한다.

그리고 인덱스 `i` 를 이용하여 `[n-1, 0)` 동안 순회하면서 다음을 반복한다.

* `valids[i] && nums[i] < minNum` 이면 `ans` 를 하나 증가한다.
* `minNum = min(minNum, nums[i])` 를 수행한다.

모든 반복을 마치면 `ans` 를 리턴한다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N) O(N)
```

# monotonic increasing stack

## Idea

`Deque<Ineger> deq = new ArrayDeque<>()` 를 선언하고 오름차순으로 유지한다.

`nums` 를 순회하고 나면 `deq.size()` 가 곧 답이다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N) O(N)
```


