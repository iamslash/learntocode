# Problem

[Knight Dialer](https://leetcode.com/problems/knight-dialer/)

```
1 2 3
4 5 6
7 8 9
  0
```

위와 같이 `0-9` 까지의 숫자로 구성된 키패드가 있다.  숫자 `N` 이
주어지면 임의 숫자 부터 출발하여 `N-1` 만큼 다음 숫자를 만들어 낸다.
다음 숫자는 이전 숫자에서 체스의 나이트 처럼 움직여서 만난 숫자이다.
이런 방식으로 만들 수 있는 `N` 자리 숫자의 개수를 구하는 문제이다.

# Idea

예를 들어, `0` 에서 출발하면 `6, 8` 에 도착할 수 있다. 또한 `6, 8`
에서 `0` 으로 도착할 수 있다. 역시 `2` 에서 출발하면 `7, 9` 에 도착할
수 있고 `7, 9` 에서 `2` 로 도착할 수 있다. 이런 식으로 각 숫자에서
출발했을 때 도착할 수 있는 숫자는 다음과 같다.

```
0: {4, 6} 
1: {6, 8} 
2: {7, 9}
3: {4, 8}
4: {3, 9, 0}
5: {}
6: {1, 7, 0}
7: {2, 6}
8: {1, 3}
9: {2, 4}
```

이전에 구했던 것을 이용하여 새로운 것을 구한다.  dynamic programming
이라 할 만 하다.

`vector<int> prevMoveCnt(10, 1)` 를 선언하여 `prevMoveCnt[i]` 에
키패드 `i` 에 도착할 수 있는 경우의 수를 저장한다. 처음 값은 모두 `1`
임이 자명하다. 

예를 들어 2 번째 `1` 을 만드는 경우를 생각해 보자. 키패드 `4, 6` 에서
출발하여 `1` 으로 도착할 수 있다. 따라서 `prevMoveCnt[1] =
prevMoveCnt[4] + prevMoveCnt[6]` 을 수행한다.

따라서 다음과 같은 dynamic programming equation 을 발견할 수 있다.

```
prevMoveCnt[i] = sum(prevMoveCnt[j])
```

모든 반복을 마치면 `sum(prevMoveCnt[])` 가 곧 답이다.

# Implmenetation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(N) O(1)
```
