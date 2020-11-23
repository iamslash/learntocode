# Problem

[Airplane Seat Assignment Probability](https://leetcode.com/problems/airplane-seat-assignment-probability/)

# Idea

숫자 `n` 이 주어진다. `n` 명의 승객이 `n` 개의 좌석을 갖는 비행기에 탑승한다. `i` 번째 좌석은 `i` 번째 승객의 자리이다. 첫번 째 승객은 랜덤하게 자리를 골라서 앉는다. 두번째 승객 역시 랜덤하게 자리를 골라서 앉는다. 이때 자기 자리에 앉을 수도 있고 그렇지 않을 수도 있다. `n` 번째 승객이 자기 자리에 앉을 확률을 구하는 문제이다.

* `n == 1` 일때를 생각해 보자.

1st 승객이 1st 좌석에 앉을 확률은 `1.0` 이다.

* `n == 2` 일때를 생각해 보자.

1st 승객이 1th 좌석에 앉을 확률 (1/2) * 2nd 승객이 2nd 좌석에 앉을 확률 (1) 

따라서 2nd 승객이 2nd 좌석에 앉을 확률은 `1/2` 이다.

* `n == 3` 일때를 생각해 보자.
  
모든 경우의 수는 `[1..n]` 의 숫자를 배열하는 것과 같다.

* 1 2 3
* 1 3 2
* 2 1 3
* 2 3 1
* 3 1 2
* 3 2 1

1/3 이 아니고 1/2 인 이유는 ???

[Proof without math】Three tiny stories](https://leetcode.com/problems/airplane-seat-assignment-probability/discuss/420455/Proof-without-mathThree-tiny-stories) 를 읽고 다시 생각해 보자.

`n` 명의 사람이 있다고 할 때 첫번째 사람은 어느 자리라도 앉도록 하자. 두번째 사람이 자기 자리를 앉는다. 만약 첫번째 사람이 두번째 자리에 있다면 일으켜 다른 자리에 앉도록 한다. 세번째 사람이 자기 자리를 앉는다. 만약 첫번째 사람이 세번째 자리에 있다면 일으켜 다른 자리에 앉도록 한다. 마침내 `n` 번째 사람이 자리에 앉을 차례이다. 이제 첫번째 사람과 `n` 번째 사람이 자리를 교환하거나 그대로 않으면 `n` 번째 사람이 `n` 번째 자리에 앉게 된다. 전체 경우의 수가 `2` 이기 때문에 확률은 `1/2` 이다.

# Implementation

* [go](a.go)

# Complexity

```
O(!) O(1)
```
