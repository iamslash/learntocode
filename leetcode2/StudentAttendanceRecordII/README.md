# Problem

[Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii/)

숫자 `n` 이 주어진다. `n` 개 만큼 `A, L, P` 를 배치할 수 있다.  `A` 가
1 개를 넘거나 연속된 `L` 이 2 개를 넘어서면 옳지 않은 문자열이다.
옳바른 문자열의 개수를 구하라.

# Idea

간단한 예부터 살펴보자. 다음과 같이 `n = 1` 일 때 `A, L` 의 개수에
따라 표현가능한 문자열을 생각해 보자.

```
A0L0: P
A0L1: L
A0L2: 
A1L0: A
A1L1:
A1L2:
```

이번에는 `n = 2` 일 때를 살펴보자.

```
A0L0: LP, PP
A0L1: PL
A0L2: LL
A1L0: AP, LA, PA
A1L1: AL
A1L2:
```

다음과 같은 규칙을 생각해 낼 수 있다.

* n 개의 `A0L0` 은 n-1 개의 `A0L0 + A0L1 + A0L2` 의 끝에 `P` 를 추가한
것과 같다. 
* n 개의 `A0L1` 은 n-1 개의 `A0L0` 의 끝에 `L` 을 추가한 것과 같다.
* n 개의 `A0L2` 은 n-1 개의 `A0L1` 의 끝에 `L` 을 추가한 것과 같다.
* n 개의 `A1L0` 은 n-1 개의 `A1L0 + A1L1 + A1L2` 의 끝에 `P` 를 추가한
것과 같다. 
* n 개의 `A1L1` 은 n-1 개의 `A1L0` 의 끝에 `L` 을 추가한 것과 같다.
* n 개의 `A1L2` 은 n-1 개의 `A1L1` 의 끝에 `L` 을 추가한 것과 같다.

`vector<int> C` 를 선언하고 다음과 같은 경우의 수를 저장한다.

```
A0L0: C[0]
A0L1: C[1]
A0L2: C[2]
A1L0: C[3]
A1L1: C[4]
A1L2: C[5]
```

`C` 와 함께 다음과 같은 dynamic programming equation 을 생각해 낼 수 있다.

```
C[0] = C[0] + C[1] + C[2]
C[1] = C[0]
C[2] = C[1]
C[3] = C[3] + C[4] + C[5]
C[4] = C[3]
C[5] = C[4]
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
