# Problem

[Equal Sum Arrays With Minimum Number of Operations](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/)

수열 `nums1[]` 과 `nums2[]` 가 주어진다. 각 수열은 `1~6` 의 숫자로만
구성된다. 한번의 동작으로 하나의 숫자를 `1~6` 의 숫자로 교체할 수
있다. 각 수열의 합이 서로 같아지도록 하기 위한 최소의 교체 횟수를
구하라.

# Idea

예를 들어 `nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]` 의 경우를 살펴보자.

```
nums1: 1 2 3 4 5 6    nums2: 6 1 2 2 2 2
nums1: 1 2 3 4 5 1    nums2: 6 1 2 2 2 2
nums1: 1 2 2 4 5 1    nums2: 6 1 2 2 2 2
```

다음과 같은 변수를 선언한다.

> * `sum1 = sum(nums1)` 
> * `sum2 = sum(nums2)` 
> * `sum1 < sum2` 가 되도록 swap 한다.
> * `ans = 0` 
> * `diff = sum2 - sum1`

이제 `diff` 를 0 보다 작거나 같도록 만들 수 있는 최소 횟수를 구하면
답이 된다. 

`sum1 < sum2` 이다. 따라서 `nums1` 의 숫자들은 증가시킬 수 있다.  또한
`nums2` 의 숫자들은 감소시킬 수 있다. `nums1` 의 각 숫자들은
`[0..6-nums1[i]]` 만큼 증가시킬 수 있다. `nums2` 의 각 숫자들은
`[0..nums2[i]-1]` 만큼 감소시킬 수 있다.

`removes[]` 를 선언하여 `nums1[i]` 의 증가시킬 수 있는 숫자와
`nums2[i]` 의 감소시킬 수 잇는 숫자를 삽입한다. 그리고 내림차순으로
정렬한다.

이제 `remove` 로 `removes[]` 를 순회하며 다음을 반복한다.

> * `ans` 를 하나 증가한다.
> * `diff -= remove` 를 수행한다.
> * `diff <= 0` 이면 `ans` 를 리턴한다.

모든 반복을 마치면 -1 를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [python3](a.py)

# Complexity

```
O(NlgN) O(N)
```
