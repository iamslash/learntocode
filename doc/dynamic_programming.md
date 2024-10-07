- [Abstract](#abstract)
- [Concepts](#concepts)
- [Problems](#problems)
  - [Knapsack-Like Problems:](#knapsack-like-problems)
  - [Coin Change Variants:](#coin-change-variants)
  - [Partitioning Problems:](#partitioning-problems)
  - [Sequence Alignment/Matching:](#sequence-alignmentmatching)
  - [Counting Paths and Ways:](#counting-paths-and-ways)
  - [Interval Scheduling and Profit Maximization:](#interval-scheduling-and-profit-maximization)
  - [String Problems:](#string-problems)
  - [Grid Problems:](#grid-problems)

-----

# Abstract

- 동적 계획법에 대해 적어본다.

# Concepts

* overlapping subproblems
  * 중복되는 부분문제를 overlapping suproblems 이라고 한다. 캐시를 이용해 최적화 할 수 있다.

* optimal substructure
  * 어떤 문제가 부분문제로 나누어지고 그 부분문제는 다시 그 부분문제를 이용해서 최적의 해결책을 찾을 수 있다면 그 문제는 optimal substructure 를 가지고 있다고 한다.
  * [TRIANGLEPATH | algospot](https://algospot.com/judge/problem/read/TRIANGLEPATH) 처럼 부분문제의 최대값을 취하는 방법으로 최적의 해결책을 갖는 형태의 문제가 해당된다.
  * [optimal substructure | wikipedia](https://en.wikipedia.org/wiki/Optimal_substructure)
  * [dynamic programming |wikipedia](https://en.wikipedia.org/wiki/Dynamic_programming)

* markov chain
  * 어떤 한 실험을 반복하는데 각 실험에서의 결과는 오직 바로 직전의 실험결과에서만 영향을 받는 것을 markov chain 혹은 markov process 라고 한다. 오늘 내가 담배피면, 내일 담배 필 확률이 `0.8`, 내일 안 필 확률이 `0.2` 오늘 내가 담배 안 피면, 내일 담배 필 확률이 `0.5`, 내일 안 필 확률이 `0.5` 라고 하자. 언급한 예처럼 임의 결과가 바로 전의 결과에만 영향을 받는 것을 말한다.
  * 또한 다음과 같은 특징을 갖는 모델 역시 markov chain 에 해당한다. 첫째 유한개의 상태가 있다. 둘째 매 시간마다
  상태가 변경된다. 셋째 어떤 상태 a 에서 다른 상태 b 로 이동할 확률은 현재 상태 a 에 의해 좌우된다. a 이전에 어느 상태에 있었는지, 현재 시간은 얼마인지 등은 영향을 주지 않는다.
  * [NUMB3RS | algospot](https://algospot.com/judge/problem/read/NUMB3RS) 는 markov chain 의 대표적인 예이다.

# Problems

## Knapsack-Like Problems:
  - 0/1 Knapsack 
  - Unbounded Knapsack (similar to 0/1 knapsack but you can use an item multiple times)
  - Subset Sum Problem (checking if a subset of numbers sums to a particular value)

## Coin Change Variants:
  - Coin Change (find the minimum number of coins that sum up to a given amount)
  - Coin Change 2 (find the number of ways to make a given amount using coins)

## Partitioning Problems:
  - Partition Equal Subset Sum (determine if you can partition a set into two subsets with equal sum)
  - Palindrome Partitioning (find the minimum number of cuts to partition a string into palindromes)

## Sequence Alignment/Matching:

  - Longest Common Subsequence (LCS) (find the longest subsequence common to two sequences)
  - Edit Distance (find the minimum number of operations required to convert one string into another)
  - Longest Increasing Subsequence (LIS) (find the longest increasing subsequence in an array)

## Counting Paths and Ways:

  - Unique Paths (find the number of ways to reach the bottom-right corner of a grid from the top-left)
  - Staircase Problem (count how many ways you can climb a staircase with n steps if you can take 1 or 2 steps at a time)

## Interval Scheduling and Profit Maximization:

  - Weighted Interval Scheduling (find the maximum profit subset of non-overlapping intervals)
  - Rod Cutting (maximize profit by cutting a rod into pieces of different lengths)

## String Problems:

  - Longest Palindromic Subsequence (find the longest subsequence in a string that is also a palindrome)
  - Longest Palindromic Substring (find the longest contiguous substring that is a palindrome)

## Grid Problems:

  - Maximum Path Sum in a Grid (find the path from top-left to bottom-right that has the maximum sum of numbers)
  - Minimum Path Sum in a Grid (find the path with the minimum sum of numbers)
