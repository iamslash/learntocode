- [**역사**](#역사)
- [**정의**](#정의)
- [**응용 분야**](#응용-분야)
- [Problem](#problem)
- [Idea](#idea)
- [Implementation](#implementation)
- [Complexity](#complexity)

-----

# **역사**

- **최초 제안**:
  - Kadane's Algorithm은 1984년 **Joseph Kadane**가 제안한 알고리즘입니다.
  - 알고리즘은 **최대 부분 배열 문제(Maximum Subarray Problem)**를 효율적으로 해결하기 위해 설계되었습니다.
  
- **문제의 배경**:
  - 원래 이 문제는 주어진 배열에서 연속된 부분 배열의 합을 최대화하는 문제로, 데이터 분석, 금융 분야(주식 가격의 최대 상승 구간) 등에 응용됩니다.
  
- **중요성**:
  - 이전에는 이 문제를 해결하기 위해 O(n²) 또는 O(n³)의 시간 복잡도를 갖는 브루트포스(완전 탐색) 방법이 사용되었으나, Kadane의 알고리즘은 이를 O(n)으로 개선하여 효율성을 크게 높였습니다.

---

# **정의**

- **목적**:
  - **주어진 배열에서 연속된 부분 배열의 합 중 최대 값을 찾는 알고리즘**.
  
- **알고리즘 개념**:
  - 동적 계획법(Dynamic Programming)의 아이디어를 기반으로 이전 단계의 최적해를 활용하여 현재 단계의 최적해를 계산.
  - **점화식**:
    - `locMax = max(locMax + arr[i], arr[i])`
    - `glbMax = max(glbMax, locMax)`
  - `locMax`는 현재 위치까지의 최적 부분 배열 합.
  - `glbMax`는 현재까지의 전체 최적 부분 배열 합.

- **시간 복잡도**:
  - O(n): 배열을 한 번 순회하며 최대 값을 계산.

- **공간 복잡도**:
  - O(1): 추가적인 배열이나 저장소 없이 변수 두 개만으로 해결.

Kadane's Algorithm은 **최대 부분 배열 문제**를 효율적으로 해결하기 위한 대표적인 동적 계획법 알고리즘입니다.  
- 단순하면서도 강력한 알고리즘으로, O(n)의 시간 복잡도로 최적해를 보장합니다.
- 데이터 분석, 금융 등 다양한 실생활 문제에 적용 가능하며, 동적 계획법 학습의 필수적인 예제 중 하나입니다.

---

# **응용 분야**
- **금융**:
  - 주식 가격의 최대 상승 구간을 분석.
- **데이터 분석**:
  - 센서 데이터의 최대 연속 신호 강도.
- **동적 프로그래밍 학습**:
  - DP의 기본 원리를 이해하고 연습하기 위한 대표적인 문제.

---

# Problem

수열 `A[]` 가 주어진다. 연속된 부분 수열중 가장 큰 합을 구하라.

# Idea

예를 들어 `A = [-2,1,-3,4,-1,2,1,-5,4]` 의 경우를 살펴보자. `[4,-1,2,1]` 의 합이 6 이고 곧 답이된다.

- `int locMax` 를 선언하여 지금까지 찾은 최대 부분 수열합 중 최근값을 저장한다.
- `int glbMax` 를 선언하여 지금까지 찾은 최대 부분 수열합 중 최대값을 저장한다.

```
  nums:  -2   1  -3   4  -1   2   1  -5   4
locMax:  -2   1  -2   4   3   5   6   1   5
glbMax:  -2   1   1   4   4   5   6   6   6
```

곧 `6` 이 답이다.

# Implementation

- [java11](MainApp.java)

# Complexity

```
O(N) O(1)
```
