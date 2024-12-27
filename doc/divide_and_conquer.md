- [**Divide and Conquer (분할 정복): 개념과 역사**](#divide-and-conquer-분할-정복-개념과-역사)
- [**Divide and Conquer의 개념**](#divide-and-conquer의-개념)
- [**Divide and Conquer의 특징**](#divide-and-conquer의-특징)
- [**Divide and Conquer의 예제**](#divide-and-conquer의-예제)
  - [1. **Merge Sort**](#1-merge-sort)
  - [2. **Binary Search**](#2-binary-search)
  - [3. **Maximum Subarray Problem (Kadane’s Algorithm as D\&C)**](#3-maximum-subarray-problem-kadanes-algorithm-as-dc)
  - [4. **Closest Pair of Points**](#4-closest-pair-of-points)
  - [5. **Strassen’s Algorithm**](#5-strassens-algorithm)
- [**Divide and Conquer의 장단점**](#divide-and-conquer의-장단점)
  - [장점:](#장점)
  - [단점:](#단점)
- [**Divide and Conquer의 적용 사례**](#divide-and-conquer의-적용-사례)
- [**Divide and Conquer와 Dynamic Programming의 차이**](#divide-and-conquer와-dynamic-programming의-차이)
- [**결론**](#결론)

-----

# **Divide and Conquer (분할 정복): 개념과 역사**

**Divide and Conquer**는 문제를 더 작은 하위 문제로 분할(Divide)하고, 각각의 하위 문제를 정복(Conquer)한 후, 결과를 결합(Combine)하여 원래 문제를 해결하는 알고리즘 설계 패러다임입니다.

- **역사**:
  - Divide and Conquer는 고대 수학 문제(예: 유클리드 알고리즘)에서도 사용되었습니다.
  - 현대 컴퓨터 과학에서는 John von Neumann의 **Merge Sort(1945년)**가 Divide and Conquer의 대표적인 예로 꼽힙니다.

---

# **Divide and Conquer의 개념**

Divide and Conquer는 세 단계로 이루어집니다:

1. **Divide (분할)**:
   - 문제를 더 작은 하위 문제로 나눕니다.
   - 하위 문제는 원래 문제와 동일한 성격을 가지며, 문제의 크기를 줄이는 데 초점이 있습니다.

2. **Conquer (정복)**:
   - 하위 문제를 재귀적으로 해결합니다.
   - 하위 문제가 충분히 작아지면 직접(또는 기저 조건으로) 해결합니다.

3. **Combine (병합)**:
   - 하위 문제의 해를 병합하여 원래 문제의 해를 구합니다.

---

# **Divide and Conquer의 특징**

1. **문제 구조**:
   - Divide and Conquer는 문제에 **최적 부분 구조(Optimal Substructure)**와 **독립적인 하위 문제**가 있을 때 효과적입니다.
   - 각 하위 문제는 서로 독립적으로 해결될 수 있어야 합니다.

2. **재귀적 접근**:
   - Divide and Conquer는 재귀를 활용하여 하위 문제를 해결합니다.

3. **시간 복잡도**:
   - Divide and Conquer의 시간 복잡도는 **마스터 정리(Master Theorem)**로 분석할 수 있습니다.
   - 일반적인 시간 복잡도:  
     T(n) = a * T(n / b) + O(n^d)
       - a: 하위 문제의 개수
       - b: 문제 크기를 나누는 비율
       - O(n^d): 병합 단계의 시간 복잡도

---

# **Divide and Conquer의 예제**

## 1. **Merge Sort**
- **문제**: 배열을 정렬하는 효율적인 알고리즘.
- **알고리즘**:
  - **Divide**: 배열을 절반으로 나눕니다.
  - **Conquer**: 각 하위 배열을 재귀적으로 정렬합니다.
  - **Combine**: 두 정렬된 배열을 병합하여 하나의 정렬된 배열을 만듭니다.
- **시간 복잡도**: O(n log n).

## 2. **Binary Search**
- **문제**: 정렬된 배열에서 특정 값을 찾기.
- **알고리즘**:
  - **Divide**: 배열의 중간 값을 선택하여 목표 값과 비교.
  - **Conquer**: 목표 값이 중간 값보다 크거나 작은 경우, 해당 절반만 탐색.
  - **Combine**: 탐색 결과를 반환.
- **시간 복잡도**: O(log n).

## 3. **Maximum Subarray Problem (Kadane’s Algorithm as D&C)**
- **문제**: 배열에서 연속된 하위 배열의 최대 합 찾기.
- **알고리즘**:
  - **Divide**: 배열을 중간으로 나눔.
  - **Conquer**: 왼쪽, 오른쪽, 중간을 포함한 하위 배열 중 최대 합을 찾음.
  - **Combine**: 최대 값을 반환.
- **시간 복잡도**: O(n log n) (Kadane’s Algorithm으로 O(n) 가능).

## 4. **Closest Pair of Points**
- **문제**: 2D 평면에서 가장 가까운 두 점의 거리 계산.
- **알고리즘**:
  - **Divide**: 점을 x좌표 기준으로 정렬한 후, 절반으로 나눔.
  - **Conquer**: 왼쪽과 오른쪽에서 가장 가까운 점 계산.
  - **Combine**: 경계선을 포함하여 가장 가까운 점 계산.
- **시간 복잡도**: O(n log n).

## 5. **Strassen’s Algorithm**
- **문제**: 두 행렬의 곱을 효율적으로 계산.
- **알고리즘**:
  - **Divide**: 행렬을 더 작은 블록으로 나눔.
  - **Conquer**: 7개의 곱셈과 추가 연산으로 블록 간 계산 수행.
  - **Combine**: 결과 블록을 결합하여 최종 행렬 생성.
- **시간 복잡도**: O(n^2.81) (일반 행렬 곱셈은 O(n^3)).

---

# **Divide and Conquer의 장단점**

## 장점:
1. **효율성**:
   - 문제를 작은 크기로 나눠 계산하므로 큰 문제를 효율적으로 해결 가능.
   - 많은 경우 시간 복잡도를 획기적으로 줄임 (예: Merge Sort, Binary Search).

2. **병렬 처리 가능성**:
   - 독립적인 하위 문제를 병렬로 처리 가능.

3. **재귀적 구조의 간결함**:
   - 코드 작성이 간단하고, 문제의 자연스러운 구조를 활용 가능.

## 단점:
1. **오버헤드**:
   - 하위 문제를 지나치게 많이 생성하면 재귀 호출 오버헤드가 발생.
   - 병합 단계가 비효율적일 경우 전체 성능 저하 가능.

2. **메모리 사용량**:
   - 재귀 호출 스택이 깊어질 경우 메모리 사용량 증가.

3. **적용 제한**:
   - 문제에 최적 부분 구조가 없거나 하위 문제가 독립적이지 않으면 적합하지 않음.

---

# **Divide and Conquer의 적용 사례**

1. **정렬 알고리즘**:
   - Merge Sort, Quick Sort.

2. **탐색 알고리즘**:
   - Binary Search.

3. **수학적 계산**:
   - Fast Fourier Transform(FFT), Karatsuba’s Algorithm.

4. **그래프 문제**:
   - Strongly Connected Components(SCC) (Tarjan’s Algorithm).

5. **기하학적 문제**:
   - Closest Pair of Points, Convex Hull.

6. **동적 계획법(DP) 문제의 최적화**:
   - 분할 정복 DP (Divide and Conquer Optimization).

---

# **Divide and Conquer와 Dynamic Programming의 차이**

| **특징**                  | **Divide and Conquer**                                  | **Dynamic Programming (DP)**                         |
|---------------------------|--------------------------------------------------------|-----------------------------------------------------|
| **문제 접근 방식**         | 문제를 독립적인 하위 문제로 분할                        | 문제를 중복되는 하위 문제로 분할                     |
| **하위 문제의 관계**       | 하위 문제가 서로 독립적                                | 하위 문제의 결과를 재활용                            |
| **적용 조건**             | 최적 부분 구조 + 독립적인 하위 문제                     | 최적 부분 구조 + 중복 부분 문제                      |
| **재귀 호출**             | 주로 사용                                              | 경우에 따라 사용 (Memoization에서 주로 사용)         |
| **시간 복잡도 감소 방법** | 문제 크기 축소 및 독립적인 해결                         | 중복 계산 방지 (결과 저장)                           |
| **대표 알고리즘**          | Merge Sort, Binary Search, Closest Pair of Points      | Knapsack Problem, Longest Common Subsequence (LCS)  |

---

# **결론**

Divide and Conquer는 큰 문제를 작은 하위 문제로 나누고 이를 효율적으로 해결한 뒤 병합하여 전체 문제를 해결하는 강력한 전략입니다.  
정렬, 탐색, 수학적 계산, 기하학 등 다양한 분야에서 활용되며, **효율적인 알고리즘 설계의 핵심 기법** 중 하나로 자리 잡고 있습니다.  
Divide and Conquer는 Dynamic Programming과 함께 문제 해결의 두 축으로 많은 응용 사례를 가지고 있습니다.
