# Problem

[Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum/)

수열 `nums[]` 가 주어진다. alternating sum 은 짝수 인덱스 원소들의
합에서 홀수 인덱스 원소들의 합을 뺀 것이다. alternating sum 이 최대가
되는 `nums[]` 의 subsequence 를 구하라.

# Recursive Dynamic Programming

## Idea

다음과 같은 부분문제를 정의한다.

```c
int dfs(nums, C, i, odd)

return: max laternating sum start with the num of i-index, order
  nums: input
     C: cache for i, ord
   odd: 0 for even index, 1 for odd index 
```

`i` index 숫자를 `odd` index 로 포함했을 때와 포함하지 않았을 때를
비교해서 최대를 리턴한다.

```
C[ord][i] = Math.max(nums[i] + dfs(nums, C, i+1, ord^1),
                     dfs(nums, C, i+1, ord))
```

## Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kotlin)

# Complexity

```
O(N^2) O(N)
```

# Iterative Dynamic Programming

## Idea

인덱스 `i` 로 `[0..n)` 동안 `nums[]` 를 순회한 다고 해보자. 다음과
같은 3 가지 경우를 생각할 수 있다.

* `nums[i]` 가 even index 로 포함되는 경우
* `nums[i]` 가 even index 로 포함되지 않는 경우
* `nums[i]` 가 odd index 로 포함되는 경우
* `nums[i]` 가 odd index 로 포함되지 않는 경우

`int sumEven = 0` 을 선언하여 `nums[i]` 가 even index 로 포함되거나
혹은 포함되지 않았을 경우 max alternating sum 을 저장한다.

`int sumOdd = 0` 을 선언하여 `nums[i]` 가 odd index 로 포함되거나
혹은 포함되지 않았을 경우 max alternating sum 을 저장한다.

다음과 같은 iterative dynamic equation 을 발견할 수 있다??? too difficult.

```
sumEven = max(sumEven, sumOdd + nums[i])

  when sumEven is sumEven: nums[i] is not included as even index
  when sumEven is sumOdd + nums[i]: nums[i] is included as even index
          
sumOdd = sumEven - nums[i]
  
  when sumEven is sumEven: nums[i] is included as odd index
  when sumEven is sumOdd + nums[i]: nums[i] is not included as odd index
```

## Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kotlin)

# Complexity

```
O(N) O(1)
```

# Iterative Dynamic Programming

## Idea

숫자 `[A...Z]` 중 임의의 개수에 대해 다음과 같이 생각해 볼 수 있다.

* `[A]`
  * 답은 `A` 이다.
* `[A,B]`
  * 답은 `A + max(B-A, 0)` 이다.
  * `[2,4]` 의 답은 `2+(4-2)` 이다.
  * `[4,2]` 의 답은 `4+(0)` 이다.
*`[A,B,C]`
  * 답은 `A + max(B-A, 0) + max(C-B, 0)` 이다.
  * `[4,6,2]` 의 답은 `4 + (6-4) + (0)` 이다.
  * `[2,6,4]` 의 답은 `2 + (6-2) + (0)` 이다.
  * `[4,2,6]` 의 답은 `4 + (0) + (4)` 이다.
  * `[6,2,4]` 의 답은 `6 + (0) + (2)` 이다.

`nums[0]` 제외한 max alternating subsequence sum 는 [BestTimeToBuyAndSellStockII](/leetcode/BestTimeToBuyAndSellStockII/README.md)
의 답과 같다.

## Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kotlin)

# Complexity

```
O(N) O(1)
```
