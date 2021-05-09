# Problem

> * [Missing Ranges](https://leetcode.com/problems/missing-ranges/)

수열 `A[]` 가 주어지고 숫자 `lo, hi` 가 주어진다.  `[lo..hi]` 에 포함된
숫자들 중 `A[]` 에 없는 숫자들을 다음과 같은 표기법을 이용하여 구하라.

* `"a->b"` if `a != b`
* `"a"` if `a == b`

# Idea

예를 들어 `nums = [0,1,3,50,75], lo = 0, hi = 99` 의 경우를 살펴보자.

```
   lo: 0
   hi: 99
       c
 nums: 0 1 3 50 75
       i
```

따라서 답은 `["2","4->49","51->74","76->99"]` 이다.

`List<String> ans = new ArrayList<>()` 를 선언하여 답을 저장한다. `int
miss = lo` 를 선언하여 이번에 검토할 숫자를 저장한다. `hi+1` 를
`nums[]` 에 추가하면 loop statement 에 모든 logic 을 구현할 수
있다. `int n = nums.length` 를 선언하여 `nums` 의 길이를 저장한다.

인덱스 `i` 를 이용하여 `[0..n]` 동안 순회하면서 다음을 반복한다.

* `miss < num` 이면 `(miss, nums[i]-1)` 를 추가한다.
* `miss = num + 1` 를 수행한다.

모든 반복을 마치면 `ans` 를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
