# Problem

[Kth Smallest Subarray Sum](https://leetcode.com/problems/kth-smallest-subarray-sum/)

수열 `nums[]` 과 숫자 `k` 가 주어진다. `k` 번 째 smallest subarray sum 을 구하라.

# Idea

예를 들어 `nums = [2,1,3], k = 4` 의 경우를 살펴보자.

```
[2] with sum 2
[1] with sum 1
[3] with sum 3
[2,1] with sum 3
[1,3] with sum 4
[2,1,3] with sum 6 
```

따라서 답은 `3` 이다.

이 문제는 다음과 같은 두가지 방법을 이용하여 해결할 만 하다. 

* [sliding window](/fundamentals/slidingwindow/nestedloop/README.md) 를 이용하여 임의의 숫자보다 작거나 같은 subarray sum 의 개수를 구한다.
* [binary search](/fundamentals/search/binarysearch/README.md) 를 이용하여 `k` 번째 smallest subarry sum 를 구한다.

먼저 다음과 같은 함수를 선언한다. 수열 `nums[]`, 숫자 `tgtSum` 가 주어지면 그것보다 작거나 같은 subarray sum 의 개수를 리턴하도록 구현한다.

```java
int countLessEqual(int nums[], int tgtSum)
```

예를 들어 `nums = [2,1,3], tgtSum = 3` 인 경우를 살펴보자. 

* `int i, j` 를 선언하여 [sliding window](/fundamentals/slidingwindow/nestedloop/README.md) 의 왼쪽, 오른쪽 인덱스를 저장한다.
* `int sum` 을 선언하여 [sliding window](/fundamentals/slidingwindow/nestedloop/README.md) 에 해당하는 subarray sum 을 저장한다.
* `int cnt` 을 선언하여 `subarray sum` 이 `tgtSum` 보다 작거나 같은 것들의 개수를 저장한다.

```
tgtSum: 3    
        i        i        i            i        i
  nums: 2 1 3    2 1 3    2 1 3    2 1 3    2 1 3
        j        j          j          j          j
   sum: 0        2        3        3        3
   cnt: 0        1        3        4        4
```

따라서 답은 `4` 이다.

`tgtSum` 을 [binary search](/fundamentals/search/binarysearch/README.md) 를 이용하여 구한다.

# Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(NlgN) O(1)
```
