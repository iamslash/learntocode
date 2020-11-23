# Problem

* [Bulb Switcher II](https://leetcode.com/problems/bulb-switcher-ii/)

# Idea

`n` 개의 전구가 주어지고 `m` 번 다음과 같은 동작중 하나를 수행할 수 있다고할 때
발생할 수 있는 전구 상태의 개수를 구하는 문제이다.

* Flip all the lights.
* Flip lights with even numbers.
* Flip lights with odd numbers.
* Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...

위 동작을 1 번부터 4 번까지 잘 살펴보면 몇가지 규칙을 발견할 수 있다.

* 1 번 동작 + 2 번 동작 = 3 번 동작
* 1 번 동작 + 3 번 동작 = 2 번 동작
* 2 번 동작 + 3 번 동작 = 1 번 동작

따라서 서로 다른 전구 상태를 만들 수 있는 동작은 다음과 같이 8 가지가 존재한다.

* 아무것도 안함
* 1 번 동작
* 2 번 동작
* 3 번 동작
* 4 번 동작
* 1 번 동작 + 4 번 동작
* 2 번 동작 + 4 번 동작
* 3 번 동작 + 4 번 동작

`n > 2 && m >= 3` 일 때는 위의 8 가지 동작이 가능하기 때문에 답은 8 이다.
그 이외의 경우는 `n, m` 을 고려해서 처리한다. 다음은 세로가 `n`, 가로가 `m` 인
표이다.

```
  0 1 2
0 1 4 7
1 2 3 2
2 4 4 7
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(1)
```