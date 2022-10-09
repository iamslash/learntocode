# Problem

[Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)

수열 `nums[]` 가 주어진다. 모든 subarray 들을 한다. 각 subarray 의
최대값에서 최소값을 뺀 차이를 모두 더한 값을 구하라.


# Brute Force Way
## Idea

예를 들어 `nums = [1,2,3]` 의 경우를 살펴보자.

```
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
```

따라서 답은 `0 + 0 + 0 + 1 + 1 + 2 = 4` 이다.

먼저 모든 subarray 들의 최대값들의 합을 구한다.  그리고 모든 subarray
들의 최소값들의 합을 구한다.  두 값의 차이가 곧 답이다.

모든 subarray 들의 최대값, 최소값은 [Sum of Subarray
Minimums](/leetcode/SumofSubarrayMinimums/README.md) 를 참고한다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N^2) O(1)
```

# Math Way

## Idea
 
* `nums[i]` 로 끝나는 subarray 중 `nums[i]` 가 min 이 되는 것들의 개수를 구한다. -- a
* `nums[i]` 로 시작하는 subarray 중 `nums[i]` 가 min 이 되는 것들의 개수를 구한다. -- b
* 두가지를 서로 곱하면 `nums[i]` 가 min 이 되는 subarray 의 개수를 구할 수 있다. -- a * b
* `nums[i]` 로 끝나는 subarray 중 `nums[i]` 가 max 이 되는 것들의 개수를 구한다. -- c
* `nums[i]` 로 시작하는 subarray 중 `nums[i]` 가 max 이 되는 것들의 개수를 구한다. -- d
* 두가지를 서로 곱하면 `nums[i]` 가 max 이 되는 subarray 의 개수를 구할 수 있다. -- c * d
* 모든 subarray 에 대해 `a * b` 를 빼고 `c * d` 를 더하면 답이 된다. 
* `[4, 1, 2, 3]` 의 subarray 의 개수는 `4 * 5 / 2 = 10`
  이다. `nums[i]` 가 min, max 일 경우 subarray 의 개수는 `10 * 2 = 20`
  이다.

```
      i
nums: 4 1 2 3
    l
              r


4 is min: 1 * 1
      4
4 is max: 1 * 4 
      4
      4 1
      4 1 2
      4 1 2 3
1 is min: 2 * 3
        1
        1 2
        1 2 3
      4 1
      4 1 2
      4 1 2 3
1 is max: 1 * 1
        1
2 is min: 1 * 2
          2
          2 3
2 is max: 2 * 1
          2
        1 2
3 is min: 1 * 1
          3
3 is max: 3 * 1
          3
        2 3
      1 2 3
```

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N^2) O(1)
```
