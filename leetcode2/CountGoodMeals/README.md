# Problem

[Count Good Meals](https://leetcode.com/problems/count-good-meals/)

수열 `deliciousness[]` 가 주어진다. `deliciousness[i]` 는 `i-th`
음식의 맛있음의 정도를 나타낸다. 서로 다른 음식의 deliciousness 를
더했을 때 그것이 `power of 2` 가 되는 모든 경우를 구하라.

# Idea

예를 들어 `deliciousness = [1,3,5,7,9]` 의 경우를 살펴보자.

```
(1,3) 2^2
(1,7) 2^3
(3,5) 2^3
(7,9) 2^4
```

따라서 답은 4 이다.

문제의 조건에 의해 `0 <= deliciousness[i] <= 2^20` 이다.  따라서 서로
다른 두수의 deliciousness 의 합은 `0 <=
sum(deilciousness[i]+deliciousness[j]) <= 2^21` 이다.

`Map<Integer, Integer> cntMap = new HashMap<>()` 을 
선언하고 `{num : count of num}` 을 저장한다.

`int num` 으로 deliciousness 를 순회하면서 다음을 반복한다.

* `int power = 1` 를 선언하다.
* 인덱스 `i` 를 `[0..21]` 동안 순회하면서 다음을 반복한다.
  * `int opp = power - num` 를 수행하여 `num` 과 합하여 power of 2 가
    되는 숫자가 있는지 확인한다.  있다면 `ans` 에 그 개수를 더한다.
  * `power` 를 다음 power of 2 숫자로 증가한다. 즉, `power <<= 1` 을
    수행한다.
* `cntMap` 의 `num` 의 개수를 하나 증가한다.


모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```

# Similar Questions

* [Two Sum](https://leetcode.com/problems/two-sum/)
* [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/)
