# Problem

[Maximum Candies You Can Get from Boxes](https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/)

# Idea

수열 `status[], candies[], keys[], containedBoxes[], initialBoxes[]`
가 주어진다.  `status[i]` 는 i-box 의 상태이다. 0 이면 닫혀있고 1 이면
열려있다.  `candies[i]` 는 i-box 에 담긴 캔디의 개수이다. `keys[i]` 는
i-box 에 담긴 열쇠의 모음이다. 열쇠의 숫자는 열수있는 상자의 번호를
의미한다.  `containedBoxes[i]` 는 i-box 에 담긴 상자의
모음이다. 상자의 숫자는 j-box 를 의미한다. `initialBoxes[i]` 는 처음에
열어볼 상자의 목록이다. `initialBoxes[]` 를 시작으로 열 수 있는 상자를
열어서 캔디를 모아보자. 캔디의 최대 개수를 구하는 문제이다.

queue 에 상자를 담고 하나씩 꺼내서 열어보는 것을 반복하여 해결할 수
있다. BFS 로 충분히 해결할 만 하다.

`todo := make(map[int]bool)` 를 선언하여 열어볼 상자들을 저장한다.  `q
:= []int` 를 선언하여 BFS queue 로 이용한다. 그리고 다음을
반복한다. `ans := 0` 을 선언하여 답을 저장한다.

`u` 는 이번에 열어볼 상자이다. `ans += candies[u]` 를
수행한다. `keys[u]` 를 순회하면서 `status[u] = 1` 을
수행한다. `containedBoxes[i]` 를 순회하면서 `todo` 에 삽입한다. `todo`
를 순회하면서 열 수 있는 상자를 `q` 에 담는다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(N)
```
