# Problem

[Count Special Quadruplets](https://leetcode.com/problems/count-special-quadruplets/)

수열 `nums[]` 가 주어진다. 다음 조건을 만족하는 `a, b, c, d` 의 개수를 구하라.

* `nums[a] + nums[b] + nums[c] == nums[d]`
* `a < b < c < d`

# Idea

예를 들어 다음과 같이 `nums = [1,2,3,6]` 의 경우를 살펴보자.

```
1 2 3 6

1 + 2 + 3 = 6
```

따라서 답은 `1` 이다.

주어진 조건을 생각해 보면 다음과 같은 수식을 발견할 수 있다.

```
a + b + c = d (a < b < c < d)
    a + b = d - c
```

따라서 `d - c` 의 개수를 `Map<Integer, Integer>` 에 저장해 두고 `a +
b` 가 `Map<>` 에 있다면 그 개수를 답에 저장하는 식으로 생각해 보자.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N^2) O(N^2)
```
