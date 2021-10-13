# Problem

[Count Subarrays With More Ones Than Zeros](https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/)

수열 `nums[]` 가 주어진다. `nums[]` 는 `0, 1` 로 구성되어 있다.  `0`
보다 `1` 의 개수가 많은 subarray 들의 개수를 구하라. 답이 너무 크다면
`10^9 + 7` 로 나눈 나머지 값을 취하라.

# Idea

예를 들어 `nums = [0,1,1,0,1]` 인 경우를 살펴보자.

```
           i
     nums: 0 1 1 0 1
subarrays:

             i
     nums: 0 1 1 0 1
subarrays: 1 

               i
     nums: 0 1 1 0 1
subarrays: 1 11 011

                 i
     nums: 0 1 1 0 1
subarrays: 110

                   i
     nums: 0 1 1 0 1
subarrays: 1 101 1101 01101
```

따라서 답은 9 개이다.

먼저 다음과 같은 변수들을 선언한다.

* `int ans = 0` 을 선언하여 답을 저장한다. 
* `int curCnt = 0` 을 선언하여 현재 숫자로 끝나는 subarray 의 개수를
  저장한다. 그 subarray 는 답에 저장할 만 하다. 즉, `1` 의 개수가 `0`
  의 개수보다 많다.
* `int oneBal = 0` 선언하여 `balance of 1` 을 저장한다. `0` 을
  만나면 하나 감소하고 `1` 을 만나면 하나 증가한다.
* `Map<Integer, Integer> cntMap = new HashMap<>()` 를 선언하여 `{
  balance of 1 : count when balance of 1 }` 을 저장한다. `balance of
  1` 은 `oneBal` 같다.

이제 인덱스 `i` 를 이용하여 `[0, n)` 동안 순회하며 다음을 반복한다.

* `nums[i] == 1` 이면
  * `curCnt` 에 `nums[i]` 로 끝나는 subarray 의 개수를 더한다. 그 subarray 는 답에
    저장할 만 하다. 즉, `1` 의 개수가 `0` 의 개수보다 많다. 
  * `oneBal` 을 하나 증가한다.
* `nums[i] == 0` 이면
  * `oneBal` 을 하나 감소한다.
  * `curCnt` 에서 `nums[i]` 로 끝난 subarray 의 개수를 뺀다. 그 subarray
    는 답에 저장할 만하지 못하다. 즉, `1` 의 개수가 `0` 의 개수보다 적거나 같다.
* `oneBal` 의 출현 횟수를 하나 증가한다. 즉, `cutMap[oneBal]++` 를 수행한다.
* `nums[i]` 로 끝나는 subarray 의 개수를 더한다. 그 subarray 는 답에
  저장할 만 하다. 즉, `ans += curCnt` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

어렵다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
