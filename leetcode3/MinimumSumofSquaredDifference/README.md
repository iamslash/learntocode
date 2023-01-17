# Problem

[Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/)

수열 `nums1[], nums2[]`, 숫자 `k1, k2` 가 주어진다.

두 수열 `nums1[], nums2[]` 에 대하여 sum of squared difference 
는 다음과 같다. 

```
sum of (nums1[i] - nums2[i])^2   (0 <= i < n)
```

이때 `nums1[]` 의 숫자를 최대 `k1` 만큼 `nums2[]` 의 숫자를 최대 `k2`
만큼 `+1` 혹은 `-1` 할 수 있다.

minimum sum of squared difference 를 구하라.

# Idea

예를 들어 `nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0`
의 경우를 살펴보자.

```
(1 - 2)^2 + (2 - 10)^2 + (3 - 20)^2 + (4 - 19)^2 = 579.
```

따라서 답은 `579` 이다.

이번에는 `nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1`
의 경우를 살펴보자. `int[] diffs` 를 선언하여 `nums1[i] - nums2[i]` 
를 저장한다. `int[] freqs` 를 선언하여 `freqs[diff]` 에 `diff` 가
발생한 횟수를 저장한다.

```
   k1: 1
   k2: 1
nums1: 1  4 10 12
nums2: 5  8  6  9
diffs: 4  4  4  3
freqs: 4  3
       3  1 
```

`diffs[i] == 4` 인 것이 `3` 개 존재한다. 그리고 `k1 + k2 == 2` 이다.
`diffs[i] == 4` 인 것을 `diffs[i] == 3` 으로 `2` 번 만들 수 있다.  즉,
`freqs[4] == 1` 이 되고 `freqs[3] == 3` 이 된다. 이 것은 minimum sum
of squared difference 를 구하는 방법이다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
