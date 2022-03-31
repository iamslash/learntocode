# Problem

[Intervals Between Identical Elements](https://leetcode.com/problems/intervals-between-identical-elements/)

수열 `arr[]` 이 주어진다. `arr.length` 만큼의 길이를 갖는 수열 `ans[]`
을 준비한다.  `arr[i]` 과 같은 수를 찾고 거리들을 모두 더한 값을
`ans[i]` 에 저장한다. 즉, `arr[1] == 1` 이면 `arr[]` 에 존재하는 `1`
을 모두 찾고 그것들의 거리를 모두 합하여 `ans[1]` 에 저장한다. `arr[]`
을 구하라.

# Idea

예를 들어 `arr = [2,1,3,1,2,3,3]` 의 경우를 살펴보자.

```
   arr: 2 1 3 1 2 3 3
   idx:   1   3 
ans[1]: |1 - 3] = 2
   arr: 2 1 3 1 2 3 3
   idx:     2     5 6 
ans[2]: |2 - 5] + |2 - 6| = 7
```

다음과 같은 규칙을 발견할 수 있다.

```
   arr: a b c a a
   idx: 0     3 4
ans[0]: |0 - 3| + |0 - 4|
        0 * 2 - (3 + 4)
        num * freq - (idx sum of num)
```

이때 `(idx sum of num)` 이 미리 저장되어 있다면 좋을 것
같다. `Map<Integer, Long> sumMap` 을 선언하여 `(idx sum of num)` 을
저장한다.

다음과 같은 변수들을 선언한다.

* `Map<Integer, Long> sumMap = new HashMap<>()` 을 선언하여 출현
  숫자에 대한 인덱스들의 합을 저장한다.
* `Map<Integer, Integer> cntMap = new HashMap<>()` 을 선언하여 출현
  숫자에 대한 출현 횟수를 저장한다.
  
`arr[]` 을 왼쪽으로 한번 순회하고 오른쪽으로 한번 순회한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
