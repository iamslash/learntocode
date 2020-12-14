# Problem

[Sum of Absolute Differences in a Sorted Array](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/submissions/)

수열 `nums[]` 가 주어진다. 수열 `result[]` 을 제작한다.  `result[i]`
는 `nums[i]` 와 다른 `nums[j]` 의 차이에 절대값을 취한 것들의 합과
같다.

예를 들어 `nums = [2, 3, 5]` 이면 `result = [4, 3, 5]` 이다.

# Idea

예를 들어 `nums = [1, 4, 6, 8, 10]` 인 경우를 살펴보자.

```
        i
  nums: 1 4 6 8 10
           1-1     4-1     6-1      8-1  10-1 : 24
          i
  nums: 1 4 6 8 10
         -(1-4)    4-4     6-4      8-4  10-4 : 15
            i
  nums: 1 4 6 8 10
         -(1-6)  -(4-6)    6-6      8-6  10-6 : 13
              i
  nums: 1 4 6 8 10
         -(1-8)  -(4-8)  -(6-8)     8-8  10-8 : 15
                 i
  nums: 1 4 6 8 10
        -(1-10) -(4-10) -(6-10) -(8-10) 10-10 : 21
```

`result[0]` 은 쉽게 구할 수 있다. `diff` 를 선언하여 `nums[1] -
nums[0]` 를 저장한다.  `result[1]` 은 `result[0]` 을 이용해서 구할 수
있다.

```
diff = nums[1] - nums[0]
result[1] = result[0] + diff * i - diff * (n-i)
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
