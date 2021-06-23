- [Abstract](#abstract)
- [다양한 유형의 문제들](#다양한-유형의-문제들)
- [previous, next boundary](#previous-next-boundary)

----

# Abstract

- 수 이론에 대해 적어본다.

# 다양한 유형의 문제들

- 나머지연산
- 최대공약수
- 최소공배수
- 어떤 수가 소수인지 판별하는 방법
- 어떤 정수 범위 안에 들어있는 소수를 구하는 방법
- 소인수 분해를 하는 간단한 방법
- 진법 변환
- 팩토리얼
- a^b 제곱연산을 분할 정복 알고리즘과 이진수의 원리를 이용
- 행렬
- 피보나치수, 피사노 주기
- 이항계수
- 파스칼의 삼각형
- 카탈란 수
- 오일러 피 함수
- 나눗셈에서 나머지 연산
- 확장 유클리드 알고리즘

# previous, next boundary

임의의 숫자가 주어지면 다음 경계값 혹은 이전 경계값을 구하는 전략이다. 예를 들어
임의의 숫자가 주어지면 그 숫자보자 작고 15 단위로 나누어 지는 수와 그 숫자보다
크고 15 간위로 나누어지는 수를 구해보자.

```
prevBound = (num - 14) / 15) * 15

nextBound = (num / 15) * 15
```

unit 을 단위에 해당하는 수라고 하자. 그러면 다음과 같이 정리할 수 있다.

```
prevBound = (num - (unit - 1)) / unit) * unit

nextBound = (num / unit) * unit
```

* [L](/leetcode2/TheNumberofFullRoundsYouHavePlayed/README.md) | [The Number of Full Rounds You Have Played](https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/)
