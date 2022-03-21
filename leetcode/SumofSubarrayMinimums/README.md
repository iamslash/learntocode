- [Problem](#problem)
- [Brute Force](#brute-force)
  - [Idea](#idea)
  - [Implementation](#implementation)
  - [Complexity](#complexity)
- [Hash Map](#hash-map)
  - [Implementation](#implementation-1)
  - [Complexity](#complexity-1)
- [Mono Stack](#mono-stack)
  - [Idea](#idea-1)
  - [Implementation](#implementation-2)
  - [Complexity](#complexity-2)
----

# Problem

[Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/)

수열 `A[]` 가 주어진다. 모든 부분수열의 최소 값들을 더한 것을
구하는 문제이다.

# Brute Force

## Idea

예를 들어 `A = 3 1 2 4` 의 경우를 살펴보자.

```
A: 3 1 2 4
   3          3
   3 1        1
   3   2      1
   3     4    1
     1        1
     1 2      1
     1   4    1
       2      2
       2 4    2
         4    4
```

따라서 답은 `17` 이다.

임의의 숫자 `A[2]` 를 살펴보자.

```
       i
A: 3 1 2 4

      count of subarray which ends with A[2] minimum: 1 ({2})
count of subarray which starts with min A[2] minimum: 2 ({2}, {2, 4})
                 count of subarray whose min is A[2]: 1 * 2 = 2 ({2}, {2, 4})
```

따라서 다음과 같은 공식을 발견할 수 있다.

```
  count of subarray which ends with A[i] minimum: l
count of subarray which starts with A[i] minimum: r
             count of subarray whose min is A[i]: l * r
```

`long ans = 0` 을 선언하여 답을 저장한다. 인덱스 `i` 를 `[0, n)` 동안 순회하면서 다음을 반복한다.

* `int l = -1` 을 선언하고 `A[i]` 로 끝나는 subarray 중 `A[i]` 가 최소값인 것들의 개수를 저장한다.
* `int r = -1` 을 선언하고 `A[i]` 로 시작하는 subarray 중 `A[i]` 가 최소값인 것들의 개수를 저장한다.
* `ans = l * r` 을 저장한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

`l, r` 을 빨리 찾을 수 있다면 time complexity 를 개선할 수 있다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N) O(1)
```

# Hash Map

`long ans = 0` 을 선언하여 답을 저장한다.

`int[] lefts = new int[n]` 을 선언한다. `A[i]` 로 끝나면서 `A[i]` 가 최소값으로 사용된 subarray 를 생각해 보자. 그 subarray 들 중 가장 긴 것의 시작 인덱스를 `lefts[i]` 에 저장한다. 

`int[] rights = new int[n]` 을 선언한다. `A[i]` 로 시작하면서 `A[i]` 가 최소값으로 사용된 subarray 를 생각해 보자. 그 subarray 들 중 가장 긴 것의 끝 인덱스를 `rights[i]` 에 저장한다.

이제 다음과 같은 수식을 발견할 수 있다.

```
  count of subarray which ends with A[i] minimum: i - lefts[i]
count of subarray which starts with A[i] minimum: rights[i] - i
             count of subarray whose min is A[i]: (i - lefts[i]) * (rights[i] - i)
```

예를 들어 `nums = 3 1 2 4` 의 풀이과정은 다음과 같다.

```
         i
   nums: 3 1 2 4
           j
  lefts: - - 1 2 
 rights: 1 4 4 4
         i
         3 * (0 - (-1)) * (1 - 0) = 3
         1 * (1 - (-1)) * (4 - 1) = 6
         2 * (2 - 1)    * (4 - 2) = 4
         4 * (3 - 2)    * (4 - 3) = 4
```

따라서 답은 `17` 이다.

다음은 `nums = 3 1 2 4 1 2` 의 풀이과정이다.

```
         i
   nums: 3 1 2 4 1
           j
  lefts: - - 1 2 1 
 rights: 1 5 4 4 5
         i
         3 * (0 - (-1)) * (1 - 0) = 3
         1 * (1 - (-1)) * (5 - 1) = 6
         2 * (2 - 1)    * (4 - 2) = 4
         4 * (3 - 2)    * (4 - 3) = 4
         1 * (4 - 1)    * (5 - 4) = 3
```

따라서 답은 `21` 이다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N) O(N)
```

# Mono Stack

## Idea

`long ans = 0` 을 선언하여 답을 저장한다.

`int[] lefts = new int[n]` 을 선언하여 `lefts[i]` 에 `A[i]` 로 끝나는 subarray 중 `A[i]` 가 최소값인 것들의 개수를 저장한다.

`Stack<Integer> leftStack = new Stack<>()` 을 선언하여 `lefts[i]` 를 채우는데 사용한다.

`int[] rights = new int[n]` 을 선언하여 `rights[i]` 에 `A[i]` 로 시작하는 subarray 중 `A[i]` 가 최소값인 것들의 개수를 저장한다.

`Stack<Integer> rightStack = new Stack<>()` 을 선언하여 `rights[i]` 를 채우는데 사용한다.

인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `ans += lefts[i] * rights[i]` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

구현이 복잡하고 시간복잡도가 좋지 않다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N) O(N)
```
