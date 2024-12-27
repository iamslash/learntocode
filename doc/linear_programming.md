- [**Linear Programming (LP): 정의와 역사**](#linear-programming-lp-정의와-역사)
- [**Linear Programming (LP)의 개념**](#linear-programming-lp의-개념)
- [**Linear Programming의 핵심 조건**](#linear-programming의-핵심-조건)
- [**Linear Programming의 예제**](#linear-programming의-예제)
    - [자원 배분 문제](#자원-배분-문제)
- [**Linear Programming의 해결 방법**](#linear-programming의-해결-방법)
  - [1. Simplex Algorithm](#1-simplex-algorithm)
  - [2. Interior Point Methods](#2-interior-point-methods)
- [**Linear Programming의 응용 분야**](#linear-programming의-응용-분야)
- [**Linear Programming의 한계**](#linear-programming의-한계)
- [**Linear Programming 문제들**](#linear-programming-문제들)
  - [**1. 자원 배분 문제 (Resource Allocation Problem)**:](#1-자원-배분-문제-resource-allocation-problem)
  - [**2. 최소 비용 운송 문제 (Transportation Problem)**:](#2-최소-비용-운송-문제-transportation-problem)
  - [**3. 투자 포트폴리오 최적화 (Investment Portfolio Optimization)**:](#3-투자-포트폴리오-최적화-investment-portfolio-optimization)
  - [**4. 작업 스케줄링 문제 (Job Scheduling Problem)**:](#4-작업-스케줄링-문제-job-scheduling-problem)
  - [**5. 네트워크 대역폭 할당 문제 (Network Bandwidth Allocation)**:](#5-네트워크-대역폭-할당-문제-network-bandwidth-allocation)
- [**Linear Programming의 장단점**](#linear-programming의-장단점)
  - [장점:](#장점)
  - [단점:](#단점)
- [**결론**](#결론)

-------


# **Linear Programming (LP): 정의와 역사**

**Linear Programming (LP)**는 선형 방정식과 부등식으로 이루어진 제약 조건 하에서, 선형 목적 함수의 최대값 또는 최소값을 찾는 최적화 기법입니다.  
1947년 **George B. Dantzig**에 의해 개발되었으며, 그는 제2차 세계 대전 당시 자원 배분 문제를 해결하기 위해 Simplex Algorithm을 고안했습니다.

- **창시자**: George B. Dantzig  
- **시기**: 1947년  
- **목적**:
  - 자원 배분과 물류 최적화를 위해 개발.
  - 군사적 자원 문제뿐 아니라, 경제학, 공학, 경영학 등으로 확장.

---

# **Linear Programming (LP)의 개념**

Linear Programming은 다음 세 가지 요소로 구성됩니다:

1. **목적 함수 (Objective Function)**:  
   최적화하려는 대상(예: 비용 최소화, 이익 최대화)을 나타내는 선형 함수.  
   예: `Z = 3x + 2y`  
   여기서 `Z`는 최적화 값, `x`와 `y`는 변수.

2. **제약 조건 (Constraints)**:  
   변수가 만족해야 하는 선형 방정식 또는 부등식의 집합.  
   예: `x + 2y <= 10`, `x >= 0`, `y >= 0`.

3. **변수 (Decision Variables)**:  
   최적화를 수행할 대상.  
   예: 생산량, 자원 사용량 등.

---

# **Linear Programming의 핵심 조건**

1. **선형성 (Linearity)**:
   - 목적 함수와 제약 조건이 모두 선형이어야 함.

2. **제약 조건의 제한성**:
   - 가능한 해는 제약 조건으로 정의된 영역(Feasible Region) 내에 있어야 함.

3. **연속성 (Continuity)**:
   - 변수는 연속적인 실수 값을 가질 수 있음.

---

# **Linear Programming의 예제**

### 자원 배분 문제
- **문제 정의**:  
  회사가 두 가지 제품을 생산하며, 각 제품은 제한된 자원을 소비.  
  최대 이익을 얻도록 제품의 생산량을 결정.

- **목적 함수**:  
  `Z = 3x + 2y` (이익 최대화).  
  여기서 `x`는 제품 A의 생산량, `y`는 제품 B의 생산량.

- **제약 조건**:
  - `x + 2y <= 10` (자원 1의 제한).
  - `2x + y <= 15` (자원 2의 제한).
  - `x >= 0`, `y >= 0` (생산량은 음수가 될 수 없음).

- **해결 방법**:  
  가능한 영역을 그래프로 표시한 후, 꼭짓점에서 목적 함수 값을 계산하여 최적해를 찾음.

---

# **Linear Programming의 해결 방법**

## 1. Simplex Algorithm
- **창시자**: George B. Dantzig (1947년).  
- 선형 계획 문제를 해결하는 가장 기본적이고 널리 사용되는 알고리즘.

## 2. Interior Point Methods
- **개발 시기**: 1980년대.  
- 대규모 선형 계획 문제를 효율적으로 해결.

---

# **Linear Programming의 응용 분야**

1. **공학**:
   - 전력망 최적화, 로봇 경로 계획.

2. **경제학 및 경영학**:
   - 자원 배분, 생산 계획, 비용 최소화.

3. **물류 및 공급망**:
   - 최적 운송 경로 계산, 재고 관리.

4. **네트워크 최적화**:
   - 데이터 흐름 최적화, 대역폭 관리.

5. **운영 연구**:
   - 작업 일정 계획, 인력 배치.

---

# **Linear Programming의 한계**

1. **선형성**:
   - 목적 함수와 제약 조건이 반드시 선형이어야만 적용 가능.  
     (현실 문제는 종종 비선형적 특성을 가짐).

2. **정수 제약**:
   - Linear Programming은 실수 값을 다룸.  
     정수 값을 요구하는 문제(Integer Programming)에서는 직접 사용할 수 없음.

---

# **Linear Programming 문제들**

## **1. 자원 배분 문제 (Resource Allocation Problem)**:
- 제품별 생산량을 결정하여 이익을 최대화.

## **2. 최소 비용 운송 문제 (Transportation Problem)**:
- 창고와 목적지 간의 운송 비용을 최소화.

## **3. 투자 포트폴리오 최적화 (Investment Portfolio Optimization)**:
- 위험을 최소화하며 수익률을 최대화.

## **4. 작업 스케줄링 문제 (Job Scheduling Problem)**:
- 작업 비용을 최소화하면서 스케줄링.

## **5. 네트워크 대역폭 할당 문제 (Network Bandwidth Allocation)**:
- 대역폭 제약 조건 하에서 비용을 최소화.

---

# **Linear Programming의 장단점**

## 장점:
1. **효율성**:  
   - Simplex Algorithm과 같은 알고리즘으로 문제를 빠르게 해결.
2. **적용성**:  
   - 자원 배분, 물류, 네트워크 등 다양한 분야에 활용 가능.

## 단점:
1. **선형성 제한**:  
   - 모든 현실 문제를 모델링할 수는 없음.
2. **정수 제약**:  
   - 정수 값을 요구하는 문제는 Integer Programming으로 확장 필요.

---

# **결론**

Linear Programming은 제약 조건 하에서 최적화 문제를 해결하기 위한 강력한 도구입니다.  
1947년 George B. Dantzig이 개발한 이 기법은 물류, 자원 배분, 네트워크 등 다양한 산업에서 활용되며, **Optimization**의 핵심 하위 개념으로 자리 잡고 있습니다.
