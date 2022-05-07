# Problem

[Count Collisions on a Road](https://leetcode.com/problems/count-collisions-on-a-road/)

문자열 `dirs` 가 주어진다. `dirs` 는 `L, R, S` 로만 구성되어 있다.

`dirs.length` 만큼 자동차가 있다고 해보자. 각 자의 위치에서 i-th
자동차는 `dirs[i]` 의 방향으로 움직인다. `L, R, S` 는 각각 왼쪽,
우른쪽, 정지를 의미한다. 자동차가 충돌하면 충돌한 자동차는 `S` 가 되어
그 자리에 머문다. 

충돌 점수는 다음과 같이 계산한다.

* 움직이는 자동차끼리 충돌하면 `2` 점
* 하나의 자동차만 움직이는 상태라면 `1` 점

모든 자동차들의 충돌 점수를 구하라.

# Idea

예를 들어 `dirs = "RLRSLL"` 의 경우를 살펴보자.

```
R L R S L L
> < > | < <
1 1 1   1 1
```

따라서 답은 `5` 이다.

`dirs` 의 양끝에 인덱스 `l = 0, r = n - 1` 을 배치한다. `dirs[l] == L`
이면 충돌하지 않는다. `l++` 하자. 마찬가지로 `dirs[r] == R` 이면
충돌하지 않는다. `r++` 하자. 이제 `dirs[l], dirs[l+1]` 은 다음과 같이 
4 가지 경우가 있다.

```
dirs[l] dirs[l+1]
R L, 1 1
R S, 1 0
S L, 0 1
S S, 0 0
```

`l <= r` 동안 `l` 을 증가하면서 `dirs[l] != 'S'` 이면
충돌 횟수를 하나씩 증가한다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(1)
```
