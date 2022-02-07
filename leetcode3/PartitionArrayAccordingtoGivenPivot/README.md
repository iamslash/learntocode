# Problem

[Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

수열 `nums[]` 와 숫자 `pivot` 이 주어진다. `pivot` 을 중심으로 작은값은
왼쪽 큰 값은 오른쪽 같은 값은 중간으로 배치하라. `nums[]` 에서
상대적인 위치는 유지해야 한다.

# Idea

예를 들어 `nums = [9,12,5,10,14,3,10], pivot = 10` 의 경우를 살펴보자.

```
pivot: 10
       i
 nums: 9 12 5 10 14 3 10
                       j
       b
  ans: 9 5 3 10 10 12 14
                       e
```

4 개의 인덱스를 이용하여 해결할 만 하다.

`nums[]` 에 `i, j` 와 같이 두개의 인덱스를 이용하여 양끝에 배치한다.
`ans[]` 에 `b, e` 와 같이 두개의 인덱스를 이용하여 양끝에 배치한다.

`i < n` 동안 `i++, j--` 하면서 `pivot` 보다 작은 값은 `ans[b++]` 에
저장하고 큰 값은 `ans[e--]` 에 저장한다. 그리고 `b <= e` 동안 `pivot`
을 `ans[b++]` 에 저장한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
