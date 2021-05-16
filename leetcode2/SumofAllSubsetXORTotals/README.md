# Problem

> [Sum of All Subset XOR Totals](https://leetcode.com/problems/sum-of-all-subset-xor-totals/)

수열 `nums[]` 가 주어진다. XOR total 은 모든 원소들을 서로 `XOR`
연산을 수행한 것을 의미한다. `nums[]` 의 모든 부분집합을
구한다. 그리고 각각의 부분집합에 대해 XOR total 을 구한다.  모든 XOR
total 을 더한 값을 구하라.

# Idea

예를 들어 `nums = [1,3]` 의 경우를 살펴보자.

```
        nums: 1 3
     subsets: 0    0
              1    1
              3    3
              1 3  2
         sum:      6
```

따라서 답은 `6` 이다.

`int n = nums.length` 를 선언하여 `nums[]` 의 길이를 저장한다.

부분집합의 개수는 공집합 까지 합쳐서 `2^n` 이다. 문제의 조건에 의해 `1
<= n <= 12` 이다. bitmask 를 이용하여 부분집합을 표현할 만 하다.

`int subsetCnt = 1 << n` 를 선언하여 부분집합의 개수를 저장한다. `int
ans = 0` 을 선언하여 답을 저장한다.

`int bm` 를 `[1..subsetCnt)` 만큼 순회하면서 다음을 반복한다.

* `int xorTotal = 0` 을 선언하여 xor total 을 저장한다.
* 인덱스 `j` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.
  * `(1 << j)` 이 `bm` 에 있다면 `xorTotal` 업데이트 한다. 즉, `(bm &
    (1 << j)) > 0` 이면 `xorTotal ^= nums[j]` 를 수행한다.
* 부분집합 `bm` 에 대해 `xorTotal` 을 구했다. 이것을 `ans` 에
  더한다. 즉, `ans += xorTotal` 을 수행한다.
  
모든 반복을 마치면 `ans` 를 리턴한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(2^N) O(1)
```
