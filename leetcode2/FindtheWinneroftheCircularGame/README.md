# Problem

> [Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)

두개의 숫자 `n, k` 가 주어진다. `[1..n]` 만큼의 숫자가 있다.  `k`
만큼씩 시계방향으로 이동하면서 숫자를 삭제하자. 마지막에 남는 숫자를
구하라.

# Idea

예를 들어 `n = 5, k = 2` 의 경우를 살펴보자.

```
k: 2
n: 1 2 3 4 5    
1    i        
2        i
3  i
4         i      
```

따라서 답은 `3` 이다.

이번에는 `n = 6, k = 5` 의 경우를 살펴보자.

```
k: 5
n: 1 2 3 4 5 6
1          i
2        i
3            i
4    i
5      i
```

따라서 답은 `1` 이다.

인덱스 `i` 의 움직임을 살펴보면 다음과 같은
규칙을 발견할 수 있다.

```
i = (i + k) % j

j = [1..n]
```

인덱스 `j` 를 `[1..n]` 동안 순회하면서 다음을 반복한다.

* `i = (i + k) % j`

모든 반복을 마치면 `i + 1` 이 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
