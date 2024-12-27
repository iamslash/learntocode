- [Combinatorial Search: 정의 및 비교](#combinatorial-search-정의-및-비교)
  - [**Combinatorial Search의 개요**](#combinatorial-search의-개요)
  - [**기원**](#기원)
  - [**Combinatorial Search vs. 다른 탐색 기법**](#combinatorial-search-vs-다른-탐색-기법)
  - [**Combinatorial Search의 강점**](#combinatorial-search의-강점)
  - [**예시**](#예시)
  - [Backtracking](#backtracking)
  - [Backtracking vs Branch and Bound: Subset Sum Problem](#backtracking-vs-branch-and-bound-subset-sum-problem)
    - [**문제 정의**](#문제-정의)
    - [**Backtracking으로 해결**](#backtracking으로-해결)
    - [**Branch and Bound으로 해결**](#branch-and-bound으로-해결)
    - [**Backtracking의 상한 계산**](#backtracking의-상한-계산)
      - [**예시**](#예시-1)
    - [**Branch and Bound의 상한과 하한 계산**](#branch-and-bound의-상한과-하한-계산)
      - [**예시**](#예시-2)
    - [**결정적인 차이: 상한과 하한 계산 여부**](#결정적인-차이-상한과-하한-계산-여부)
    - [**비유**](#비유)
    - [**결론**](#결론)
- [Key Concepts in Combinatorial Search](#key-concepts-in-combinatorial-search)
  - [Overview](#overview)
  - [Heuristic](#heuristic)
  - [Metaheuristic](#metaheuristic)
  - [CSP (Constrained Satisfaction Problem)](#csp-constrained-satisfaction-problem)

----

# Combinatorial Search: 정의 및 비교

---

## **Combinatorial Search의 개요**
- **정의**: 조합론적 문제의 해결을 목표로, 가능한 해의 집합(탐색 공간)을 체계적으로 탐색하여 최적 또는 만족스러운 해를 찾는 방법.
- **적용 범위**: 조합 최적화 문제, 퍼즐 문제(N-Queens), 그래프 문제(예: 그래프 색칠하기), 정수 계획 문제 등.

Combinatorial Search는 Exhaustive Search의 일반화된 접근 방식으로, 탐색 공간 축소를 통해 효율성을 높이기 위해 다양한 기법(Backtracking, Branch and Bound 등)을 포함합니다. 이는 특정 시점에 누군가 "발명"했다기보다 필요에 의해 자연스럽게 발전된 개념으로 이해하는 것이 적합합니다.

---

## **기원**
- **초기 기법**: Combinatorial Search는 체계적 탐색 기법(예: 완전 탐색 및 Backtracking)의 연장선에서 발전.
- **역사적 배경**: 
  - **조합론 연구**: 18~19세기 수학자들이 조합론적 문제 탐구.
  - **20세기 중반**: 전산학 발전과 함께 Backtracking, Branch and Bound 등 체계적인 알고리즘 등장.

---

## **Combinatorial Search vs. 다른 탐색 기법**

**Combinatorial Search**는 경우에 따라 **Exhaustive Search**를 포함할 수 있지만, 더 나아가 **Pruning**, **Branch and Bound**, **Backtracking** 등 다양한 최적화 기법을 포함합니다.

**Exhaustive Search**와 **Combinatorial Search**는 탐색 전략이라는 공통된 상위 개념 아래에서, 각각 다른 특성과 역할을 가진 독립적인 개념입니다.
**Combinatorial Search**는 효율성을 목표로 하고, **Exhaustive Search**는 단순함과 완전성을 목표로 합니다.

**Brute Force**는 탐색 전략을 포함한 다양한 문제 해결 방법에 적용되는 일반적인 접근법으로 이해하는 것이 더 적절합니다.

**Pruning** 자체는 특정 탐색 기법에 종속된 개념이 아니라, 탐색 공간 축소를 위한 일반적인 전략입니다. 그러나 **Backtracking**과 B**ranch and Bound**의 핵심적인 요소로 자주 사용되기 때문에 **Backtracking**과 **Branch and Bound** 모두의 하위 개념으로 볼 수도 있습니다. 두 기법의 탐색 공간 축소와 효율성 향상을 위해 필수적인 역할을 합니다. **Backtracking**에서는 조건 기반으로 탐색 공간을 줄이기 위해 **Pruning**이 사용됩니다. **Branch and Bound**에서는 상한과 하한을 기반으로 탐색을 제한하는 **Pruning**이 사용됩니다. 

---

## **Combinatorial Search의 강점**
- **체계적 접근**: 탐색 공간을 체계적으로 살펴봄으로써 모든 경우의 수를 누락 없이 고려.
- **다양한 기법의 융합**: 탐색 공간 축소(Branch and Bound), 조건 기반 탐색(Backtracking) 등을 포함.
- **확장성**: 동적 계획법(Dynamic Programming), 휴리스틱 탐색(A*) 등과 결합 가능.

---

## **예시**
- **N-Queens 문제**: Backtracking과 함께 사용해 모든 가능한 퀸 배치 조합을 탐색.
- **그래프 색칠하기**: 모든 가능한 색 배치 조합을 체계적으로 탐색.

## Backtracking

[backtracking](/doc/backtracking.md)

## Backtracking vs Branch and Bound: Subset Sum Problem

---

### **문제 정의**
- **Subset Sum Problem**: 주어진 정수 배열에서 일부 요소를 선택해 특정 합(sum)을 만들 수 있는지 확인.
- 입력:
  - `nums[]`: 정수 배열.
  - `target`: 목표 합.
- 출력:
  - 가능한 경우: "Found".
  - 불가능한 경우: "Not Found".

---

### **Backtracking으로 해결**
Backtracking은 모든 가능한 부분집합을 탐색하며 조건을 만족하지 않으면 가지치기(Pruning)를 수행합니다.

```java
public class SubsetSumBacktracking {
    public static boolean isSubsetSum(int[] nums, int target, int index, int currentSum) {
        // 가지치기: 현재 합이 목표를 초과하면 탐색 중단
        if (currentSum > target) return false;
        // 목표를 만족하면 종료
        if (currentSum == target) return true;
        // 배열 끝까지 탐색했지만 목표를 만족하지 못한 경우
        if (index == nums.length) return false;

        // 포함하지 않는 경우와 포함하는 경우를 재귀적으로 탐색
        return isSubsetSum(nums, target, index + 1, currentSum) ||
               isSubsetSum(nums, target, index + 1, currentSum + nums[index]);
    }

    public static void main(String[] args) {
        int[] nums = {3, 34, 4, 12, 5, 2};
        int target = 9;

        if (isSubsetSum(nums, target, 0, 0)) {
            System.out.println("Found");
        } else {
            System.out.println("Not Found");
        }
    }
}
```

### **Branch and Bound으로 해결**
Branch and Bound은 현재 합과 "최대 가능한 합(Bound)"을 계산하여 불필요한 탐색을 조기에 중단합니다.

```java
import java.util.LinkedList;
import java.util.Queue;

public class SubsetSumBranchAndBound {
    static class Node {
        int level, currentSum, bound;
        public Node(int level, int currentSum, int bound) { ... }
    }

    public static boolean isSubsetSum(int[] nums, int target) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(0, 0, calculateBound(nums, 0, 0)));

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (node.currentSum > target || node.bound < target) continue;
            if (node.currentSum == target) return true;
            if (node.level == nums.length) continue;

            queue.offer(new Node(node.level + 1, node.currentSum, 
                    calculateBound(nums, node.level + 1, node.currentSum)));
            queue.offer(new Node(node.level + 1, node.currentSum + nums[node.level],
                    calculateBound(nums, node.level + 1, node.currentSum + nums[node.level])));
        }

        return false;
    }

    public static int calculateBound(int[] nums, int level, int currentSum) {
        int bound = currentSum;
        for (int i = level; i < nums.length; i++) bound += nums[i];
        return bound;
    }

    public static void main(String[] args) {
        int[] nums = {3, 34, 4, 12, 5, 2};
        int target = 9;

        if (isSubsetSum(nums, target)) {
            System.out.println("Found");
        } else {
            System.out.println("Not Found");
        }
    }
}
```

---

### **Backtracking의 상한 계산**
- **Backtracking에서 가지치기(Pruning)**는 **상한 계산**만 사용합니다.
  - 즉, 현재 경로가 **문제 조건을 위반(예: target 초과)**하면 탐색을 중단합니다.
- **하한 계산은 하지 않습니다**.
  - Backtracking은 최적해를 찾는 것이 목적이 아니라, 조건을 만족하는 해를 빠르게 찾는 데 집중합니다.
  - 따라서 하한 계산을 통해 탐색 가능성을 판단하지 않습니다.

#### **예시**
- **Subset Sum Problem**:
  - 현재 합이 target을 초과하면 탐색 중단:
    ```java
    if (currentSum > target) return; // 상한 계산
    ```

---

### **Branch and Bound의 상한과 하한 계산**
- **Branch and Bound**는 **상한**과 **하한**을 모두 계산합니다.
  - **상한**: 현재 경로에서 더 진행했을 때 얻을 수 있는 최대 값.
    - 상한이 최적해보다 작으면 탐색 중단.
  - **하한**: 현재 경로에서 더 진행해도 최소한으로 얻을 수 있는 값.
    - 하한이 목표값에 미치지 못하면 탐색 중단.
- 이 두 계산을 통해 **탐색 가능성**과 **최적해 가능성**을 평가하여 더 효율적으로 탐색 공간을 줄입니다.

#### **예시**
- **Subset Sum Problem**:
  - 현재 합이 target을 초과하면 탐색 중단(상한 계산).
  - 현재 합 + 앞으로 가능한 최대 합이 target보다 작으면 탐색 중단(하한 계산):
    ```java
    if (node.currentSum > target || node.bound < target) continue;
    ```

---

### **결정적인 차이: 상한과 하한 계산 여부**

| **특징** | **Backtracking** | **Branch and Bound** |
|-------|-----------------------|-----------|
| **상한 계산** | 상한만 계산하여 조건을 위반하면 탐색 중단. | 상한 계산을 통해 최적해 가능성을 평가. |
| **하한 계산** | 하한 계산 없음. | 하한 계산을 통해 탐색 가능성을 평가. |
| **목적** | 조건을 만족하는 해를 찾는 데 초점. | 최적해를 찾는 데 초점. |
| **효율성** | 상대적으로 덜 효율적(탐색 공간이 더 큼). | 상한과 하한을 모두 활용하여 탐색 공간을 더 효과적으로 축소. |

---

### **비유**
- **Backtracking**: "목표를 넘으면 돌아서 다른 길을 찾는다."  
  - 단순히 조건을 만족하지 않으면 탐색을 중단.
- **Branch and Bound**: "이 길에서 더 가도 최적의 목적지에 도달할 가능성이 없다면 포기한다."  
  - 상한과 하한 계산을 통해 현재 경로가 유망한지 판단.

---

### **결론**
- **Backtracking**은 상한 계산만을 사용하여 탐색을 제한하며, 최적해를 찾기 위한 추가 계산(하한 계산)을 하지 않습니다.
- **Branch and Bound**는 상한과 하한 계산을 모두 사용하여 탐색 가능성과 최적해 가능성을 정교하게 평가하며, 이는 두 기법의 가장 큰 차이점이자 Branch and Bound의 핵심적인 강점입니다.
- **따라서, 상한과 하한 계산 여부는 Backtracking과 Branch and Bound를 구분하는 결정적인 차이**라고 할 수 있습니다.

# Key Concepts in Combinatorial Search

---

## Overview

**Heuristics**, **Metaheuristics**, and **CSP**는 Combinatorial Search의 핵심 개념입니다.
이들은 조합 탐색 문제에서 탐색 공간 축소, 최적화, 제약 조건 처리라는 필수 요소를 각각 다루며, 문제 해결의 효율성을 극대화합니다. 따라서, 이 세 가지는 조합 탐색 문제를 이해하고 해결하는 데 없어서는 안 될 개념입니다.

## Heuristic

- **정의**:
  - Heuristic은 '찾아내다', '발견하다'는 뜻의 그리스어에서 유래된 용어입니다.
  - 불확실하고 복잡한 문제를 가능한 빨리 풀기 위해 사용하는 **주먹구구식 셈법**이나 **직관적 판단**, **경험과 상식에 바탕을 둔 추론**을 의미합니다.

- **특징**:
  - 문제를 **빨리 해결하기 위해 대충 때려맞추는 방법**입니다.
  - 항상 최적의 해를 보장하지는 못하지만, **제약적인 상황**에서 **적당히 만족스러운 해**를 찾을 수 있습니다.

- **예시**:
  - **학교 소풍에서 점심값 계산**:  
    선생님이 100명의 아이들에게 필요한 점심값을 빠르게 계산해야 한다고 가정합니다. 시간이 부족하므로, 아이들이 먹을 음식을 대충 스캔하고 **한 사람당 만 원**이라는 직관적인 판단으로 계산합니다.  
    이는 정확한 계산 대신 **시간 부족 상황에서 적당히 만족하는 방법**으로 문제를 해결하는 Heuristic의 대표적인 사례입니다.

---

## Metaheuristic

- **정의**:
  - Heuristic을 찾아내는 방법을 **Metaheuristic**이라고 합니다.
  - Metaheuristic 알고리즘은 **최적화 알고리즘(Optimization Algorithm)**의 한 종류입니다.

- **특징**:
  - 일반적인 최적화 알고리즘은 **목적 함수를 미분 가능하다는 가정**을 사용합니다.
  - Metaheuristic은 이러한 가정을 하지 않기 때문에 **프로그래밍 대회**나 **복잡한 문제**를 해결할 때 자주 사용됩니다.

- **종류 및 활용**:
  - **Local Search(국소 탐색)**와 **Simulated Annealing(시뮬레이티드 어닐링)**은 구현과 튜닝이 간단하여 널리 사용됩니다.
  - 다양한 Metaheuristic 알고리즘이 있지만, 간단한 문제부터 복잡한 최적화 문제까지 폭넓게 적용할 수 있습니다.

- **참고 자료**:
  - [Metaheuristic @ Wikipedia](https://en.wikipedia.org/wiki/Metaheuristic)

---

## CSP (Constrained Satisfaction Problem)

- **정의**:
  - CSP는 **복수의 제약 조건을 충족하는 상태를 찾아내는 수학 문제**입니다.
  - 주로 **Combinatorial Search**로 해결됩니다.

- **중요 요소**:
  - **Constraint Propagation(제약조건 전파)**: 제약 조건을 활용해 탐색 공간을 줄이는 방법.
  - **Variable and Value Ordering(변수와 값 순서 정하기)**: 탐색 순서를 효율적으로 정하는 기법.

- **적용 문제**:
  - N-Queens 문제 ([NQUEEN @ Learntocode](/algospot/NQUEEN/README.md))
  - Kakuro 문제 ([KAKURO2 @ Learntocode](/algospot/KAKURO2/README.md))
  - Sudoku ([Sudoku @ Learntocode](/fundamentals/combinatorialsearch/sudoku/README.md))
  - 그 외: Map Coloring Problem, Crossword, Futoshiki, Numbrix, Hidato 등.

- **참고 자료**:
  - [Constraint Satisfaction Problem @ Wikipedia](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem)
  - [Constraint Satisfaction, An Introduction @ YouTube](https://www.youtube.com/watch?v=wrs6Lvo5LZM)

---
