# Problem

> [Maximize the Beauty of the Garden](https://leetcode.com/problems/maximize-the-beauty-of-the-garden/)

수열 `F[]` 가 주어진다. `F[]` 의 부분수열들 중 처음과 끝 원소가 같은
것들에 임의의 원소들을 삭제할 수 있다. 그 부분수열들 중 원소들의 합이
가장 큰 것을 구하고 그 합을 리턴하라.

# Idea

예를 들어 `F = [1,2,3,1,2]` 의 경우를 살펴보자.

```
      _______
F = 1 2 3 1 2
```

따라서 답은 `8` 이다.

`Map<Integer, Integer> sumMap = new HashMap<>()` 를 선언 하여 `{F[i],
partial sum}` 을 저장한다.  `int ans = Integer.MIN_VALUE` 를 선언하여
답을 저장한다.  `int sum = 0` 를 선언하여 부분합을 저장한다. `F[i] <=
0` 이면 `sum` 에 더할 필요는 없다.

숫자 f 로 `F[]` 를 순회하면서 다음을 반복한다.

* `psMap` 에 `f` 가 있다면 조건에 해당하는 부분합을 발견한 것이다. 
  * `int rangeSum = sum - psMap.get(f)` 를 선언하여 부분합을 양끝
    숫자를 제외한 부분합을 저장한다.
  * `ans` 를 업데이트 한다. 즉, `ans = max(ans, rangeSum + 2 * f)` 를
    수행한다.
* `f > 0` 이면 `sum` 에 더한다.
* `psMap` 에 `f` 가 없을 때만 `psMap` 에 `{f, sum}` 를 삽입한다.

다음은 앞서 언급한 알고리즘의 풀이과정이다.

```
                f
     F: 1 2 3 1 2
sumMap: 1 2 3
        1 3 6 7 9
   ans: 8
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
```
