# Problem

* [Smallest Rotation with Highest Score](https://leetcode.com/problems/smallest-rotation-with-highest-score/)

# Idea

수열 `V` 가 주어진다. 인덱스 `i` 에 대하여 `i >= V[i]` 인 경우 포인트가
하나씩 증가한다고 해보자. `V` 를 `K` 만큼 회전했을 때 포인트가 가장 크다면
그때의 `K` 를 구하는 문제이다.

`K` 회전했을 때 포인트의 합을 `sump[K]` 라고 하자. `sump[K] -
sump[K-1] = deltap[K]` 라고 하자. `deltap[K]` 를 구하면 `sump[K] =
sump[K-1] + deltap[K]` 이기 때문에 `sump[]` 를 구할 수 있고 가장
큰값의 인덱스를 리턴하면 된다.

`sump[], deltap[]` 에대해 중요한 규칙을 발견할 수 있다. `V = 2 3 1 4 0` 이라고 하자.

숫자 `2` 를 회전해 보자. 인덱스 `i = 1` 일 때 즉 `k = 4` 일 때
`sump[4] = sump[3] - 1` 이다.

숫자 `3` 을 회전해 보자. 인덱스 `i = 2` 일 때
즉 `k = 4` 일 때 `sump[4] = sump[3] - 1` 이다.

숫자 `1` 을 회전해 보자. 인덱스 `i = 0` 일 때
즉 `k = 2` 일 때 `sump[2] = sump[1] - 1` 이다.

숫자 `4` 을 회전해 보자. 어떠한 인덱스에서도 `sum[k] = sum[k-1] - 1` 인
`k` 는 없다.

숫자 `0` 을 회전해 보자. 어떠한 인덱스에서도 `sum[k] = sum[k-1] - 1`인
`k` 는 없다.

```
deltap[(i - V[i] + 1 + n) % n] -= 1

i:  0  1  2  3  4
V:  2  3  1  4  0
d:  0  0  0  0 -1
s:  
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
