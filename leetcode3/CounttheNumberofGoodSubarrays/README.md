# Problem

[Count the Number of Good Subarrays](https://leetcode.com/problems/count-the-number-of-good-subarrays/)

수열 `nums[]`, 숫자 `k = 10` 이 주어진다.

`nums[i] == nums[j] (i < j)` 를 만족하는 `(i, j)` 의 개수가 최소 `k`
개 있을 때 그 subarray 를 good 이라고 하자.

good subarray 의 개수를 구하라.

# Idea

예를 들어 `nums = [3,1,4,3,2,2,4], k = 2` 의 경우를 살펴보자.

```
nums: 3 1 4 3 2 2 4
      3 1 4 3 2 2
      3 1 4 3 2 2 4
        1 4 3 2 2 4
          4 3 2 2 4
```

따라서 답은 `4` 이다.

임의의 subarray 에 같은 숫자가 2 개 이상일 때 pair 의 개수는 다음과
같다.

```
2 2           1 = 0 + 1
2 2 2         3 = 1 + 2
2 2 2 2       6 = 3 + 3
2 2 2 2 2    10 = 6 + 4
```

임의의 subarray 에 같은 숫자가 `n` 개 있다고 하자.
같은 숫자가 `n - 1` 개 일 때 pair 의 개수를 `pair(n - 1)`
이라고 하자. 그렇다면 `pair(n)` 은 다음과 같이 구할 수 있다.

```
pair(n) = pair(n - 1) + (n - 1)
```

인덱스 `i = 0, j = 0` 를 이용하여 sliding window 를 만든다.  good
subarray 를 하나 찾으면 `k >= j (k < n)` 를 만족하는 모든 `k` 에 대해
good subarray 를 만들 수 있다. 즉, `n - j` 만큼 good subarray 를 만들
수 있다.

예를 들어 `nums = [3,1,4,3,2,2,4], k = 2` 의 경우를 다시 살펴보자.
이때 `i = 0, j = 5, n = 7` 이다. 

```
      i
nums: 3 1 4 3 2 2 4
                j
      3 1 4 3 2 2
      3 1 4 3 2 2 4

7 - 5 = 2
```

`Map<Integer, Integer> cntMap = new HashMap<>()` 를 선언하여 `{num,
count}` 를 저장한다. sliding window 안에서 같은 숫자들이 얼만큼 있는지
알 수 있다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
