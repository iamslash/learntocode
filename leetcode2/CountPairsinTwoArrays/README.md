# Problem

[Count Pairs in Two Arrays](https://leetcode.com/problems/count-pairs-in-two-arrays/)

수열 `nums1[], nums2[]` 가 주어진다. 다음을 만족하는 짝 `(i, j)` 의 개수를 구하라.

```
i < j and nums1[i] + nums1[j] > nums2[i] + nums2[j]
```

# Idea

문제의 조건으로 부터 다음과 같은 수식을 유도할 수 있다.

```
nums1[i] + nums1[j] > nums2[i] + nums2[j]
nums1[i] - nums2[i] > nums2[j] - nums1[j]
nums1[i] - nums2[i] > -(nums1[j] - nums2[j])
            diff[i] > -diff[j]
  diff[i] + diff[j] > 0
```

즉, `diff[i] + diff[j] > 0` 를 만족하는 짝 `(i, j)` 의 개수를 구해야 한다.

예를 들어 `nums1 = [1,10,6,2], nums2 = [1,4,1,5]` 의 경우를 살펴보자.

```
       nums1: 1 10 6 2
       nums2: 1  4 1 5
       diffs:  0  6 -5 -3
                        i
sorted diffs: -5 -3  0  6
                     j
         cnt: 3
```

???

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
