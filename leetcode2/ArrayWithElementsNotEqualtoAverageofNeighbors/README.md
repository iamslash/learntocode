# Problem

[Array With Elements Not Equal to Average of Neighbors](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/)

수열 `nums[]` 가 주어진다. `nums[i]` 는 distinct 하다. `0 < i < n-1`
를 만족하는 i 에 대하여 `(nums[i-1] + nums[i+1]) / 2 != nums[i]` 를
만족하도록 `nums[]` 를 재배치 하라.

# Idea

예를 들어 `nums = [1,2,3,4,5]` 의 경우를 살펴보자.

```
        i
nums: 1 2 3 4 5

      1 3 2 5 4
```

따라서 답은 `1, 3, 2, 5, 4` 이다.

숫자가 y 좌표값을 의미한다고 하면 `/\/\/\` 혹은 `\/\/\/` 와 같이 x
값에 따라 높낮이가 다르게 배열하면 된다. 문제의 조건에 의해 모든
수들은 unique 하다. 따라서 가장 작은 차이를 갖는 예를 따져보면
알고리즘을 증명할 수 있다.

```
nums: 1 2 3

      1 3 2
     \ / \

      2 1 3
     / \ /
     
nums: 3 2 1

      3 1 2
      2 3 1
```

따라서 3 개의 수가 늘어서 있을 때 다음과 같은 알고리즘을 구상해 보자.

* `a > b > c` 이면 `b` 와 `c` 를 교체한다.
* `a < b < c` 이면 `b` 와 `c` 를 교체한다.

위의 구상을 기반으로 다음과 같이 알고리즘을 구현한다.

인덱스 `i` 를 `[1..n)` 동안 순회하면서 다음을 반복한다.

* `nums[i-1] > nums[i] > nums[i+1]` 이면 `nums[i]` 와
  `nums[i+1]` 을 교체한다.
* `nums[i-1] < nums[i] < nums[i+1]` 이면 `nums[i]` 와
  `nums[i+1]` 을 교체한다.

모든 반복을 마치면 `nums` 가 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
