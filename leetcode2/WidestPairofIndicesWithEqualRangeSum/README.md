# Problem

> [Widest Pair of Indices With Equal Range Sum게ㅅ](https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/)

`0, 1` 로 구성된 수열 `nums1[], nums2[]` 가 주어진다. 다음을 만족하는
`i, j` 를 찾는다.  `j - i` 는 최대가 되도록 하라.

```
nums1[i] + nums1[i+1] + ... + nums1[j] == 
nums2[i] + nums2[i+1] + ... + nums2[j] 
```

# Idea

문제의 조건을 다시 살펴보면 다음과 같은 수식을 발견할 수 있다.

```
nums1[i] + nums1[i+1] + ... + nums1[j] == 
nums2[i] + nums2[i+1] + ... + nums2[j] 


 nums1[i] + nums1[i+1] + ... + nums1[j] -
(nums2[i] + nums2[i+1] + ... + nums2[j])= 0 

(nums1[i]   -   nums2[i]) + 
(nums1[i+1] - nums2[i+1]) + 
(nums1[...] - nums2[...]) + 
(nums1[j]   -   nums2[j]) = 0
```

`(nums1[i] - nums2[i])` 의 부분합을 sum 라고 해보자.  같은 sum 가 두번
발생했다면 나중에 발생한 ps 의 인덱스와 이전에 발생한 ps 의 인덱스의
차이가 답이된다.

다음과 같이 알고리즘을 생각해 보자. 먼저 `Map<Integer, Integer>
sum2idxMap` 을 선언하여 부분합과 인덱스를 저장한다. `int sum = 0` 을
저장하여 `nums1[i] - nums2[i]` 의 부분합을 저장한다. `int n =
nums1.length` 를 선언하여 `nums1` 의 길이를 저장한다. `int maxDist` 를
선언하여 답을 저장한다.

magic seed 를 위해 `sum2idxMap.put(0, -1)` 를 수행한다.

인덱스 `i` 를 이용하여 `[0..n)` 동안 다음을 반복한다.

* 부분합을 `sum` 에 저장한다. 즉, `sum += (nums1[i] - nums2[i])` 를
  수행한다.
* 현재 발생한 부분합 `sum` 이 이전에 발생했다면 둘 사이의 거리를
  `maxDist` 와 비교하여 답에 저장한다. 즉, `maxDist = max(maxDist, i -
  sum2idxMap.get(sum))` 를 수행한다.
* 현재 발생한 부분합과 인덱스 를 `sum2idxMap` 에 저장한다. 그러나
  `sum` 이 이미 있다면 저장할 필요가 없다. 최대 거리를 구해야 하기
  때문이다.

모든 반복을 마치면 `maxDist` 가 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
