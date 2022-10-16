- [Abstract](#abstract)
- [How To Loop Subarray](#how-to-loop-subarray)
- [Number Of Subarrays](#number-of-subarrays)
- [Number Of Total Min Usages](#number-of-total-min-usages)
- [Number Of Total Max Usages](#number-of-total-max-usages)

----

# Abstract

subarray 의 특징들을 몇가지 정리해 본다.

# How To Loop Subarray

subarray 를 `i, j` 인덱스를 이용하여 순회하는 방법은 다음과 같이 2 가지 방법이 있다.

첫번째 방법

```
// nums: 2 3 3 2 2
//       2
//       2 3
//       2 3 3
//       2 3 3 2
//       2 3 3 2 2
//         3 
//         3 3
//         3 3 2
//         3 3 2 2
//           3
//           3 2
//           3 2 2
//             2 
//             2 2
//               2
```

두번째 방법

```
// nums: 2 3 3 2 2
//       2
//         3
//           3
//             2
//               2
//       2 3
//         3 3
//           3 2
//             2 2
//       2 3 3
//         3 3 2
//           3 2 2
//       2 3 3 2
//         3 3 2 2
//       2 3 3 2 2
```

어느 쪽 방법이든 탐색한 subarray 의 개수는 `1 + 2 + 3 + 4 + 5 = 15` 이다.

* [L](/leetcode3/KDivisibleElementsSubarrays/) | [K Divisible Elements Subarrays](https://leetcode.com/problems/k-divisible-elements-subarrays/)

# Number Of Subarrays

원소의 개수가 `n` 개 라고 하면 전체 subarray 의 개수는 `n * (n + 1) / 2` 와 같다.
예를 들어 다음과 같이 `[1, 2, 3]` 의 경우를 살펴보자.

```
nums: 1 2 3
      1
      1 2
      1 2 3
        2 
        2 3
          3

3 * 4 / 2 = 6
```

# Number Of Total Min Usages

subarray 의 각 원소가 최소값으로 사용되었을 때의 횟수는 전체 subarray 의 개수와 같다.
예를 들어 다음과 같이 `[1, 2, 3]` 의 경우를 살펴보자.

```
nums: 1 2 3    min
      1        1
      1 2      1
      1 2 3    1
        2      2
        2 3    2
          3    3

3 * 4 / 2 = 6

1 이 최소로 사용된 횟수 -- 3
2 가 최소로 사용된 횟수 -- 2
3 이 최소로 사용된 횟수 -- 1
Number of total min usages -- 6
```

# Number Of Total Max Usages

subarray 의 각 원소가 최대값으로 사용되었을 때의 횟수는 전체 subarray 의 개수와 같다.
예를 들어 다음과 같이 `[1, 2, 3]` 의 경우를 살펴보자.

```
nums: 1 2 3    max
      1        1
      1 2      2
      1 2 3    3
        2      2
        2 3    3
          3    3

3 * 4 / 2 = 6

1 이 최대로 사용된 횟수 -- 1
2 가 최대로 사용된 횟수 -- 2
3 이 최대로 사용된 횟수 -- 3
Number of total max usages -- 6
```
