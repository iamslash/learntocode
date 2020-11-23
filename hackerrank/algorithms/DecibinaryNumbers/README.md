# Problem

[Decibinary Numbers @ hackerrank](https://www.hackerrank.com/challenges/decibinary-numbers/problem)

# Idea

x번째 decibinary number를 구하는 문제이다.  x는 1보다 크거나 같고
10^16보다 작거나 같다. 

x를 decibinary number와 decimal number로
다음과 같이 표현해보자.

| x | decibinary | decimal  |
|---|------|---|
| 1 |    0 | 0 |
| 2 |    1 | 1 |
| 3 |    2 | 2 |
| 4 |   10 | 2 |
| 5 |    3 | 3 |
| 6 |   11 | 3 |
| 7 |    4 | 4 |
| 8 |   12 | 4 |
| 9 |   20 | 4 |
| 10 | 100 | 4 |
| .  | ... | ... |
| 20 | 110 | 6 |

하나의 decimal을 표현할 수 있는 decibinary는 여러 개이고 같은
decimal에 대한 여러 decibinary들은 오름차순으로 정렬 돼야
한다. 그렇다면 특정 decimal과 같은 여러 개의 decibinary 중 가장 큰
것은 어떤 것일까?  자릿수를 가장 많이 사용하는 녀석이다. 자릿수가 커질
수록 크기가 큰 수가 될테니 당연하다.

자릿수가 최대이면서 크기가 최소인 decibinary를 구하려면 다음과 같은
방법을 이용한다. 특정 decimal보다 크면서 1로 시작하고 나머지는 0으로
채워진 최소의 decibinary를 만들어 그것의 자릿수에서 하나 감소하면
된다.

예를 들어서 위의 표를 참고하여 decimal이 4인 경우를 살펴 보자.  1로
시작하고 나머지는 0으로 채워진 최소의 decibinary는 1000이다. 이것의
자릿수는 4이기 때문에 decimal 4에 대한 최대 자릿수는 3이다.

decibinary의 최대 자릿수를 구했다면 가장 왼쪽 자리 부터 0에서 9까지
숫자를 교체 해가면서 decimal과 같은 수를 찾으면 된다.

자릿수를 `digitidx`라 하고 decimal number를 `decimal`라고 할때 다음과
같은 부분 문제를 정의하여 decibinary들의 숫자를 재귀적으로 계산 할 수
있다.

```
int cnt(digitidx, decimal)
digitidx : 십진수 decimal을 표현하기 위해 필요한 
           decibinary의 가장 왼쪽 자리 숫자의 인덱스
decimal  : 표현하고자 하는 십진수
```

부분문제 cnt는 다음과 같은 여러가지 경우를 고려하여 구현할 수 있다.

* digitidx가 -1이면 성공이다.
* digitidx의 숫자 i를 0부터 9까지 반복하면서 `cnt(digitidx-1,
  decimal - (1<<digitidx)*i)` 를 계산한다. 이때 `decimal -
  (1<<digitidx)*i`가 0보다 작으면 이후 탐색은 실패이므로 건너뛴다.

decimal number `i`를 0부터 하나씩 증가하면서 해당하는 decibinary의
개수를 누적 하여 1차원 배열 `ps`에 저장하자. x는 10^16보다 작거나 같기
때문에 `ps[i]`는 10^16보다 크면 종료한다. ps는 다음과 같이 구한다.

```
ps[i] = ps[i-1] + cnt(60, i)
```

직접 해본 결과 decimal은 300,000을 초과 하지 않는다. 300,000와 같은
최대 자릿수이면서 최소 크기의 decibinary는 `100000000000000000000`이기
때문에 decibinary의 자릿수는 `20`이다. 따라서 다음과 같이 CACHE를
정의하여 `cnt`를 memoization할 수 있다.

```
CACHE[20][300000]
```

이제 x번째의 decibinary를 구해보자.  x가 포함되는 최소의 `ps[i]`를
찾아 낼 수 있다. `ps[i]`의 decibinary 중 최대인 녀석부터 decibinary를
만들어 낼 수 있고 x번째 해당하는 것을 찾으면 된다.

# Implementation

* [c++11](a.cpp)

# Time Complexity
