
- [**Greedy Algorithm: 왜 Optimization의 하위 개념인가?**](#greedy-algorithm-왜-optimization의-하위-개념인가)
- [**Optimization(최적화)의 정의**](#optimization최적화의-정의)
- [**Greedy Algorithm의 정의**](#greedy-algorithm의-정의)
- [**Greedy Algorithm이 Optimization의 하위 개념인 이유**](#greedy-algorithm이-optimization의-하위-개념인-이유)
  - [1) **최적화 문제를 해결하는 특정 전략**](#1-최적화-문제를-해결하는-특정-전략)
  - [2) **특정 문제에서 최적해를 보장**](#2-특정-문제에서-최적해를-보장)
  - [3) **최적화 문제에서 빠른 해결 가능**](#3-최적화-문제에서-빠른-해결-가능)
  - [4) **최적화를 위한 한계와 조건**](#4-최적화를-위한-한계와-조건)
- [**Greedy Algorithm의 최적화 문제 응용 사례**](#greedy-algorithm의-최적화-문제-응용-사례)
  - [1. **그래프 문제**](#1-그래프-문제)
  - [2. **자원 분배 문제**](#2-자원-분배-문제)
  - [3. **압축 문제**](#3-압축-문제)
  - [4. **스케줄링 문제**](#4-스케줄링-문제)
- [**Greedy Algorithm의 장단점**](#greedy-algorithm의-장단점)
  - [**장점**](#장점)
  - [**단점**](#단점)
- [**Greedy Algorithm으로 풀어볼만한 문제들**](#greedy-algorithm으로-풀어볼만한-문제들)
  - [**1. Graph Problems (그래프 문제)**](#1-graph-problems-그래프-문제)
    - [Minimum Spanning Tree (최소 스패닝 트리)](#minimum-spanning-tree-최소-스패닝-트리)
    - [Shortest Path Problems (최단 경로 문제)](#shortest-path-problems-최단-경로-문제)
  - [**2. Scheduling Problems (스케줄링 문제)**](#2-scheduling-problems-스케줄링-문제)
    - [Activity Selection](#activity-selection)
    - [Job Scheduling](#job-scheduling)
  - [**3. Resource Allocation Problems (자원 할당 문제)**](#3-resource-allocation-problems-자원-할당-문제)
    - [Fractional Knapsack Problem](#fractional-knapsack-problem)
    - [Task Assignment](#task-assignment)
  - [**4. Compression Problems (압축 문제)**](#4-compression-problems-압축-문제)
    - [Huffman Encoding](#huffman-encoding)
  - [**5. Interval Problems (구간 문제)**](#5-interval-problems-구간-문제)
    - [Interval Covering](#interval-covering)
    - [Maximum Number of Non-overlapping Intervals](#maximum-number-of-non-overlapping-intervals)
  - [**6. String Problems (문자열 문제)**](#6-string-problems-문자열-문제)
    - [Lexicographically Smallest Subsequence](#lexicographically-smallest-subsequence)
  - [**7. Money and Coin Problems (돈과 동전 문제)**](#7-money-and-coin-problems-돈과-동전-문제)
    - [Coin Change (Greedy Variant)](#coin-change-greedy-variant)
  - [**8. Game Problems (게임 문제)**](#8-game-problems-게임-문제)
    - [Nim Game](#nim-game)
    - [Stone Game Variants](#stone-game-variants)
  - [**9. Tournament Problems (토너먼트 문제)**](#9-tournament-problems-토너먼트-문제)
    - [Optimal Matchups](#optimal-matchups)
  - [**10. Miscellaneous Problems (기타 문제)**](#10-miscellaneous-problems-기타-문제)
    - [Minimize Cash Flow](#minimize-cash-flow)
    - [Maximize Meeting Rooms Usage](#maximize-meeting-rooms-usage)
- [**결론**](#결론)

------

# **Greedy Algorithm: 왜 Optimization의 하위 개념인가?**

**Greedy Algorithm**은 최적화 문제를 해결하기 위한 **특정한 접근 방식**으로, Optimization의 하위 개념으로 간주됩니다. 이는 Greedy Algorithm이 **현재 단계에서 가장 최선의 선택**을 반복적으로 수행하여 전체 문제의 해를 구하려는 알고리즘 설계 기법이기 때문입니다.

---

# **Optimization(최적화)의 정의**

**Optimization(최적화)**는 주어진 제약 조건 하에서 **최대값** 또는 **최소값**을 구하는 문제를 다룹니다.  
예를 들어:
- 배낭 문제: 배낭의 용량 내에서 최대 가치를 얻는 조합 찾기.
- 그래프 문제: 최소 비용으로 연결하는 스패닝 트리를 구하기.

최적화 문제의 목표는 **특정 기준**을 만족하는 해를 찾는 것이며, 이를 해결하기 위해 다양한 접근 방법(알고리즘)이 사용됩니다.
- **접근 방법 예시**:
  - Greedy Algorithm
  - Dynamic Programming
  - Divide and Conquer

---

# **Greedy Algorithm의 정의**

**Greedy Algorithm**은 **현재 상태에서 가장 최선이라고 판단되는 선택(Locally Optimal Choice)**을 반복적으로 수행하여 전체 문제의 해를 구하려는 알고리즘 설계 기법입니다.

- **특징**:
  - 매 단계에서 최적 선택을 함.
  - 선택이 확정되면 되돌리지 않음(Non-reversible).
  - 전역적으로 최적해를 보장하는 문제에서 효과적.

- **핵심 아이디어**:
  - "현재 최적이 전체적으로도 최적일 것"이라는 가정 하에 동작.

---

# **Greedy Algorithm이 Optimization의 하위 개념인 이유**

## 1) **최적화 문제를 해결하는 특정 전략**
Greedy Algorithm은 최적화 문제를 해결하기 위한 전략 중 하나입니다.  
최적화 문제의 목표는 특정 기준(예: 최대값, 최소값, 최소 비용)을 만족하는 해를 찾는 것이며, Greedy Algorithm은 이 목표를 달성하기 위한 효율적인 접근 방식 중 하나로 사용됩니다.

- **예제 1: Kruskal's Algorithm (Minimum Spanning Tree)**  
  - **목표**: 최소 비용으로 모든 노드를 연결하는 트리 구성(최적화 문제).  
  - **접근법**: 가장 작은 가중치의 간선을 반복적으로 선택하여 트리를 구성.

- **예제 2: Fractional Knapsack Problem**  
  - **목표**: 배낭의 용량을 초과하지 않으면서 최대 가치를 얻기.  
  - **접근법**: 단위 무게당 가치가 가장 높은 물건을 먼저 선택.

---

## 2) **특정 문제에서 최적해를 보장**
Greedy Algorithm은 다음과 같은 속성을 가진 문제에서 **최적화 문제의 해법**으로 효과적입니다:

1. **Greedy Choice Property**:
   - 현재 단계에서의 최적 선택이 전체 문제에서도 최적임을 보장.

2. **Optimal Substructure**:
   - 문제의 최적 해가 하위 문제의 최적 해로 구성될 수 있음.  
   (Dynamic Programming과 유사하지만, Greedy는 중복 계산을 고려하지 않음).

---

## 3) **최적화 문제에서 빠른 해결 가능**
Greedy Algorithm은 복잡한 최적화 문제를 해결하는 데 간단하고 효율적인 방법을 제공합니다.
- 시간 복잡도가 일반적으로 낮음(O(n) 또는 O(n log n)).  
- 예: Huffman Encoding(O(n log n)), Kruskal’s Algorithm(O(E log E)).

---

## 4) **최적화를 위한 한계와 조건**
Greedy Algorithm은 모든 최적화 문제에서 동작하지 않습니다.
- 모든 문제에 대해 전역 최적해를 보장하지는 않음.  
- 특정 문제는 **Greedy Choice Property**와 **Optimal Substructure**를 만족해야만 동작.  
  예: Fractional Knapsack은 가능하지만, 0/1 Knapsack은 불가능.

---

# **Greedy Algorithm의 최적화 문제 응용 사례**

## 1. **그래프 문제**
- **Minimum Spanning Tree**:
  - Kruskal’s Algorithm, Prim’s Algorithm.
- **Shortest Path**:
  - Dijkstra’s Algorithm.

## 2. **자원 분배 문제**
- **Fractional Knapsack**: 단위 가치가 높은 물건을 우선 선택.
- **Activity Selection**: 가장 빨리 끝나는 활동을 반복적으로 선택.

## 3. **압축 문제**
- **Huffman Encoding**: 가장 빈도수가 낮은 두 문자를 반복적으로 병합하여 최적의 이진 트리 생성.

## 4. **스케줄링 문제**
- **Job Scheduling**: 작업을 완료하기 위한 최소 시간 계산.

---

# **Greedy Algorithm의 장단점**

## **장점**
1. **단순성**:  
   - 알고리즘 설계가 직관적이며 간단.
2. **효율성**:  
   - 많은 경우 시간 복잡도가 낮음.
3. **적용성**:  
   - 특정 유형의 최적화 문제에서 효과적.

## **단점**
1. **전역 최적 보장 어려움**:  
   - Greedy Choice Property와 Optimal Substructure가 없는 문제에서는 부적합.
2. **되돌릴 수 없음**:  
   - 선택이 확정되면 수정 불가.

---

# **Greedy Algorithm으로 풀어볼만한 문제들**

Greedy Algorithm은 최적화 문제에서 효율적이고 직관적인 해결책을 제공할 수 있습니다. 아래는 문제 유형별로 Greedy Algorithm을 적용할 수 있는 대표적인 문제들을 분류한 목록입니다.

---

## **1. Graph Problems (그래프 문제)**

### Minimum Spanning Tree (최소 스패닝 트리)
- **Kruskal's Algorithm**: 간선을 가중치 기준으로 정렬하여 트리를 구성.
- **Prim's Algorithm**: 시작 노드에서 가장 가까운 노드를 확장하며 트리 구성.

### Shortest Path Problems (최단 경로 문제)
- **Dijkstra's Algorithm**: 가중치가 비음수인 그래프에서 최단 경로 계산.

---

## **2. Scheduling Problems (스케줄링 문제)**

### Activity Selection
- 문제: 활동의 시작과 종료 시간이 주어졌을 때, 가장 많은 활동을 선택.
- 접근법: 종료 시간이 가장 빠른 활동을 먼저 선택.

### Job Scheduling
- 문제: 작업의 완료 시간을 최소화하거나 작업 이익을 극대화.
- 접근법: 이익이 높은 작업 또는 마감 시간이 빠른 작업을 우선 선택.

---

## **3. Resource Allocation Problems (자원 할당 문제)**

### Fractional Knapsack Problem
- 문제: 단위 무게당 가치가 주어진 물건들을 배낭 용량 내에서 최대 가치를 얻도록 선택.
- 접근법: 단위 무게당 가치가 높은 물건을 우선 선택.

### Task Assignment
- 문제: 작업을 작업자에게 할당할 때 총 비용을 최소화.
- 접근법: 비용이 가장 적은 작업을 우선 할당.

---

## **4. Compression Problems (압축 문제)**

### Huffman Encoding
- 문제: 주어진 문자들의 빈도수에 따라 최적의 이진 트리 생성.
- 접근법: 빈도가 낮은 두 문자를 반복적으로 병합하여 트리 생성.

---

## **5. Interval Problems (구간 문제)**

### Interval Covering
- 문제: 주어진 구간을 최소한의 선택으로 덮을 수 있는 구간 집합 선택.
- 접근법: 시작점 기준 정렬 또는 종료점 기준 정렬 후 선택.

### Maximum Number of Non-overlapping Intervals
- 문제: 겹치지 않는 가장 많은 구간 선택.
- 접근법: 종료 시간이 가장 빠른 구간부터 선택.

---

## **6. String Problems (문자열 문제)**

### Lexicographically Smallest Subsequence
- 문제: 주어진 문자열에서 사전순으로 가장 작은 부분 수열 생성.
- 접근법: 사전순으로 작은 문자를 선택하며 진행.

---

## **7. Money and Coin Problems (돈과 동전 문제)**

### Coin Change (Greedy Variant)
- 문제: 주어진 금액을 최소한의 동전 개수로 표현.
- 접근법: 가장 큰 단위의 동전을 먼저 선택.  
  (단, Greedy가 항상 최적해를 보장하지는 않음. 예: 동전 단위가 1, 3, 4인 경우)

---

## **8. Game Problems (게임 문제)**

### Nim Game
- 문제: 돌더미에서 돌을 제거하며 최적의 전략으로 승리.
- 접근법: 남은 돌의 개수를 최적 상태로 유지.

### Stone Game Variants
- 문제: 두 플레이어가 돌을 번갈아 제거하며 점수를 최대로 얻기.
- 접근법: 현재 가장 큰 점수를 얻을 수 있는 돌 선택.

---

## **9. Tournament Problems (토너먼트 문제)**

### Optimal Matchups
- 문제: 두 팀 간의 매치업에서 가장 적은 점수 차이를 만드는 매칭.
- 접근법: 실력이 가까운 선수끼리 매칭.

---

## **10. Miscellaneous Problems (기타 문제)**

### Minimize Cash Flow
- 문제: 주어진 거래 네트워크에서 최소 거래 횟수로 빚을 정산.
- 접근법: 최대 부채를 가진 사람과 최대 수익을 가진 사람 사이에서 거래.

### Maximize Meeting Rooms Usage
- 문제: 주어진 시간대에 가능한 많은 회의를 수용할 수 있는 방 배정.
- 접근법: 가장 일찍 끝나는 회의를 우선 배치.

---

# **결론**

Greedy Algorithm은 **최적화 문제의 해결 전략 중 하나**로, 특정 조건을 만족하는 문제에서 빠르고 효율적인 해법을 제공합니다.  
그러나 모든 최적화 문제에 적합하지 않으며, **문제의 특성**을 만족할 때만 전역 최적해를 보장합니다.  
따라서, Greedy Algorithm은 **최적화의 하위 개념**으로 간주되며, 알고리즘 설계와 최적화 문제 해결에서 중요한 위치를 차지합니다.
