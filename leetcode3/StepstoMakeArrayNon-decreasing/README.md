# Problem

[Steps to Make Array Non-decreasing](https://leetcode.com/problems/steps-to-make-array-non-decreasing/)

수열 `nums[]` 가 주어진다. 한번 동작으로 다음 조건을 만족하는
`nums[i]` 를 삭제할 수 있다.

* `nums[i-1] > nums[i]` for all `0 < i < n`

`nums[]` 를 non-decreasing array 로 바꾸기 위해 수행해야 하는 동작의
수를 구하라.

# Idea

문제를 이해하는 것이 어렵다.

예를 들어 `nums = [11,8,5,11]` 를 살펴보자.

```
nums: 11 8 5 11
         . .
      11 11   
```

답은 `1` 이다. `2` 가 아니다.

또한 `nums = [11,8,5,3,1,11]` 를 살펴보자.

```
nums: 11 8 5 3 1 11
         . . . .
      11 11

```

답은 `1` 이다. `4` 가 아니다.

또한 `nums = [5,3,4,4,7,3,6,11,8,5,11]` 를 살펴보자.

```
nums: 5 3 4 4 7 3 6 11 8 5 11
        .       .      . .
      5 4 4 7 6 11 11  
        .     .
      5 4 7 11 11  
        .
      5 7 11 11  
```

따라서 답은 `3` 이다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
