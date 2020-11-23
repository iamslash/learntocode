# Problem

* [Can I Win @ leetcode](https://leetcode.com/problems/can-i-win/)

# References

* [花花酱 LeetCode 464. Can I Win - 刷题找工作 EP165 @ youtube](https://www.youtube.com/watch?v=GNZIAbf0gT0)

# Idea

`maxChoosableInteger` 를 `M` 이라고 하고 `desiredTotal` 을 `T`
라고 하자. 

두 사람이 한번씩 숫자를 고르는 게임을 한다. 숫자는 `[1, M]` 
이고 한 번 사용된 숫자는 다시 사용될 수 없다. 두
사람이 고른 숫자의 합이 `T` 보다 크거나 같을 때 마지막에
고른 사람이 승자가 된다. 첫 번째 사람이 이길 수 있는 경우가 있다면 `true`
를 출력하고 그렇지 않다면 `false` 를 출력해야 한다.

예를 들어 `M` 이 3 이고 `T` 가 4 인 경우 다음과 같이 그래프를 그려볼
수 있다.

```
                                       R
                                  /    |                               \
player 1               [S:1,U:(1)]   [S:2,U(2)]                       [S:1,U(3)]
                    /     /             /            \                    /     \
player 2  [S:3,U:(1,2)] [S:4,U:(1,3)] [S:3,U:(1,2)] [S:5,U:(2,3)] [S:4,U:(1,3)] [S:5,U:(2,3)]
                  /                     /
player 1  [S:6,U(1,2,3)]        [S:6,U(1,2,3)]
```

먼저 다음과 같은 3 가지 경우를 생각할 수 있다.

* `1` 부터 `M` 까지의 합이 `T` 보다 작다면 `false` 이다.
* `T` 가 `1` 보다 작거나 같다면 `true` 이다.
* `M*(M+1)/2 == T` 일 때를 생각해 보자. `[1,M]` 의 숫자를 모두 골라야 게임이
  종료된다. `M` 이 홀수인 경우 첫 번째 사람이 마지막에 고르게 된다.

언급한 3 가지를 제외한 경우는 직접 게임을 수행한다. `M` 은 20 보다 크지
않기 때문에 int 변수에 bit 연산을 이용하면 어느 숫자가 사용되었는지를
표현할 수 있다. `2^M` 만큼의 경우의 수가 존재한다.

다음과 같은 부분문제를 정의하여 재귀적으로 해결해보자. `play` 는 현재의 `M, T, U`
에 대하여 이번에 선택해야 하는 사람의 승패정보를 리턴한다.

```
play(int M, int T, int U)
M : maxChoosableInteger
T : designedTotal
U : used numbers
```

# Implementation

* [c++11](a.cpp)
