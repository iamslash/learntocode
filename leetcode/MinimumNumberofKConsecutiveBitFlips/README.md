# Problem

[Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)

# Idea

수열 `A[]` 와 숫자 `K` 가 주어진다. `A[]` 는 `0, 1` 들로 구성되어
있다. `A[]` 가 모두 `1` 이 되도록 `K` 만큼씩 bit flipping 하자. 최소의
bit flipping 개수를 구하는 문제이다.

greedy algorithm 을 이용한다. 처음부터 순회하면서 다음을 반복한다.

0. `A[i] == 1` 이면 건너뛴다.
1. `A[i] != 1` 이면 k 만큼 bit flipping 한다.

위의 방법은 bit flipping 할 때 `A[i]` 에서 `K` 만큼 순회한 후 다시
`A[i+1]` 부터 순회한다. `K` 가 아주 크다면 시간복잡도가 높이진다.
위의 방법을 조금 더 최적화 해보자.

sliding window 를 이용한다.  일단 다음과 같이 두가지 변수를 선언한다.

```
cnt: bit flipping 개수
cur: bit flipping 필요성을 계산하기 위한 변수
```

`A[i]` 가 `cur` 를 고려할 때 bit flipping 을 시작해야 할 window 의
시작이라면 `A[i] += 2` 하여 표시를 하자. 이때 `cur++, cnt++` 를
수행한다.

인덱스 `i` 가 bit flipping 이 필요한`K` 크기 윈도우를 지나칠 때 마다
`cur` 를 하나 감소한다.

`cur` 가 짝수이고 `A[i] == 0` 이거나 `cur` 가 홀수이고 `A[i] == 1`
이면 bit flipping 필요하다.

다음은 `A = (0 0 0 1 0 0 1 0), K = 3` 일 때의 풀이 과정이다.

```
     i                      i                             i    
                            _____                   _____
  A: 0 0 0 1 0 0 1 0     A: 2 0 0 1 0 0 1 0      A: 2 0 0 1 0 0 1 0
cur: 0                 cur: 1                  cur: 0             
cnt: 0                 cnt: 1                  cnt: 1             

             i                            i      
             _____                    _____    
  A: 2 0 0 1 2 0 1 0     A: 2 0 0 1 2 2 1 0    
cur: 1                 cur: 1                  
cnt: 2                 cnt: 3                  
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
