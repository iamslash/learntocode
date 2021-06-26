# Problem

[Remove One Element to Make the Array Strictly Increasing](https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/)

수열 `nums[]` 가 주어진다. 최대 1 개를 제거해서 strictly increasing 이 
되는지 검증하라.

# Idea

예를 들어 `nums = [1,2,10,5,7]` 의 경우를 생각해 보자.

```
             i
nums: 1 2 10 5 7
           .
             .
```

위와 같이 `i == 3` 일 때 두개의 숫자중 하나를 지울 수 있다. 

0) `nums[1] < nums[3]` 이라면 `nums[2]` 를 지운다.
1) `nums[1] >= nums[3]` 이라면 `nums[3]` 을 지운다.

`nums[3]` 을 지운다면 `nums[3] = nums[2]` 를 수행핸다.

# Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(N) O(1)
```
