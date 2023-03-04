# Problem

[Count the Number of Square-Free Subsets](https://leetcode.com/problems/count-the-number-of-square-free-subsets/)

수열 `nums[]` 가 주어진다. `nums[]` 의 subset 중
원소를 모두 곱한 것이 square-free 인 것의 개수를 구하라.

# Idea

예를 들어 `nums = [3,4,4,5]` 의 경우를 살펴보자.

```
nums: 3 4 4 5
      3         3
            5   5
      3     5   3 * 5
```

따라서 답은 `3` 이다.

다음과 같이 recursive dynamic programming 으로 구현할 만 하다.

문제의 조건에 의해 `1 <= nums[i] <= 30` 이다.

따라서 가능한 소수의 모임은 다음과 같이 `primes` 를 정의한다.

```java
int[] primes = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
```

`nums[i]` 가 주어지면 소인수 분해를 한다. `primes` 를 순회하며 모든
소수에 대해 나누어 떨어지는 지 살펴본다. 결과는 bit seq 로 저장할 수
있다.

임의의 두수 `nums[i], nums[j]` 가 있다고 해보자. 두수를 곱했을 때
square-free 인 지 검증하는 방법은 간단하다. 두수의 소인수 분해 결과를
저장한 bit seq 를 `bm_i, bm_j` 라고 하자. `bm_i & bm_j != 0` 이면
`nums[i] * nums[j]` 에 같은 소수가 2 개 이상 존재한다는 의미이다.
square-free 하지 않다는 말이다.

다음과 같은 함수 `dfs()` 를 정의하여 recursive 하게 구현한다.

```
int dfs(int prodBm, int idx)

return: number of square-free subsets
prodBm: prime number bit seqs of multiplied subsets
   idx: index to be visited
```

또한 다음과 같은 캐쉬 `C` 를 정의하여 memoization 하자.

```
int[][] C = new int[1001][1 << 1]

C[i][j]: i means idx
         j means producted bit mask
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
N: len of nums
```
