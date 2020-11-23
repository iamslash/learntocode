# Problem

[Maximum Number of Non-Overlapping Subarrays With Sum Equals Target](https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/)

수열 `A[]` 와 숫자 `target` 이 주어진다. `A` 의 subarray 들 중에 합이
`target` 인 것들을 찾아보자. 서로 겹치지 않는 것들의 최대 길이를 구하라.

# Idea

예를 들어 `A = [1,1,1,1,1], target = 2` 경우를 살펴보자.

`cntMap` 을 선언하여 `{sum - target : ans}` 를 저장한다.  `sum` 을
선언하여 `A[i]` 를 더한다.  

인덱스 `i` 를 이용하여 `A` 를 처음부터 순회한다. `A[i]` 를 `sum` 에
더하고 나면 `sum - target` 을 이미 과거에 찾았는지 `cntMa[sum-target]`
을 검색한다. 그리고 있다면 과거의 `ans` 에 하나를 더하여 새로운 `ans`
와 비교하여 큰 값을 답으로 취한다. 물론 새로운 `{sum : ans}` 를
`cntMap` 에 저장해 두어야 한다.

`sum - target` 을 `cnntMap` 에서 검색한다는 것은 최근에 합이 `target`
인 subarray 를 찾았으니 이것과 겹치지 않은 과거의 subarray 들의 개수를
찾는 것을 의미한다.

```
target: 2
     A: 1 1 1 1 1
                i
   sum: 1 2 3 4 5
   ans: 0 1 1 2 2
   
cntMap: 0 1 2 3 4 5
        0 0 1 1 2 2
```

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(N)
```
