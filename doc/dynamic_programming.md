- [**Dynamic Programming (DP): 창시와 역사**](#dynamic-programming-dp-창시와-역사)
- [**Dynamic Programming (DP)의 개념**](#dynamic-programming-dp의-개념)
  - [**DP의 두 가지 핵심 조건**](#dp의-두-가지-핵심-조건)
- [**Dynamic Programming의 구현 방식**](#dynamic-programming의-구현-방식)
  - [**1. Memoization (Top-Down Approach)**](#1-memoization-top-down-approach)
  - [**2. Tabulation (Bottom-Up Approach)**](#2-tabulation-bottom-up-approach)
- [**Memoization vs. Tabulation**](#memoization-vs-tabulation)
- [**Markov Chain과 Dynamic Programming**](#markov-chain과-dynamic-programming)
  - [**Markov Chain의 정의**](#markov-chain의-정의)
  - [**Markov Chain의 특징**](#markov-chain의-특징)
    - [**Markov Chain의 간단한 예**](#markov-chain의-간단한-예)
  - [**Markov Decision Processes (MDPs)와 Dynamic Programming**](#markov-decision-processes-mdps와-dynamic-programming)
    - [**MDPs의 구성 요소**](#mdps의-구성-요소)
  - [**Dynamic Programming 기법이 활용되는 이유**](#dynamic-programming-기법이-활용되는-이유)
  - [**Markov Chain의 대표적인 문제**](#markov-chain의-대표적인-문제)
  - [**Markov Chain과 Dynamic Programming의 관계 정리**](#markov-chain과-dynamic-programming의-관계-정리)
- [**Problems**](#problems)
  - [Knapsack-Like Problems:](#knapsack-like-problems)
  - [Coin Change Variants:](#coin-change-variants)
  - [Partitioning Problems:](#partitioning-problems)
  - [Sequence Alignment/Matching:](#sequence-alignmentmatching)
  - [Counting Paths and Ways:](#counting-paths-and-ways)
  - [Interval Scheduling and Profit Maximization:](#interval-scheduling-and-profit-maximization)
  - [String Problems:](#string-problems)
  - [Grid Problems:](#grid-problems)
  - [Game Theory Problems:](#game-theory-problems)
  - [Probabilistic Problems:](#probabilistic-problems)
  - [Graph and DP Problems:](#graph-and-dp-problems)
  - [Tree-Based Problems:](#tree-based-problems)

-----

# **Dynamic Programming (DP): 창시와 역사**

**Dynamic Programming (DP)**은 1950년대에 **Richard Bellman**에 의해 제안되었습니다. 그는 복잡한 최적화 문제를 해결하기 위해 이 접근법을 개발했습니다.

- **창시자**: Richard Bellman  
- **시기**: 1953년  
- **목적**: 
  - 공학, 물리학, 경제학 등에서 최적화 문제를 해결하기 위한 방법론 개발.
  - "Dynamic Programming"이라는 용어는 "Dynamic"이란 단어가 당시에 긍정적으로 여겨졌기 때문에 사용되었습니다.

Bellman의 DP 아이디어는 **최적 부분 구조**와 **중복 부분 문제**를 가진 문제를 효율적으로 해결하기 위한 기본 개념을 제공했습니다. 오늘날 DP는 알고리즘 설계와 최적화 문제 해결의 핵심 도구로 자리 잡았습니다.

---

# **Dynamic Programming (DP)의 개념**

**Dynamic Programming (DP)**은 복잡한 문제를 **더 작은 하위 문제(subproblems)**로 나누어 해결하고, 결과를 저장하여 **중복 계산을 방지**하는 알고리즘 설계 기법입니다.

## **DP의 두 가지 핵심 조건**
1. **Optimal Substructure (최적 부분 구조)**:
   - 문제의 최적 해가 하위 문제의 최적 해로 구성될 수 있음.
   - 예: 피보나치 수열, 최단 경로 문제.

2. **Overlapping Subproblems (중복 부분 문제)**:
   - 동일한 하위 문제가 여러 번 계산됨.
   - 예: 피보나치 수열에서 `F(3)`은 `F(4)`와 `F(5)` 계산 시 반복적으로 등장.

---

# **Dynamic Programming의 구현 방식**

Dynamic Programming은 하위 문제의 결과를 저장하는 방식에 따라 두 가지로 구현됩니다:

## **1. Memoization (Top-Down Approach)**

**Memoization**은 재귀 호출을 기반으로 하위 문제를 해결하며, 그 결과를 **캐싱**하여 중복 계산을 방지하는 방식입니다.

- **특징**:
  - Top-Down 방식: 문제를 큰 문제에서 시작하여 필요한 하위 문제만 해결.
  - Lazy Evaluation (필요할 때만 계산).
  - 재귀 호출로 인해 **스택 메모리**를 사용.

- **장점**:
  - 구현이 직관적이고 간단함.
  - 필요한 하위 문제만 계산하므로 효율적일 수 있음.

- **단점**:
  - 깊은 재귀 호출 시 스택 오버플로우 위험.

- **예제: 피보나치 수열 (Memoization)**

```java
import java.util.HashMap;

public class FibonacciMemoization {
    private static HashMap<Integer, Long> memo = new HashMap<>();

    public static long fibonacci(int n) {
        if (n <= 1) return n;
        if (memo.containsKey(n)) return memo.get(n);

        long result = fibonacci(n - 1) + fibonacci(n - 2);
        memo.put(n, result);
        return result;
    }

    public static void main(String[] args) {
        System.out.println(fibonacci(50)); // Output: 12586269025
    }
}
```

## **2. Tabulation (Bottom-Up Approach)**

**Tabulation**은 반복문을 사용하여 작은 하위 문제부터 순차적으로 계산하고, 결과를 **테이블**에 저장하는 방식입니다.

- **특징**:
  - Bottom-Up 방식: 작은 하위 문제를 먼저 계산한 후, 이를 이용해 상위 문제 해결.
  - Eager Evaluation (모든 하위 문제를 미리 계산).
  - 재귀 호출 없이 테이블만 사용하므로 메모리 사용이 효율적.

- **장점**:
  - 스택 오버플로우 위험 없음.
  - 반복문 기반으로 일정한 성능 보장.

- **단점**:
  - 모든 하위 문제를 계산하므로 불필요한 계산이 있을 수 있음.

- **예제: 피보나치 수열 (Tabulation)**

```java
public class FibonacciTabulation {
    public static long fibonacci(int n) {
        if (n <= 1) return n;

        long[] dp = new long[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    public static void main(String[] args) {
        System.out.println(fibonacci(50)); // Output: 12586269025
    }
}
```

# **Memoization vs. Tabulation**

| **특징**              | **Memoization**                           | **Tabulation**                           |
|-----------------------|-------------------------------------------|-------------------------------------------|
| **접근 방식**         | Top-Down (재귀 호출 기반)                 | Bottom-Up (반복문 기반)                   |
| **계산 순서**         | 필요한 하위 문제만 계산 (Lazy Evaluation)  | 모든 하위 문제를 미리 계산 (Eager Evaluation) |
| **메모리 사용**       | 재귀 호출로 스택 메모리 사용               | 테이블만 사용 (스택 사용 없음)            |
| **구현 난이도**       | 직관적이고 간단함                         | 테이블 정의와 반복문 작성 필요             |
| **성능**              | 필요할 때만 계산하므로 효율적일 수 있음    | 모든 하위 문제를 계산하므로 균일한 속도    |
| **스택 오버플로우 위험**| 있음                                     | 없음                                     |


# **Markov Chain과 Dynamic Programming**

**Markov Chain**은 확률적 시스템에서 상태가 시간에 따라 전환되는 과정을 모델링하는 수학적 구조입니다. **Dynamic Programming (DP)**과 직접적인 관계는 없지만, **Markov Decision Processes (MDPs)**를 통해 연결됩니다. MDP는 Markov Chain의 특성을 활용하여 최적의 의사결정 전략을 설계하는 데 Dynamic Programming 기법을 사용합니다.

---

## **Markov Chain의 정의**
- Markov Chain은 **Markov Property**를 만족하는 상태 전이 모델입니다.  
  즉, **현재 상태가 미래 상태를 결정하는 데 필요한 모든 정보를 제공**하며, 과거 상태는 영향을 미치지 않습니다.
- **Markov Property**:  
  \[
  P(S_{t+1} \mid S_t, S_{t-1}, ..., S_0) = P(S_{t+1} \mid S_t)
  \]

---

## **Markov Chain의 특징**
1. **유한 상태 공간**: 가능한 상태의 집합이 유한하거나 가산 무한함.
2. **상태 전이 확률**: 상태 \(a\)에서 상태 \(b\)로 이동할 확률은 현재 상태 \(a\)에만 의존.
3. **상태 전이 행렬**: 모든 상태 전이 확률을 행렬로 표현.

### **Markov Chain의 간단한 예**
담배를 피우는 습관에 대한 간단한 모델을 고려하자:
- 오늘 담배를 피우면:
  - 내일 담배를 필 확률: \(0.8\)
  - 내일 담배를 안 필 확률: \(0.2\)
- 오늘 담배를 안 피우면:
  - 내일 담배를 필 확률: \(0.5\)
  - 내일 담배를 안 필 확률: \(0.5\)

이와 같이 **현재 상태(오늘의 행동)**가 **미래 상태(내일의 행동)**에만 영향을 미치는 시스템이 Markov Chain에 해당합니다.

---

## **Markov Decision Processes (MDPs)와 Dynamic Programming**
Markov Chain이 확률적 상태 전이 모델이라면, **Markov Decision Processes (MDPs)**는 상태에서 **결정 가능한 행동**을 추가한 모델입니다. MDP는 최적의 정책(policy)을 찾는 문제를 해결하며, 이 과정에서 **Dynamic Programming** 기법을 활용합니다.

### **MDPs의 구성 요소**
1. **상태 (States)**: 시스템이 가질 수 있는 모든 상태의 집합.
2. **행동 (Actions)**: 각 상태에서 선택 가능한 행동.
3. **전이 확률 (Transition Probabilities)**: 행동에 따른 상태 전이 확률.
4. **보상 함수 (Reward Function)**: 특정 상태와 행동 조합에 대해 주어지는 보상.
5. **정책 (Policy)**: 각 상태에서 어떤 행동을 선택할지 정의하는 전략.

---

## **Dynamic Programming 기법이 활용되는 이유**
MDPs의 목표는 **누적 보상(expected return)을 최대화하는 최적의 정책**을 찾는 것입니다. 이를 위해 DP의 핵심 기법이 사용됩니다:

1. **벨만 방정식 (Bellman Equation)**:
   - 현재 상태의 가치는 보상과 미래 가치의 합으로 표현됩니다.
   - \[
     V(s) = \max_a \left[ R(s, a) + \gamma \sum_{s'} P(s' \mid s, a) V(s') \right]
     \]
     여기서:
     - \(V(s)\): 상태 \(s\)의 가치(value).
     - \(R(s, a)\): 상태 \(s\)에서 행동 \(a\)를 선택할 때 얻는 보상.
     - \(\gamma\): 할인율(discount factor).
     - \(P(s' \mid s, a)\): 상태 \(s\)에서 \(a\)를 선택했을 때 \(s'\)로 전이할 확률.

2. **정책 반복 (Policy Iteration)**:
   - 정책을 평가하고 개선하는 과정을 반복하여 최적 정책을 찾음.

3. **값 반복 (Value Iteration)**:
   - 벨만 방정식을 반복적으로 계산하여 최적의 가치 함수를 도출.

---

## **Markov Chain의 대표적인 문제**
- **[NUMB3RS | algospot](https://algospot.com/judge/problem/read/NUMB3RS)**:  
  이 문제는 Markov Chain의 전이 확률과 상태 모델링을 사용하여 특정 상태에 도달할 확률을 계산하는 대표적인 예입니다.  
  문제에서 다루는 전이 확률과 DP를 결합하여 해결 가능합니다.

---

## **Markov Chain과 Dynamic Programming의 관계 정리**
1. Markov Chain은 **확률적 상태 전이 모델**이며, 현재 상태가 미래 상태를 결정합니다.
2. Dynamic Programming은 Markov Decision Processes(MDPs)의 최적 정책을 찾는 데 사용됩니다.
3. MDP는 Markov Chain에 행동과 보상을 추가한 모델로, Bellman 방정식, 정책 반복, 값 반복 같은 DP 기법을 활용하여 최적화 문제를 해결합니다.

이러한 관계를 통해 Markov Chain과 Dynamic Programming은 확률적 최적화 및 의사결정 문제에서 긴밀히 연결됩니다.

# **Problems**

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

## Game Theory Problems:
  - Nim Game (determine the winner given the current state of the game using the optimal strategy)
  - Grundy Numbers (used in generalizations of Nim to compute the optimal move)
  - Stone Game (determine the winner in a game where two players take turns optimally removing stones)

## Probabilistic Problems:
  - NUMB3RS (find the probability of being in a specific state after a given number of transitions in a Markov chain)
  - Die Throw Problem (determine the probability of achieving a target sum with a given number of dice rolls)

## Graph and DP Problems:
  - Longest Path in a DAG (find the longest path in a directed acyclic graph)
  - Hamiltonian Path (determine if a path exists that visits every vertex exactly once)
  - Travelling Salesman Problem (find the shortest possible route that visits every city and returns to the origin city)

## Tree-Based Problems:
  - Binary Tree Maximum Path Sum (find the maximum path sum in a binary tree)
  - Diameter of a Binary Tree (find the length of the longest path between any two nodes in the tree)
  - Unique Binary Search Trees (count the number of unique BSTs that can be formed with n nodes)
