# Problem

[Count Subarrays With Median K](https://leetcode.com/problems/count-subarrays-with-median-k/)

수열 `nums[]`, 숫자 `k` 가 주어진다. `nums[]` 의 수자들 중 `k` 를
중심으로 subarray 들을 생각해 보자. 오름차순으로 정렬했을 때 `k` 가
median 인 것의 개수를 구하라.

# Idea

예를 들어 `nums = [2, 5, 1, 4, 3, 6], k = 1` 인 경우를 살펴보자.

```
   k: 1
nums: 2 5 1 4 3 6
          1
          1 4
        5 1
```

따라서 답은 `3` 이다.

`k` 를 median 으로 하는 subarray 의 후보들은 원소의 개수가 짝수 혹은
홀수 이다.  예를 들어 다음의 두 subarray 는 모두 median 이 2 이다.

```
  nums: 1 2 3
  nums:   2 3
```

`k` 를 중심으로 모든 숫자들에 `k` 보다 크면 `+1`, `k` 보다 작으면 `-1`
을 할당해 보자. 이 것을 `delta` 라고 하자.

```
     k: 4
  nums: 3 4 1 5 6
 delta: - 0 - 1 1
          4        sum is 0
          4 1 5    sum is 0
        3 4 1 5 6  sum is 0

     k: 5
  nums: 3 4 1 5 6
 delta: - - - 0 1
              5    sum is 0
              5 6  sum is 1
            1 5 6  sum is 0 
```

`k` 를 중심으로 임의의 subarray 를 만들어서 그 delta 의 합이 `0` 이면
`k` 가 median 인 홀수 개수의 subarray 를 의미한다. delta 의 합이 `1`
이면 `k` 가 median 인 짝수 개수의 subarray 를 의미한다.

`k` 를 포함하여 오른쪽에 있는 숫자들을 살펴보자. `int sum = 0` 을
선언하고 `nums[i] > k` 이면 `sum += 1` `nums[i] < k` 이면 `sum -= 1`
을 수행한다. `Map<Integer, Integer> sumMap` 을 선언하여 발생한 `sum`
과 그 개수를 저장한다.

```
   k: 1
nums: 2 5 1 4 3 6
 sum:     0 1 2 3
```

이제 `k` 를 포함하여 왼쪽에 있는 숫자들을 살펴보자. `sum = 0` 으로
초기화하고 `nums[i] > k` 이면 `sum += 1` `nums[i] < k` 이면 `sum -= 1`
을 수행한다.

현재 발생한 `sum = 0 - sum` 이 이전에도 발생했다면 `k` 를 포함한 홀수
개수 subarray 가 있다는 의미이다. 현재 발생한 `1 - sum` 이 이전에도
발생했다면 `k` 를 포함한 짝수 개수 subarray 가 있다는 의미이다.

```
   k: 1
nums: 2 5 1 4 3 6
 sum:     0 1 2 3
          
          0 - 0 = 0 -> [1]
          1 - 0 = 1 -> [1, 4]

   k: 1
nums: 2 5 1 4 3 6
 sum:   1 0 1 2 3
          
        0 - 1 = -1
        1 - 1 = 0   -> [5, 1]

   k: 1
nums: 2 5 1 4 3 6
 sum: 2 1 0 1 2 3
          
      0 - 2 = -2
      1 - 2 = -1
```

따라서 답은 `3` 이다.
 
# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
