- [Master Theorem이란?](#master-theorem이란)
- [문제 구조](#문제-구조)
- [Master Theorem의 핵심 규칙](#master-theorem의-핵심-규칙)
- [간단한 예제](#간단한-예제)
  - [Merge Sort](#merge-sort)

----

# Master Theorem이란?
- **Master Theorem**은 재귀적으로 정의된 알고리즘의 시간 복잡도를 계산하는 방법입니다.
- **분할 정복 알고리즘**(예: Merge Sort, Quick Sort 등)에서, 문제를 작은 문제로 나누고 합치는 데 걸리는 전체 시간을 계산합니다.

![](/_img/master_theorem.png)

# 문제 구조
Master Theorem은 다음과 같은 **재귀 식**의 시간 복잡도를 계산합니다:

```
T(n) = a * T(n / b) + O(n^d)
```

- **`a`**: 한 번 문제를 나눌 때 생기는 작은 문제의 개수.
- **`n / b`**: 나누어진 문제의 크기.
- **`O(n^d)`**: 문제를 나눈 후 처리하는 "합치는 작업"의 시간 복잡도.

# Master Theorem의 핵심 규칙
Master Theorem은 **a**, **b**, 그리고 **d**를 비교해서 아래 세 가지 경우 중 하나로 시간 복잡도를 결정합니다.

1. **작은 문제 풀이가 더 중요할 때 (a > b^d)**  
   - 재귀적으로 나누는 문제가 더 많이 발생.  
   - **결과**: `T(n) = O(n^(log_b a))`

2. **문제를 합치는 일이 더 중요할 때 (a == b^d)**  
   - 문제를 나누는 것과 합치는 것의 중요도가 같음.  
   - **결과**: `T(n) = O(n^d * log n)`

3. **문제를 합치는 일이 훨씬 더 중요할 때 (a < b^d)**  
   - 문제를 나누는 것보다 합치는 일이 더 많은 시간 소모.  
   - **결과**: `T(n) = O(n^d)`

# 간단한 예제
## Merge Sort

Merge Sort는 다음과 같이 재귀적으로 정의됩니다:

```
T(n) = 2 * T(n / 2) + O(n)
```

- **a = 2**: 문제를 두 개로 나눕니다.
- **b = 2**: 각 문제의 크기는 절반으로 줄어듭니다.
- **d = 1**: 합치는 작업은 O(n)입니다.

**분석**:
- `log_b a = log_2 2 = 1`  
- **a == b^d**: 문제를 나누는 것과 합치는 일이 비슷한 시간 소모.  
- 따라서, 시간 복잡도는 `T(n) = O(n * log n)`.

[merge sort](/fundamentals/sort/mergesort/README.md#idea)
