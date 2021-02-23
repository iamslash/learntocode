# Problem

[Minimum Number of Operations to Move All Balls to Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)

문자열 `boxes[]` 가 주어진다. `boxes[i]` 는 `0` 혹은 `1` 이다. `1` 은
공이 하나 있다는 의미이다. 공을 한칸씩 움직여서 각 `boxes[i]` 로 모든
공을 옮기자. `ans[]` 를 선언하고 `ans[i]` 에 각 `boxes[i]` 로 옮긴
최소횟수를 저장하자.

# Idea

예를 들어 `boxes = "110"` 을 살펴보자.

```
boxes: 1 1 0
  ans: 1 1 3
```

`ans = [0]*len(boxes)` 를 선언하여 답을 저장한다. `ops = 0` 를
선언하여 `ans[i]` 에 더할 공들의 이동횟수를 저장한다. `cnt = 0` 를
선언하여 지나친 공의 개수를 저장한다.

인덱스 `i` 를 이용하여 `boxes` 를 `[0..n)` 동안 순회하면서 다음을
반복한다.

* `ans[i] = ops` 를 수행한다.
* `boxes[i] == 1` 이면 `cnt` 를 하나 증가한다.
* `ops` 에 `cnt` 를 더한다.

`ops, cnt` 를 `0` 으로 초기화 한다.

인덱스 `i` 를 이용하여 `boxes` 를 `(n..0]` 동안 순회하면서
다음을 반복한다.

* `ans[i] = ops` 를 수행한다.
* `boxes[i] == 1` 이면 `cnt` 를 하나 증가한다.
* `ops` 에 `cnt` 를 더한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [py3](a.py)

# Complexity

```
O(N) O(N)
```
