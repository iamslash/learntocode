# Problem

[Tuple with Same Product](https://leetcode.com/problems/tuple-with-same-product/)

수열 `nums[]` 가 주어진다. `nums[]` 의 수들은 모두 distinct 하다.

다음의 조건을 만족하는 tuple `(a, b, c, d)` 을 찾아보자.

* `a != b != c != d`
* `a * b == c * d`

그 tuple 의 개수를 구하라.

# Idea

예를 들어 `nums = [2,3,4,6]` 의 경우를 살펴보자.

```
nums: 2 3 4 6

(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
```

따라서 답은 8 이다.

여기서 중요한 규칙을 하나 발견할 수 있다. `(2, 3, 4, 6)` 과 같이
조건을 만족하는 tuple 을 하나 찾으면 그 원소들을 재배치해서 경우의수 8
을 얻을 수 있다.

`nums[]` 에서 두개의 수를 찾고 그것의 곱과 같은 수가 이미 있었다면
답에 `8` 을 더하면 된다.

`int ans = 0` 을 선언하여 답을 저장한다.  `Map<Integer, Integer>
prodMap = new HashMap<>()` 을 선언하여 두수의 곱을 저장한다.

인덱스 `i` 를 이용하여 nums 를 `[0..n)` 만큼 순회하며 다음을 반복한다.

* 인덱스 `j` 를 이용하여 `nums` 를 `[i+1..n)` 만큼 순회하며 다음을 반복한다.
  * `int prod = nums[i] * nums[j]` 를 선언하여 두수의 곱을 저장한다.
  * `prodMap` 에 `prod` 가 있다면 `ans` 에 8 을 더한다.
  * `prodMap` 에 `prod` 를 삽입한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N^2) O(N)
```

# Similar Questions

* [Two Sum](https://leetcode.com/problems/two-sum/)
