# Abstract

Gray code 는 이진법 부호의 일종으로 데이터 전송, 입출력 장치, 아날로그 디지털 간 변환과 주변장치에 주로 사용된다. 연속된 수가 1 개의 비트만 다른 특징을 갖는다.

예를 들어서 다음은 일반적인 2 진법과 Gray code 를 비교한 것이다.

| number | binary numerical system | Gray code |
| ------ | ----------------------: | --------- |
| 0      |                     000 | 000       |
| 1      |                     001 | 001       |
| 2      |                     010 | 011       |
| 3      |                     011 | 010       |
| 4      |                     100 | 110       |
| 5      |                     101 | 111       |
| 6      |                     110 | 101       |
| 7      |                     111 | 100       |

다음은 2 bit 의 Gray Code 를 생성하는 방법이다.

1. 0 과 1 을 세로로 쓴다.
2. 바로 밑으로 이어서 앞서 적었던 숫자를 거꾸로 적는다. 마치 거울로 반사된 것과 같다.
3. `1` 단계에서 적었던 숫자의 왼쪽에 0 을 각각 적는다.
4. `2` 단계에서 적었던 숫자의 왼쪽에 1 을 각각 적는다.
5. `1-4` 를 반복한다.

```
(1)  (2)  (3)   (4)
0    0    00    00    
1    1    01    01    
     1     1    11    
     0     0    10    
```

다음은 앞서 Gray code 생성을 구현한 것이다.

```go
for i := 0; i < 4; i++ {
  bm := i ^ (i >> 1)
  fmt.Printf("%d : %b\n", i, bm)
}
```

# Hanoi Tower with gray code

Gray code 를 이용하면 [Tower of hanoi](/fundamentals/recursion/towerofhanoi/README.md) 문제를 쉽게 풀어 낼 수 있다.

예를 들어 원판이 3 개인 [Tower of hanoi](/fundamentals/recursion/towerofhanoi/README.md) 를 다음과 같이 풀어보자.

| Gray code | description        |
| --------- | ------------------ |
| 000       | start              |
| 001       | 1 번 원판 빈 기둥으로 이동   |
| 011       | 2 번 원판 빈 기둥으로 이동   |
| 010       | 1 번 원판 2 번 원판으로 이동 |
| 110       | 3 번 원판 빈 기둥으로 이동   |
| 111       | 1 번 원판 빈 기둥으로 이동   |
| 101       | 2 번 원판 3 번 원판으로 이동 |
| 100       | 1 번 원판 2 번 원판으로 이동 |

# References

* [그레이 코드(Gray code)](https://johngrib.github.io/wiki/gray-code/)
* [Gray code](https://cp-algorithms.com/algebra/gray-code.html)
  