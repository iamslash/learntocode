# Problem

[New 21 Game](https://leetcode.com/problems/new-21-game/)

숫자 `N, K, W` 가 주어진다. Alice 는 `[1..W]` 숫자가 그려진 카드를
한장씩 뽑을 수 있다. 카드를 한장씩 뽑을 때 마다 그 카드의 숫자 만큼
점수를 증가한다. 점수의 합계가 `K` 보다 크거나 같으면 게임을
중지한다. 게임을 중지할 때 점수의 합계가 `N` 보다 작거나 같을 확률을
구하는 문제이다.

# Idea

결국 내가 뽑은 카드의 숫자합 `x` 가 `K <= x <= N` 일 확률을 구하는
것이다.  이때 카드를 뽑는 횟수는 정해져 있지 않기 때문에 신경쓸 필요가
없다.  다음과 같은 점화식을 만들어 볼 수 있다.

```c
x : final points
i : intermediate points

P(K <= x <= N) = P(x = K) + P(x = K+1) + ... + P(x = N)

      P(x = K) = P(i = K-1, last number = 1) + 
                 P(i = K-2, last number = 2) + ... + 
                 P(i = K-W, last number = W)

P(i = K-1, last number = 1) = P(i = K-1) * P(last number = 1) 
                            = P(i = K-1) * 1/W

      P(x = 0) = 1
      P(x = 1) = P(x = 0)     * 1/W
      P(x = 2) = P(x = 0)     * 1/W +
                 P(x = 1)     * 1/W
      P(x = 3) = P(x = 0)     * 1/W +
                 P(x = 1)     * 1/W +
                 P(x = 2)     * 1/W
      ...
      P(x = K) = P(x = K-1)   * 1/W + 
                 P(x = K-2)   * 1/W + ... + 
                 P(x = K-W)   * 1/W
    P(x = K+1) = P(x = K)     * 1/W +
                 P(x = K-1)   * 1/W + ... +
                 P(x = K-W+1) * 1/W
    P(x = K+2) = P(x = K+1)   * 1/W +
                 P(x = K)     * 1/W + ... +
                 P(x = K-W+2) * 1/W
```

만약 `K == 0` 이면 `[1..W]` 중 아무거나 한장 뽑아도 `K <= x <= N` 을
만족한다??? `N = 10, K = 0, W = 20`???

만약 `N >= K + W` 이면 점수가 `x >= K` 인 상태를 살펴보자. `[1..W]` 중
아무거나 한장 뽑아도 `K <= x <= N` 을 만족한다. `1.0` 을 리턴한다.

`double P[N+1]` 를 선언하고 `P[]` 를 `[1..N]` 를 순회하며 채운다. 이때 `W` 만큼의 window 를 만들고 sliding 하면서 `ans` 에 더한다.

```
   _________
     _________
       _________
  P: . . . . . . .
ans: ?
```

예를 들어 `N = 10, K = 2, W = 2` 의 풀이과정은 다음과 같다.

```
 N = 10, K = 2, W = 3
 P(2 <= x <= 10) = P[2] + P[3] + … + P[10]

 P[0] = 1.0
 P[1] = P[0]/W
 P[2] = P[0]/W + P[1]/W
 P[3] = P[1]/W + P[2]/W
 P[4] = (P[1] + P[2] + P[3])/W 
 P[5] = (P[2] + P[3] + P[4])/W
...
P[10] = (P[7] + P[8] + P[9])/W
```

따라서 답은 `P[2] + P[3] + ... + P[10]` 과 같다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(N) O(N)
```
